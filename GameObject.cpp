//
// Created by kirut on 10/17/2022.
//

#include "GameObject.h"

#include <utility>

GameObject::GameObject(std::string name, glm::mat4 transform, Model model)
        : shaderLoader(), transform(transform), name(std::move(name)), textureModel("default.png") ,model(std::move(model)) {

    // camera stuff
    this->view = glm::translate(this->view, glm::vec3(0.0f, 0.0f, -3.0f));
    this->projection = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f);

    // add how an object is viewed to the shaders
    this->shaderLoader.editShaderWithMat4("projection", this->projection);
    this->shaderLoader.editShaderWithMat4("view", this->view);




}
// default constructor
/*
GameObject::GameObject() : GameObject("default", "default.png", glm::mat4(1.0f)) {
}
*/

void GameObject::draw() {






    // Check if texture model has changed before updating the sprite's texture
    /* TODO: this would be change model for a 3D Game Objects
    if (this->textureModel != this->sprite.texture->imgSource) {
        std::cout << "umTexture has changed\n";
        this->sprite.texture->changeTexture(this->textureModel);
    }
     */
    glUseProgram(shaderLoader.shaderProgramID);

    this->shaderLoader.editShaderWithMat4("projection", this->projection);
    this->shaderLoader.editShaderWithMat4("view", this->view);
    this->shaderLoader.editShaderWithMat4("model", transform);

    // Draw the sprite using the updated shader uniforms
    this->model.Draw(shaderLoader);
    //this->sprite.drawSprite();
    glUseProgram(0);

}

void GameObject::translate(const glm::vec3 &offset) {
    transform = glm::translate(transform, offset);
}

void GameObject::rotate(float angle, glm::vec3 axis) {
    transform = glm::rotate(transform, glm::radians(angle), axis);
}

void GameObject::rotateXYZ(glm::vec3 eulerAngles) {
    glm::mat4 rotationMatrix(1.0f);
    rotationMatrix = glm::rotate(rotationMatrix, glm::radians(eulerAngles.x), glm::vec3(1, 0, 0));
    rotationMatrix = glm::rotate(rotationMatrix, glm::radians(eulerAngles.y), glm::vec3(0, 1, 0));
    rotationMatrix = glm::rotate(rotationMatrix, glm::radians(eulerAngles.z), glm::vec3(0, 0, 1));
    transform = transform * rotationMatrix;
}

void GameObject::scale(const glm::vec3 &scale) {
    // it is possible to divide by zero (BAD) so uh dont do that
    if (scale.x == 0.0f || scale.y == 0.0f || scale.z == 0.0f) {
        std::cerr << "Scale vector cannot contain 0 values." << std::endl;
        return; // need better way of doing this
    }
    transform = glm::scale(transform, scale / getScale());
}

glm::vec3 GameObject::getPosition() {
    return {transform[3][0], transform[3][1], transform[3][2]};
}

glm::vec3 GameObject::getRotation() const {
    return glm::eulerAngles(glm::quat_cast(transform));
}

glm::vec3 GameObject::getScale() {
    return {
            glm::length(glm::vec3(transform[0][0], transform[0][1], transform[0][2])),
            glm::length(glm::vec3(transform[1][0], transform[1][1], transform[1][2])),
            glm::length(glm::vec3(transform[2][0], transform[2][1], transform[2][2]))
    };
}

