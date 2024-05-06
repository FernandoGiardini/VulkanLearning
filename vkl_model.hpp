#pragma once

#include "vkl_device.hpp"

//libs
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
//std
#include <vector>

namespace vkl
{
    class VKL_Model
    {
    public:

        struct Vertex {
            glm::vec2 position;
            glm::vec3 color;

            static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
            static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
        };

        VKL_Model(VKL_Device &device,const std::vector<Vertex> &vertices);
        ~VKL_Model();

        VKL_Model(const VKL_Model &)= delete;
        VKL_Model &operator=(const VKL_Model &)=delete;

        void bind(VkCommandBuffer commandBuffer);
        void draw(VkCommandBuffer commandBuffer);
    private:
        void createVertexBuffers(const std::vector<Vertex> &vertices);

        VKL_Device& vkl_device;
        VkBuffer vertexBuffer;
        VkDeviceMemory vertexBufferMemory;
        uint32_t vertexCount;
    };
    
    
} // namespace vkl
