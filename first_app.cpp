#include "first_app.hpp"

//std
#include <stdexcept>
namespace vkl{

    
    FirstApp::FirstApp(){
        createPipelineLayout();
        createPipeline();
        createCommandBuffers();
    }

    FirstApp::~FirstApp(){
        vkDestroyPipelineLayout(vkl_Device.device(),pipelineLayout,nullptr);
    }

    void FirstApp::run() {
        while (!vkl_Window.shouldClose()){
            glfwPollEvents();
        }
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
        auto pipelineConfig = VKL_Pipeline::defaultPipelineConfigInfo(vkl_SwapChain.width(),vkl_SwapChain.height());
        pipelineConfig.renderPass = vkl_SwapChain.getRenderPass();
        pipelineConfig.pipelineLayout = pipelineLayout;
        vkl_Pipeline = std::make_unique<VKL_Pipeline>(
            vkl_Device,
            "../shaders/simple_shader.vert.spv",
            "../shaders/simple_shader.frag.spv",
            pipelineConfig
        );
    }

    void FirstApp::createCommandBuffers(){};

    void FirstApp::drawFrame(){};
}