//
// Created by kirut on 9/12/2022.
//

#ifndef PROJECTBAHAMUT_TEXTURE_H
#define PROJECTBAHAMUT_TEXTURE_H

#include <iostream>
#include <stb_image.h>


class Texture{
public:

    Texture();


    Texture(const std::string& imgSource);

    std::string imgSource;

    unsigned int textureId{};

    void bindTexture() const;
    void unbindTexture() const;


    void changeTexture(const std::string& filename);
};


#endif //PROJECTBAHAMUT_TEXTURE_H
