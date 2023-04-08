//
// Created by kirut on 10/25/2022.
//

#ifndef PROJECTBAHAMUT_GAME_H
#define PROJECTBAHAMUT_GAME_H


#include <unordered_map>
#include <string>
#include "camera.h"

#include "GameObject.h"
class Game {
public:
    std::vector<GameObject*> sceneList;
    Camera camera;

    Game();



    void drawScene();

};


#endif //PROJECTBAHAMUT_GAME_H
