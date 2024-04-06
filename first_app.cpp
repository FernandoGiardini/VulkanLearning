#include "first_app.hpp"

namespace vkl{

    void FirstApp::run() {
        while (!vkl_Window.shouldClose())
        {
            glfwPollEvents();
        }
        
    }
}