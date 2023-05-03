//
// Created by kirut on 10/17/2022.
//

#include "SpriteRenderer.h"


void SpriteRenderer::drawSprite() const {

    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}

SpriteRenderer::SpriteRenderer(const std::string& imgSource, ShaderLoader sl) : shaderLoader(sl), texture(new umTexture(imgSource)) {
    float vertices[] = {
            // positions (x,y,z)                // umTexture coords (x,y)
            -1.0f,  -1.0f, 0.0f,    0.0f, 0.0f, // top right
            -1.0f, 1.0f, 0.0f,      0.0f, 1.0f, // bottom right
            1.0f, 1.0f, 0.0f,     1.0f, 1.0f, // bottom left
            1.0f,  -1.0f, 0.0f,   1.0f, 0.0f  // top left

    };

    unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
    };

    // VAO
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);

    // VBO
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    // bring square vertices into the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // EBO
    glGenBuffers(1, &elementBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindVertexArray(0);

}


// default constructor
SpriteRenderer::SpriteRenderer(const std::string& imgSource) : SpriteRenderer(imgSource, *new ShaderLoader()) {}
