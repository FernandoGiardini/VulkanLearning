#include "vkl_window.hpp"
#include <stdexcept>

namespace vkl {

    VKL_Window::VKL_Window(int w,int h,std::string name) : width{w}, height{h}, windowName{name} 
    {
        initWindow();
    }

    VKL_Window::~VKL_Window()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void VKL_Window::initWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        window = glfwCreateWindow(width,height,windowName.c_str(),nullptr,nullptr);
        glfwSetWindowUserPointer(window,this);
        glfwSetFramebufferSizeCallback(window,frameBufferResizeCallback);
    }

    void VKL_Window::createWindowSurface(VkInstance instance,VkSurfaceKHR* surface)
    {
        if (glfwCreateWindowSurface(instance,window,nullptr,surface) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create window surface");
        }
        
    }

    void VKL_Window::frameBufferResizeCallback(GLFWwindow *window,int width,int heigth)
    {
        auto vklWindow = reinterpret_cast<VKL_Window *>(glfwGetWindowUserPointer(window));
        vklWindow->frameBufferResized = true;
        vklWindow->width = width;
        vklWindow->height = heigth;
    }
}