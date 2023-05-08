//
// Created by kirut on 10/17/2022.
//

#ifndef PROJECTBAHAMUT_GAMEOBJECT_H
#define PROJECTBAHAMUT_GAMEOBJECT_H


#include <glm/gtx/matrix_decompose.hpp>
#include "SpriteRenderer.h"
#include "umTexture.h"
#include "Mesh.h"
#include "Model.h"
#include "Transformation.h"

class GameObject {
public:

    GameObject();

    GameObject(std::string name, glm::mat4 transform, Model model);

    GameObject(std::string name, Model model);

    ShaderLoader shaderLoader;
    std::string name;
    Model model;
    Transform transform;
    glm::vec3 skew;

    std::string textureModel; // TODO: to be deleted

    glm::vec4 perspective;
    glm::mat4 projection = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);

    virtual std::string getClass();





    void translate(const glm::vec3 &offset);
    void scale(const glm::vec3 &scale);



    void draw();

    glm::vec3 getPosition() const;
    glm::quat getRotation() const;
    glm::vec3 getScale() const;

    void rotate(glm::vec3 angles);
};


#endif //PROJECTBAHAMUT_GAMEOBJECT_H