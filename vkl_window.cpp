#include "vkl_window.hpp"

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
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width,height,windowName.c_str(),nullptr,nullptr);
    }
}