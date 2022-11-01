//
// Created by kirut on 10/25/2022.
//

#ifndef PROJECTBAHAMUT_SCENE_H
#define PROJECTBAHAMUT_SCENE_H


#include <map>
#include <string>
#include <unordered_map>
#include "GameObject.h"

class Scene {
public:
    std::unordered_map<std::string, GameObject>  gameOjbectMap;
    Scene();
};


#endif //PROJECTBAHAMUT_SCENE_H
