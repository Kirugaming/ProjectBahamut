//
// Created by kirut on 10/25/2022.
//

#ifndef PROJECTBAHAMUT_GAME_H
#define PROJECTBAHAMUT_GAME_H


#include "Scene.h"
#include "camera.h"
#include "Player.h"

class Game {
public:
    std::unordered_map<std::string, GameObject> sceneMap;
    Camera camera;
    Player player;

    Game();



    void drawScene();
};


#endif //PROJECTBAHAMUT_GAME_H
