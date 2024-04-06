#pragma once

#include "vkl_window.hpp"
#include "vkl_pipeline.hpp"
#include "vkl_device.hpp"

namespace vkl 
{
    class FirstApp
    {
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            void run();

        private:
            VKL_Window vkl_Window{WIDTH,HEIGHT,"Hello Vulkan!"};
            VKL_Device vkl_Device{vkl_Window};
            VKL_Pipeline vkl_Pipeline{
                vkl_Device,
                "../shaders/simple_shader.vert.spv",
                "../shaders/simple_shader.frag.spv",
                VKL_Pipeline::defaultPipelineConfigInfo(WIDTH,HEIGHT)};
    };
    
}