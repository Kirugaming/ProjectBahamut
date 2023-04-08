//
// Created by kirut on 4/6/2023.
//

#include "Terrain.h"

#include <utility>

Terrain::Terrain(std::string name, const char* imgSource) : GameObject(std::move(name), imgSource, glm::mat4(1.0f)) {
    this->rotate(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
}