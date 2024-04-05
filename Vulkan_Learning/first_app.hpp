#pragma once

#include "vkl_window.hpp"

namespace vkl 
{
    class FirstApp
    {
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            void run();

        private:
        VKL_Window vkl_Window_app_child{WIDTH,HEIGHT,"Hello Vulkan!"};
    };
    
}