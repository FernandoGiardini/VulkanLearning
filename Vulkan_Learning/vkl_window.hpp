#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace vkl 
{

    class VKL_Window 
    {
        public:
            VKL_Window(int w, int h,std::string name);
            ~VKL_Window();

            VKL_Window(const VKL_Window &) = delete;
            VKL_Window &operator=(const VKL_Window &) = delete;


            bool shouldClose() { return glfwWindowShouldClose(window);}

        private:

            void initWindow();

            const int width;
            const int height;

            std::string windowName;
            GLFWwindow *window;
    };
} //namespace VKL