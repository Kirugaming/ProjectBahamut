//
// Created by kirut on 10/17/2022.
//

#ifndef PROJECTBAHAMUT_SPRITERENDERER_H
#define PROJECTBAHAMUT_SPRITERENDERER_H


#include <glad/glad.h>
#include "umTexture.h"
#include "ShaderLoader.h"
#include <GLFW/glfw3.h>
#include <string>

class SpriteRenderer {
public:



    SpriteRenderer(GLfloat *vertices, unsigned int *indices, unsigned int sizeOfVertices, unsigned int sizeOfIndices);

    SpriteRenderer(const std::string &imgSource, ShaderLoader sl);

    explicit SpriteRenderer(const std::string& imgSource);

    umTexture *texture;

    ShaderLoader shaderLoader;
    unsigned int vertexBuffer{}, vertexArray{}, elementBuffer{};


    void changeSprite(std::string &imgSource);


    void drawSprite() const;
private:



};


#endif //PROJECTBAHAMUT_SPRITERENDERER_H
