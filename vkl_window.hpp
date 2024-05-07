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
            VkExtent2D getExtent() {return {static_cast<uint32_t>(width),static_cast<uint32_t>(height)};}
            bool wasWindowResized() {return frameBufferResized;}
            void resetWindowResizedFlag() { frameBufferResized = false;}
            
            void createWindowSurface(VkInstance instance,VkSurfaceKHR* surface);
        private:
            static void frameBufferResizeCallback(GLFWwindow *window,int width,int heigth);
            void initWindow();

            int width;
            int height;
            bool frameBufferResized = false;

            std::string windowName;
            GLFWwindow *window;
    };
} //namespace VKL