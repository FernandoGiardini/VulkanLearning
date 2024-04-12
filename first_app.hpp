#pragma once

#include "vkl_window.hpp"
#include "vkl_pipeline.hpp"
#include "vkl_device.hpp"
#include "vkl_swap_chain.hpp"

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
            void createPipelineLayout();
            void createPipeline();
            void createCommandBuffers();
            void drawFrame();

            VKL_Window vkl_Window{WIDTH,HEIGHT,"Hello Vulkan!"};
            VKL_Device vkl_Device{vkl_Window};
            VKL_SwapChain vkl_SwapChain{vkl_Device,vkl_Window.getExtent()};
            std::unique_ptr<VKL_Pipeline> vkl_Pipeline;
            VkPipelineLayout pipelineLayout;
            std::vector<VkCommandBuffer> commandBuffers;
    };
    
}