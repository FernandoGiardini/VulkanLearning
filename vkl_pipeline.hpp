#pragma once

#include "vkl_device.hpp"

#include <string>
#include <vector>

namespace vkl {

struct PipelineConfigInfo {
    PipelineConfigInfo(const PipelineConfigInfo&) = delete;
    PipelineConfigInfo& operator=(const PipelineConfigInfo&) = delete;

    VkPipelineViewportStateCreateInfo viewportInfo;
    VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
    VkPipelineRasterizationStateCreateInfo rasterizationInfo;
    VkPipelineMultisampleStateCreateInfo multisampleInfo;
    VkPipelineColorBlendAttachmentState colorBlendAttachment;
    VkPipelineColorBlendStateCreateInfo colorBlendInfo;
    VkPipelineDepthStencilStateCreateInfo depthStencilInfo;

    std::vector<VkDynamicState> dynamicStateEnables;
    VkPipelineDynamicStateCreateInfo dynamicStateInfo;
    VkPipelineLayout pipelineLayout = nullptr;
    VkRenderPass renderPass = nullptr;
    uint32_t subpass = 0;
    };

    class VKL_Pipeline {
        public:
            VKL_Pipeline(
                VKL_Device& device,
                const std::string& vertFilepath,
                const std::string& fragFilepath,
                const PipelineConfigInfo& configInfo);
            ~VKL_Pipeline();    

            //RAII
            VKL_Pipeline(const VKL_Pipeline&) = delete;
            VKL_Pipeline& operator=(const VKL_Pipeline&) = delete;

            //default config
            static void defaultPipelineConfigInfo(PipelineConfigInfo &configInfo);

            //bind commandbuffer to pípeline
            void bind(VkCommandBuffer commandBuffer);

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