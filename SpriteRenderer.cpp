//
// Created by kirut on 10/17/2022.
//

#include "SpriteRenderer.h"


void SpriteRenderer::drawSprite() const {
    texture.bindTexture();
    shaderLoader.useShader();

    glBindVertexArray(vertexArray);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

SpriteRenderer::SpriteRenderer(const std::string &imgSource, ShaderLoader sl) : shaderLoader(sl), texture(imgSource) {
    float vertices[] = {
            // positions                         // Texture coords
            -1.0f,  -1.0f, 0.0f,    0.0f, 0.0f, // top right
            -1.0f, 1.0f, 0.0f,      0.0f, 1.0f, // bottom right
            1.0f, 1.0f, 0.0f,     1.0f, 1.0f, // bottom left
            1.0f,  -1.0f, 0.0f,   1.0f, 0.0f  // top left

    };

    unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
    };

    glGenVertexArrays(1, &vertexArray);
    glGenBuffers(1, &vertexBuffer);
    glBindVertexArray(vertexArray);
    glGenBuffers(1, &elementBuffer);
    // bring square vertices into the buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) nullptr);
    glEnableVertexAttribArray(0);
    // Texture coord
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);





}