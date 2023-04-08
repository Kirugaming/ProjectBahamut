//
// Created by kirut on 4/6/2023.
//

#ifndef PROJECTBAHAMUT_TERRAIN_H
#define PROJECTBAHAMUT_TERRAIN_H


#include "GameObject.h"

class Terrain : public GameObject {
public:
    Terrain(std::string name, const char *imgSource);

    void draw();
};


#endif //PROJECTBAHAMUT_TERRAIN_H
