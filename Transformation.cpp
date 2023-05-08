//
// Created by kirut on 5/3/2023.
//

#include "Transformation.h"

glm::mat4 Transform::transformToMat4(const Transform &transform) {
    // rotation
    glm::vec3 x = transform.rotation * glm::vec3(1.0f, 0.0f, 0.0f);
    glm::vec3 y = transform.rotation * glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 z = transform.rotation * glm::vec3(0.0f, 0.0f, 1.0f);
    // scale
    x *= transform.scale.x;
    y *= transform.scale.y;
    z *= transform.scale.z;
    // translation
    glm::vec3 p = transform.position;
    // create matrix
    return {x.x, x.y, x.z, 0.0f,
            y.x, y.y, y.z, 0.0f,
            z.x, z.y, z.z, 0.0f,
            p.x, p.y, p.z, 1.0f};
}
