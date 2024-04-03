cmake_minimum_required(VERSION 3.1)

project(VKLearn)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Setting C++ Vulkan prerequisites
set(CMAKE_CXX_FLAGS "-std=c++17 -O2")

# Find GLFW
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})

#Fetching all executables
file(GLOB SOURCES "*.cpp" "*.hpp")
add_executable(VKLearn ${SOURCES})

# Link against GLFW
target_link_libraries(VKLearn glfw ${OPENGL_LIBRARIES} vulkan dl pthread X11 Xxf86vm Xrandr Xi)

# Custom commands
add_custom_target(test
    COMMAND VKLearn
    DEPENDS VKLearn
    COMMENT "Running VulkanTest"
)

add_custom_target(remove
    COMMAND ${CMAKE_COMMAND} -E remove VKLearn
    COMMENT "Cleaning project"
)