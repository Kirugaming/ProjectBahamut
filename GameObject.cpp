//
// Created by kirut on 10/17/2022.
//

#include "GameObject.h"


GameObject::GameObject(const std::string &imgSource, ShaderLoader* shader, glm::mat4 transform)
: sprite(imgSource, *shader), transform(glm::translate(transform, glm::vec3(0,0,0))) {
    this->sprite.shaderLoader.editShaderWithMat4("transform", this->transform);
}

void GameObject::draw() const {
    //this->sprite.shaderLoader.editShaderWithMat4("transform", this->transform);
    this->sprite.drawSprite();
}

void GameObject::transformVector(glm::vec3 posChange) {
    this->transform = glm::translate(transform, posChange);
    this->sprite.shaderLoader.editShaderWithMat4("transform", transform);
}

void GameObject::rotate(float angle) {
    this->transform = glm::rotate(transform, angle, glm::vec3(0.0f, 0.0f, 1.0f));
    this->sprite.shaderLoader.editShaderWithMat4("transform", transform);
}

void GameObject::scale(glm::vec3 scaleBy) {
    this->transform = glm::scale(transform, scaleBy);
    this->sprite.shaderLoader.editShaderWithMat4("transform", transform);
}
