#pragma once

#include "vkl_device.hpp"

#include <string>
#include <vector>

namespace vkl {

    struct PipelineConfigInfo {};
    class VKL_Pipeline {
        public:
            VKL_Pipeline(
                VKL_Device& device,
                const std::string& vertFilepath,
                const std::string& fragFilepath,
                const PipelineConfigInfo& configInfo);
            ~VKL_Pipeline(){};    

            //RAII
            VKL_Pipeline(const VKL_Pipeline&) = delete;
            void operator=(const VKL_Pipeline&) = delete;

            //default config
            static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width,uint32_t height);

        private:
            static std::vector<char> readFile(const std::string& filepath);

        void createGraphicsPipeline(
            const std::string& vertFilepath,
            const std::string& fragFilepath,
            const PipelineConfigInfo& configInfo);   

        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

        VKL_Device& vklDevice;     
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;

    };
    
}