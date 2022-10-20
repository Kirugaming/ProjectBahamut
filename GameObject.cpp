//
// Created by kirut on 10/17/2022.
//

#include "GameObject.h"



GameObject::GameObject(const std::string &imgSource, ShaderLoader* shader)
: sprite(imgSource, *shader) {}

void GameObject::draw() const {
    this->sprite.drawSprite();
}
