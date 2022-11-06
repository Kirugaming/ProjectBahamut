//
// Created by kirut on 9/12/2022.
//

#ifndef PROJECTBAHAMUT_TEXTURE_H
#define PROJECTBAHAMUT_TEXTURE_H

#include <iostream>
#include "lib/stb_image.h"
#include "lib/glad.h"


class Texture{
public:


    explicit Texture(const std::string &imgSource);

    unsigned int aTexture{};

    void bindTexture() const;

};


#endif //PROJECTBAHAMUT_TEXTURE_H
