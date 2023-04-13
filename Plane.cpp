//
// Created by kiru on 4/13/23.
//

#include "Plane.h"

Plane::Plane(std::string name, const std::string& imgSource, glm::mat4 transform) {
    // camera stuff
    this->view = glm::translate(this->view, glm::vec3(0.0f, 0.0f, -3.0f));
    this->projection = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f);

    // add how an object is viewed to the shaders
    this->sprite.shaderLoader.editShaderWithMat4("projection", this->projection);
    this->sprite.shaderLoader.editShaderWithMat4("view", this->view);
}

Plane::Plane() : Plane("default", "default.png", glm::mat4(1.0f)) {}

void Plane::draw() {
    const glm::mat4& projectionRef = this->projection;
    const glm::mat4& viewRef = this->view;

    this->sprite.texture->bindTexture();
    this->sprite.shaderLoader.useShader();




    // Check if texture model has changed before updating the sprite's texture
    if (this->textureModel != this->sprite.texture->imgSource) {
        std::cout << "Texture has changed\n";
        this->sprite.texture->changeTexture(this->textureModel);
    }

    this->sprite.shaderLoader.editShaderWithMat4("model", transform);
    this->sprite.shaderLoader.editShaderWithMat4("projection", const_cast<glm::mat4 &>(projectionRef));
    this->sprite.shaderLoader.editShaderWithMat4("view", const_cast<glm::mat4 &>(viewRef));

    // Draw the sprite using the updated shader uniforms
    this->sprite.drawSprite();
}
