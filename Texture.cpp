//
// Created by kirut on 9/12/2022.
//

#define STB_IMAGE_IMPLEMENTATION
#include "Texture.h"
#include "lib/glad.h"

Texture::Texture() : Texture("default.png") {
}
Texture::Texture(const char *imgSource) : imgSource(imgSource) {
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    // wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // use nearest for pixel art

    stbi_set_flip_vertically_on_load(true);

    int width, height, nrChannels;
    unsigned char* img = stbi_load(imgSource, &width, &height, &nrChannels, STBI_rgb_alpha);

    if (img == nullptr) {
        std::cout << "Image failed to load: " << stbi_failure_reason() << std::endl;
        return;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img);

    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(img);



    std::cout << "Image Loaded" << std::endl;
}

void Texture::bindTexture() const {
    glBindTexture(GL_TEXTURE_2D, this->textureId);
}

void Texture::unbindTexture() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::changeTexture(const char *imgSource) {
    int width, height, nrChannels;
    // load image into program
    unsigned char* img = stbi_load(imgSource, &width, &height, &nrChannels, STBI_rgb_alpha);
    if (img == nullptr) {
        std::cout << "Image failed to load: " << stbi_failure_reason() << std::endl;
        return;
    }
    // load the img into opengl
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img);
    glGenerateMipmap(GL_TEXTURE_2D); // mipmap is for viewing distance's

    this->imgSource = imgSource; // for comparison with a newer image in texture change


    stbi_image_free(img);
}

