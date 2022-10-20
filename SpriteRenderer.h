//
// Created by kirut on 10/17/2022.
//

#ifndef PROJECTBAHAMUT_SPRITERENDERER_H
#define PROJECTBAHAMUT_SPRITERENDERER_H


#include "ShaderLoader.h"
#include "Texture.h"
#include <glm/glm.hpp>

class SpriteRenderer {
public:

    SpriteRenderer(const std::string &imgSource, ShaderLoader sl);

    Texture texture;

    ShaderLoader shaderLoader;
    unsigned int vertexBuffer{}, vertexArray{}, elementBuffer{};



    void drawSprite() const;


};


#endif //PROJECTBAHAMUT_SPRITERENDERER_H
