//
// Created by kirut on 10/17/2022.
//

#include "GameObject.h"

#include <utility>

GameObject::GameObject(const char* name, const char* imgSource, glm::mat4 transform)
        : sprite(imgSource), transform(glm::translate(transform, glm::vec3(0, 0, 0))), position(new float[3]), rotation(new float[3]), scale(new float[3]), name(), textureModel() {
    // TODO: need to find  a better way to do these 2 strings
    this->name = new char[strlen(name) + 1];  // idk what this is doing
    strcpy(this->name, name);
    this->textureModel = new char[strlen(imgSource) + 1];
    strcpy(this->textureModel, imgSource);

    // camera stuff
    this->view = glm::translate(this->view, glm::vec3(0.0f, 0.0f, -3.0f));
    this->projection = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f);

    // add how an object is viewed to the shader
    this->sprite.shaderLoader.editShaderWithMat4("transform", this->transform);
    this->sprite.shaderLoader.editShaderWithMat4("projection", this->projection);
    this->sprite.shaderLoader.editShaderWithMat4("view", this->view);


    // get position from transform matrix
    this->position[0] = this->transform[3][0];
    this->position[1] = this->transform[3][1];
    this->position[2] = this->transform[3][2];
    // get rotation from transform matrix
    this->rotation[0] = this->transform[0][0];
    this->rotation[1] = this->transform[1][1];
    this->rotation[2] = this->transform[2][2];
    // get scale from transform matrix
    this->scale[0] = this->transform[0][0];
    this->scale[1] = this->transform[1][1];
    this->scale[2] = this->transform[2][2];

}

GameObject::GameObject() : sprite("sillycat.jpg"), transform(glm::mat4(1.0f)), position(new float[3]), rotation(new float[3]), scale(new float[3]), name(), textureModel() {
    this->name = new char[strlen("default") + 1];
    strcpy(this->name, "default");
    this->textureModel = new char[strlen("sillycat.jpg") + 1];
    strcpy(this->textureModel, "sillycat.jpg");


    this->view = glm::translate(this->view, glm::vec3(0.0f, 0.0f, -3.0f));
    this->projection = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f);

    this->sprite.shaderLoader.editShaderWithMat4("transform", this->transform);
    this->sprite.shaderLoader.editShaderWithMat4("projection", this->projection);
    this->sprite.shaderLoader.editShaderWithMat4("view", this->view);

    // get position from transform matrix
    this->position[0] = this->transform[3][0];
    this->position[1] = this->transform[3][1];
    this->position[2] = this->transform[3][2];
    // get rotation from transform matrix
    this->rotation[0] = this->transform[0][0];
    this->rotation[1] = this->transform[1][1];
    this->rotation[2] = this->transform[2][2];
    // get scale from transform matrix
    this->scale[0] = this->transform[0][0];
    this->scale[1] = this->transform[1][1];
    this->scale[2] = this->transform[2][2];

}


void GameObject::draw() {
    glm::mat4 projectionRef = this->projection;
    glm::mat4 viewRef = this->view;

    // check if texture model is changed
    // TODO: Fix so its not called every frame
        this->sprite.texture->changeTexture(this->textureModel);


    // these methods apply rotation, position, and scale to update shader
    // turn position into a transform mat4
    glm::mat4 transformRef = glm::translate(glm::mat4(1.0f), glm::vec3(this->position[0], this->position[1], this->position[2]));
    // turn rotation into a transform mat4
    transformRef = glm::rotate(transformRef, glm::radians(this->rotation[0]), glm::vec3(1.0f, 0.0f, 0.0f));
    transformRef = glm::rotate(transformRef, glm::radians(this->rotation[1]), glm::vec3(0.0f, 1.0f, 0.0f));
    transformRef = glm::rotate(transformRef, glm::radians(this->rotation[2]), glm::vec3(0.0f, 0.0f, 1.0f));
    // turn scale into a transform mat4
    transformRef = glm::scale(transformRef, glm::vec3(this->scale[0], this->scale[1], this->scale[2]));

    // update shader with new transform
    this->sprite.shaderLoader.editShaderWithMat4("transform", transformRef); // TODO: maybe make the shader accept vec3 or translate into mat4 every draw call
    this->sprite.shaderLoader.editShaderWithMat4("projection", projectionRef);
    this->sprite.shaderLoader.editShaderWithMat4("view", viewRef);

    this->sprite.drawSprite();


}


void GameObject::transformVector(glm::vec3 posChange) {
    this->transform = glm::translate(transform, posChange);

    this->position[0] = this->transform[3][0];
    this->position[1] = this->transform[3][1];
    this->position[2] = this->transform[3][2];

    this->sprite.shaderLoader.editShaderWithMat4("transform", transform);

}
/*
void GameObject::rotate(float angle, glm::vec3 vector) {
    this->transform = glm::rotate(transform, angle, vector);
    this->sprite.shaderLoader.editShaderWithMat4("transform", transform);
}

bool GameObject::nameEmpty() {
    if (this->name == nullptr) {
        return true;
    }
    return false;
}

void GameObject::scale(glm::vec3 scaleBy) {
    this->transform = glm::scale(transform, scaleBy);
    this->sprite.shaderLoader.editShaderWithMat4("transform", transform);
}
*/



