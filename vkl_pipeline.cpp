#include "vkl_pipeline.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>

namespace vkl {

    VKL_Pipeline::VKL_Pipeline(
                VKL_Device& device,
                const std::string& vertFilepath,
                const std::string& fragFilepath,
                const PipelineConfigInfo& configInfo) : vklDevice{device} {
        createGraphicsPipeline(vertFilepath,fragFilepath,configInfo);
    }


    std::vector<char> VKL_Pipeline::readFile(const std::string& filepath) {
        
        std::ifstream file{filepath, std::ios::ate | std::ios::binary};

        if (!file.is_open())
        {
            throw std::runtime_error("failed to open file "+ filepath);
        }
            
        size_t filesize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(filesize);

        file.seekg(0);
        file.read(buffer.data(),filesize);

        file.close();
        return buffer;
    };

    void VKL_Pipeline::createGraphicsPipeline(
        const std::string& vertFilepath,
        const std::string& fragFilepath,
        const PipelineConfigInfo& configInfo) {

            auto vertCode = readFile(vertFilepath);
            auto fragCode = readFile(fragFilepath);

            std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
            std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
        }

    void VKL_Pipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule){
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

        if (vkCreateShaderModule(vklDevice.device(), &createInfo,nullptr,shaderModule) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create shader module");
        }     
    }

    PipelineConfigInfo VKL_Pipeline::defaultPipelineConfigInfo(uint32_t width,uint32_t height){
        PipelineConfigInfo configInfo{};

        return configInfo;
    }
}