//
// Created by kirut on 10/17/2022.
//

#include "GameObject.h"


GameObject::GameObject(const std::string &imgSource, ShaderLoader* shader, glm::mat4 transform)
: sprite(imgSource, *shader), transform(glm::translate(transform, glm::vec3(0,0,0))) {
    this->view = glm::translate(this->view, glm::vec3(0.0f, 0.0f, -3.0f));
    this->projection = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f);

    this->sprite.shaderLoader.editShaderWithMat4("transform", this->transform);
    this->sprite.shaderLoader.editShaderWithMat4("projection", this->projection);
    this->sprite.shaderLoader.editShaderWithMat4("view", this->view);
}

void GameObject::draw() const {
    glm::mat4 projectionRef = this->projection;
    glm::mat4 viewRef = this->view;
    this->sprite.shaderLoader.editShaderWithMat4("projection", projectionRef);
    this->sprite.shaderLoader.editShaderWithMat4("view", viewRef);

    this->sprite.drawSprite();


}


void GameObject::transformVector(glm::vec3 posChange) {
    this->transform = glm::translate(transform, posChange);
    this->sprite.shaderLoader.editShaderWithMat4("transform", transform);
}

void GameObject::rotate(float angle, glm::vec3 vector) {
    this->transform = glm::rotate(transform, angle, vector);
    this->sprite.shaderLoader.editShaderWithMat4("transform", transform);
}

void GameObject::scale(glm::vec3 scaleBy) {
    this->transform = glm::scale(transform, scaleBy);
    this->sprite.shaderLoader.editShaderWithMat4("transform", transform);
}

