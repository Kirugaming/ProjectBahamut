//
// Created by kirut on 10/26/2022.
//

#include "Player.h"

Player::Player(const std::string &imgSource, ShaderLoader *shader, glm::mat4 transform) : GameObject(imgSource, shader, transform) {
    this->scale(glm::vec3(.5f, .5f, .5f));
    this->transformVector(glm::vec3(0.0f, 0.0f, -4.0f));
}

void Player::draw() {
    GameObject::rotate(.1f);
    GameObject::draw();
}

void Player::editProjection(glm::mat4 value) {
    this->projection = value;
}
void Player::editView(glm::mat4 value) {
    this->view = value;
}
