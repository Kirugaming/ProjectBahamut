//
// Created by kirut on 10/17/2022.
//

#ifndef PROJECTBAHAMUT_GAMEOBJECT_H
#define PROJECTBAHAMUT_GAMEOBJECT_H


#include <glm/gtx/matrix_decompose.hpp>
#include "SpriteRenderer.h"
#include "Texture.h"
#include "Mesh.h"
#include "Model.h"

class GameObject {
public:

    GameObject();

    GameObject(std::string name, glm::mat4 transform, Model model);

    Model model;

    ShaderLoader shaderLoader;

    glm::mat4 transform;


    glm::vec3 skew;

    std::string name;

    std::string textureModel;

    glm::vec4 perspective;
    glm::mat4 projection = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);





    void rotate(float angle, glm::vec3 axis);
    void translate(const glm::vec3 &offset);
    void scale(const glm::vec3 &scale);

    glm::vec3 getPosition();

    void draw();


    glm::vec3 getRotation() const;

    glm::vec3 getScale();

    void rotateXYZ(glm::vec3 eulerAngles);
};


#endif //PROJECTBAHAMUT_GAMEOBJECT_H