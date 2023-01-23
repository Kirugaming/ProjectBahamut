//
// Created by kirut on 10/17/2022.
//

#ifndef PROJECTBAHAMUT_GAMEOBJECT_H
#define PROJECTBAHAMUT_GAMEOBJECT_H


#include <glm/gtx/matrix_decompose.hpp>
#include "SpriteRenderer.h"
#include "Texture.h"

class GameObject {
public:

    GameObject();

    GameObject(const char* name, const char *imgSource, glm::mat4 transform);

    SpriteRenderer sprite;


    glm::mat4 transform;

    glm::vec3 translation;

    glm::vec3 skew;

    char *name;
    bool nameEmpty();

    char *textureModel;
    float *position;
    float *rotation;
    float *scale;

    glm::vec4 perspective;
    glm::mat4 projection = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);





    void rotate(float angle, glm::vec3 vector);

    void transformVector(glm::vec3 posChange);

    void draw();


};


#endif //PROJECTBAHAMUT_GAMEOBJECT_H