//
// Created by kirut on 9/12/2022.
//

#ifndef PROJECTBAHAMUT_UMTEXTURE_H
#define PROJECTBAHAMUT_UMTEXTURE_H

#include <iostream>
#include <stb_image.h>


class umTexture{
public:

    umTexture();


    umTexture(const std::string& imgSource);

    std::string imgSource;

    unsigned int textureId{};

    void bindTexture() const;
    void unbindTexture() const;


    void changeTexture(const std::string& filename);
};


#endif //PROJECTBAHAMUT_UMTEXTURE_H
