//
// Created by kirut on 9/12/2022.
//

#define STB_IMAGE_IMPLEMENTATION
#include "textureLoader.h"



void textureLoader::loadTexture() {
    int width, height, nrChannels;
    unsigned char* img = stbi_load("wall.jpg", &width, &height, &nrChannels, 0);
    if (img == nullptr) {
        std::cout << "Image failed to load: " << stbi_failure_reason() << std::endl;
        return;
    }
    stbi_image_free(img);

    std::cout << "Image Loaded" << std::endl;

    
}