//
// Created by kirut on 10/17/2022.
//

#ifndef PROJECTBAHAMUT_GAMEOBJECT_H
#define PROJECTBAHAMUT_GAMEOBJECT_H


#include "SpriteRenderer.h"
#include "Texture.h"

class GameObject {
public:

    GameObject(const std::string &imgSource, ShaderLoader *shader, glm::mat4 transform);

    SpriteRenderer sprite;

    glm::mat4 transform;
    glm::mat4 view = glm::mat4(1.0f);

    void scale(glm::vec3 scaleBy);

    void rotate(float angle);

    void transformVector(glm::vec3 posChange);

    glm::mat4 projection = glm::mat4(1.0f);

    void draw() const;
};


#endif //PROJECTBAHAMUT_GAMEOBJECT_H
