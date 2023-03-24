//
// Created by kirut on 10/17/2022.
//

#ifndef PROJECTBAHAMUT_SPRITERENDERER_H
#define PROJECTBAHAMUT_SPRITERENDERER_H


#include <glad/glad.h>
#include "Texture.h"
#include "ShaderLoader.h"
#include <GLFW/glfw3.h>
#include <string>

class SpriteRenderer {
public:

    SpriteRenderer();

    explicit SpriteRenderer(std::string& imgSource);

    SpriteRenderer(std::string& imgSource, ShaderLoader sl);

    SpriteRenderer(const char *imgSource);

    SpriteRenderer(const char *imgSource, ShaderLoader sl);

    Texture *texture;

    ShaderLoader shaderLoader;
    unsigned int vertexBuffer{}, vertexArray{}, elementBuffer{};


    void changeSprite(std::string &imgSource);

    void drawSprite() const;


    void changeSprite(const char *imgSource);
};


#endif //PROJECTBAHAMUT_SPRITERENDERER_H
