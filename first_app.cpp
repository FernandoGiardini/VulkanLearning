#include "first_app.hpp"

//std
#include <stdexcept>
#include <array>
#include <cassert>
namespace vkl{

    
    FirstApp::FirstApp(){
        loadModels();
        createPipelineLayout();
        recreateSwapChain();
        createCommandBuffers();
    }

    FirstApp::~FirstApp(){
        vkDestroyPipelineLayout(vkl_Device.device(),pipelineLayout,nullptr);
    }

    void FirstApp::run() {
        while (!vkl_Window.shouldClose()){
            glfwPollEvents();
            drawFrame();
        }
        vkDeviceWaitIdle(vkl_Device.device());
    }

    void FirstApp::loadModels(){
        std::vector<VKL_Model::Vertex> vertices {//inicializa o vector
            {{0.0f,-0.5f},{1.0f,0.0f,0.0f}},//inicializa o vertex de cada modelo e depois o atributo posição [location 0] (glm vec2) do vertex e por ultimo o atributo cor [location 1](glm vec3)
             {{0.5f,0.5f},{0.0f,1.0f,0.0f}},
             {{-0.5f,0.5f},{0.0f,0.0f,1.0f}}
        };

        vkl_Model = std::make_unique<VKL_Model>(vkl_Device,vertices);
    }

    void FirstApp::createPipelineLayout() {
        VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount =0;
        pipelineLayoutInfo.pSetLayouts = nullptr;
        pipelineLayoutInfo.pushConstantRangeCount = 0;
        pipelineLayoutInfo.pPushConstantRanges = nullptr;
        if (vkCreatePipelineLayout(vkl_Device.device(),&pipelineLayoutInfo,nullptr,&pipelineLayout) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create pipeline layout!");
        }
        
    }

    void FirstApp::createPipeline() {
        assert(vkl_SwapChain != nullptr && "Cannot create pipeline before swapchain!");
        assert(pipelineLayout != nullptr && "Cannot create pipeline before pipeline layout!");

        PipelineConfigInfo pipelineConfig{};
        VKL_Pipeline::defaultPipelineConfigInfo(pipelineConfig);
        pipelineConfig.renderPass = vkl_SwapChain->getRenderPass();
        pipelineConfig.pipelineLayout = pipelineLayout;
        vkl_Pipeline = std::make_unique<VKL_Pipeline>(
            vkl_Device,
            "../shaders/simple_shader.vert.spv",
            "../shaders/simple_shader.frag.spv",
            pipelineConfig
        );
    }

    void FirstApp::recreateSwapChain(){
        auto extent = vkl_Window.getExtent();
        while (extent.width == 0 || extent.height == 0)
        {
            extent = vkl_Window.getExtent();
            glfwWaitEvents();
        }
        vkDeviceWaitIdle(vkl_Device.device());

        if (vkl_SwapChain == nullptr)
        {
            vkl_SwapChain = std::make_unique<VKL_SwapChain>(vkl_Device,extent);
        } else{
            vkl_SwapChain = std::make_unique<VKL_SwapChain>(vkl_Device,extent,std::move(vkl_SwapChain));
            if (vkl_SwapChain->imageCount() != commandBuffers.size())
            {
                freeCommandBuffers();
                createCommandBuffers();
            }
            
        }
        
        createPipeline();
    }

    void FirstApp::createCommandBuffers(){
        commandBuffers.resize(vkl_SwapChain->imageCount());

        VkCommandBufferAllocateInfo allocInfo{};

        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandPool = vkl_Device.getCommandPool();
        allocInfo.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());

        if (vkAllocateCommandBuffers(vkl_Device.device(),&allocInfo,commandBuffers.data()) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to allocate command buffers!");
        }

     
    };

    void FirstApp::freeCommandBuffers(){
        vkFreeCommandBuffers(
            vkl_Device.device(),
            vkl_Device.getCommandPool(),
            static_cast<uint32_t>(commandBuffers.size()),
            commandBuffers.data());

        commandBuffers.clear();
    }

    void FirstApp::recordCommandBuffer(int imageIndex){
        VkCommandBufferBeginInfo beginInfo{};
            beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

            if (vkBeginCommandBuffer(commandBuffers[imageIndex],&beginInfo) != VK_SUCCESS)
            {
                throw std::runtime_error("failed to begin recording command buffer!");
            }
            
            
            VkRenderPassBeginInfo renderPassInfo{};
            renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
            renderPassInfo.renderPass = vkl_SwapChain->getRenderPass();
            renderPassInfo.framebuffer = vkl_SwapChain->getFrameBuffer(imageIndex);

            renderPassInfo.renderArea.offset = {0,0};
            renderPassInfo.renderArea.extent = vkl_SwapChain->getSwapChainExtent();

            std::array<VkClearValue,2> clearValues{};
            clearValues[0].color = {0.1f,0.1f,0.1f,1.0f};
            clearValues[1].depthStencil = {1.0f, static_cast<uint32_t>(0.0f)}; //conferir static cast dps
            renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
            renderPassInfo.pClearValues = clearValues.data();

            vkCmdBeginRenderPass(commandBuffers[imageIndex],&renderPassInfo,VK_SUBPASS_CONTENTS_INLINE);

            VkViewport viewport{};
            viewport.x = 0.0f;
            viewport.y = 0.0f;
            viewport.width = static_cast<float>(vkl_SwapChain->getSwapChainExtent().width);
            viewport.height = static_cast<float>(vkl_SwapChain->getSwapChainExtent().height);
            viewport.minDepth = 0.0f;
            viewport.maxDepth = 1.0f;
            VkRect2D scissor{{0,0},vkl_SwapChain->getSwapChainExtent()};//mlk menor ideia do que e como isso esta fazendo.
            vkCmdSetViewport(commandBuffers[imageIndex],0,1,&viewport);
            vkCmdSetScissor(commandBuffers[imageIndex],0,1,&scissor);

            vkl_Pipeline->bind(commandBuffers[imageIndex]);
            vkl_Model->bind(commandBuffers[imageIndex]);
            vkl_Model->draw(commandBuffers[imageIndex]);

            vkCmdEndRenderPass(commandBuffers[imageIndex]);
            if(vkEndCommandBuffer(commandBuffers[imageIndex]) != VK_SUCCESS)
            {
                throw std::runtime_error("failed to record command buffer!");
            }
    }

    void FirstApp::drawFrame(){
        uint32_t imageIndex;
        auto result = vkl_SwapChain->acquireNextImage(&imageIndex);

        if (result == VK_ERROR_OUT_OF_DATE_KHR)
        {
            recreateSwapChain();
            return;
        }
        
        if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)
        {
            throw std::runtime_error("failed to acquire swapchain image!");
        }
        
        recordCommandBuffer(imageIndex);
        result = vkl_SwapChain->submitCommandBuffers(&commandBuffers[imageIndex],&imageIndex);
        if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR || vkl_Window.wasWindowResized())
        {
            vkl_Window.resetWindowResizedFlag();
            recreateSwapChain();
            return;
        }

        if (result != VK_SUCCESS)
        {
            throw std::runtime_error("failed to present swapchain image!");
        }
    }
}