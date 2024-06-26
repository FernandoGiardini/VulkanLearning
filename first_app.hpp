#pragma once

#include "vkl_window.hpp"
#include "vkl_pipeline.hpp"
#include "vkl_device.hpp"
#include "vkl_swap_chain.hpp"
#include "vkl_model.hpp"

//std
#include <memory>
#include <vector>


namespace vkl 
{
    class FirstApp
    {
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            FirstApp();
            ~FirstApp();

            FirstApp(const FirstApp &)= delete;
            FirstApp &operator=(const FirstApp &)=delete;

            void run();

        private:
            void loadModels();
            void createPipelineLayout();
            void createPipeline();
            void createCommandBuffers();
            void freeCommandBuffers();
            void drawFrame();
            void recreateSwapChain();
            void recordCommandBuffer(int imageIndex);

            VKL_Window vkl_Window{WIDTH,HEIGHT,"Hello Vulkan!"};
            VKL_Device vkl_Device{vkl_Window};
            std::unique_ptr<VKL_SwapChain> vkl_SwapChain;
            std::unique_ptr<VKL_Pipeline> vkl_Pipeline;
            VkPipelineLayout pipelineLayout;
            std::vector<VkCommandBuffer> commandBuffers;
            std::unique_ptr<VKL_Model> vkl_Model;
    };
    
}