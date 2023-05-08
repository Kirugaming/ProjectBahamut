//
// Created by kirut on 5/3/2023.
//

#ifndef PROJECTBAHAMUT_TRANSFORMATION_H
#define PROJECTBAHAMUT_TRANSFORMATION_H

#include <glm/vec3.hpp>
#include <glm/detail/type_quat.hpp>
#include <glm/fwd.hpp>
#include <glm/gtc/quaternion.hpp>

struct Transform {
    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;

    Transform(const glm::vec3 &position, const glm::quat &rotation, const glm::vec3 &scale) : position(position),
                                                                                              rotation(rotation),
                                                                                              scale(scale) {};
    Transform() : Transform(glm::vec3(0.0f), glm::quat(1.0f, 0.0f, 0.0f, 0.0f), glm::vec3(1.0f)) {};

    static glm::mat4 transformToMat4(const Transform &transform);
};


#endif //PROJECTBAHAMUT_TRANSFORMATION_H
