//
// Created by kirut on 10/17/2022.
//

#include "GameObject.h"

#include <utility>

GameObject::GameObject(std::string name, Model model)
        : shaderLoader(), name(std::move(name)), textureModel("default.png") ,model(std::move(model)) {

    transform = Transform();

    // camera stuff
    this->view = glm::translate(this->view, glm::vec3(0.0f, 0.0f, -3.0f));
    this->projection = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f);

    // add how an object is viewed to the shaders
    this->shaderLoader.editShaderWithMat4("projection", this->projection);
    this->shaderLoader.editShaderWithMat4("view", this->view);




}
// default constructor
GameObject::GameObject() : GameObject("default", Model("default.obj")) {
}

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

    glm::mat4 transformMat4 = Transform::transformToMat4(this->transform);

    this->shaderLoader.editShaderWithMat4("model", transformMat4);

    // Draw the sprite using the updated shader uniforms
    this->model.Draw(shaderLoader);
    //this->sprite.drawSprite();
    glUseProgram(0);

}

void GameObject::translate(const glm::vec3 &offset) {
    transform.position += offset;
}

void GameObject::rotate(glm::vec3 angles) {
    transform.rotation *= glm::quat(glm::radians(angles));
}
void GameObject::scale(const glm::vec3 &scale) {
    transform.scale *= scale;
}

glm::vec3 GameObject::getPosition() const {
    return transform.position;
}

glm::quat GameObject::getRotation() const {
    return transform.rotation;
}

glm::vec3 GameObject::getScale() const {
    return transform.scale;
}

std::string GameObject::getClass() {
    return "GameObject";
}

