//
// Created by kirut on 10/25/2022.
//

#ifndef PROJECTBAHAMUT_GAME_H
#define PROJECTBAHAMUT_GAME_H


#include <unordered_map>
#include "camera.h"
#include "Player.h"

class Game {
public:
    std::unordered_map<std::string, GameObject> sceneMap;
    Camera camera;

    Game();



    void drawScene();

};


#endif //PROJECTBAHAMUT_GAME_H
