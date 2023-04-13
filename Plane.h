//
// Created by kiru on 4/13/23.
//

#ifndef PROJECTBAHAMUT_PLANE_H
#define PROJECTBAHAMUT_PLANE_H


#include "GameObject.h"

class Plane : public GameObject{



public:


    Plane(std::string name, const std::string &imgSource, glm::mat4 transform);

    void draw();
    Plane();
};


#endif //PROJECTBAHAMUT_PLANE_H
