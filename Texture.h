//
// Created by kirut on 9/12/2022.
//

#ifndef PROJECTBAHAMUT_TEXTURE_H
#define PROJECTBAHAMUT_TEXTURE_H

#include <iostream>
#include "stb_image.h"
#include "glad/glad.h"


class Texture{
public:


    explicit Texture(const std::string &imgSource);

    unsigned int aTexture{};

};


#endif //PROJECTBAHAMUT_TEXTURE_H
