//
// Created by kirut on 10/26/2022.
//

#include "Player.h"


Player::Player(const char* imgSource, glm::mat4 transform) : GameObject("player", imgSource, transform) {
    //this->scale(glm::vec3(.5f, .5f, .5f));
    this->transformVector(glm::vec3(0.0f, -0.9f, 0.0f));
}

void Player::draw() {
    GameObject::draw();
}

void Player::controls() {

}

void Player::editProjection(glm::mat4 value) {
    this->projection = value;
}
void Player::editView(glm::mat4 value) {
    this->view = value;
}



