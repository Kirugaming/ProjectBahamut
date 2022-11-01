//
// Created by kirut on 10/26/2022.
//

#ifndef PROJECTBAHAMUT_PLAYER_H
#define PROJECTBAHAMUT_PLAYER_H

#include "GameObject.h"

class Player : GameObject {
public:
    Player(const std::string &imgSource, ShaderLoader *shader, glm::mat4 transform);

    void editProjection(glm::mat4 value);

    void editView(glm::mat4 value);


    void draw();
};


#endif //PROJECTBAHAMUT_PLAYER_H
