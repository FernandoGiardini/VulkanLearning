#include "vkl_pipeline.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>

namespace vkl {

    VklPipeline::VklPipeline(const std::string& vertFilepath,const std::string& fragFilepath){
        createGraphicsPipeline(vertFilepath,fragFilepath);
    }


    std::vector<char> VklPipeline::readFile(const std::string& filepath) {
        
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

    void VklPipeline::createGraphicsPipeline(
        const std::string& vertFilepath,
        const std::string& fragFilepath) {

            auto vertCode = readFile(vertFilepath);
            auto fragCode = readFile(fragFilepath);

            std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
            std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
        }

}