//
// Created by kirut on 9/12/2022.
//

#ifndef PROJECTBAHAMUT_TEXTURE_H
#define PROJECTBAHAMUT_TEXTURE_H

#include <iostream>
#include "lib/stb_image.h"


class Texture{
public:

    Texture();
    explicit Texture(const char *imgSource);


    const char *imgSource;

    unsigned int textureId{};

    void bindTexture() const;
    void unbindTexture() const;

    void changeTexture(const char *imgSource);

};


#endif //PROJECTBAHAMUT_TEXTURE_H
