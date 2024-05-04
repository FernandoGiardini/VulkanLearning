#pragma once

#include "vkl_device.hpp"

namespace vkl
{
    class VKL_Model
    {
    public:
        VKL_Model();
        ~VKL_Model();

        VKL_Model(const VKL_Model &)= delete;
        VKL_Model &operator=(const VKL_Model &)=delete;

    private:
        VKL_Device& vkl_device;
        VkBuffer vertexBuffer;
        VkDeviceMemory vertexBufferMemory;
        uint32_t vertexCount;

    };
    
    
} // namespace vkl
