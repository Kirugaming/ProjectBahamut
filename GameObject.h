//
// Created by kirut on 10/17/2022.
//

#ifndef PROJECTBAHAMUT_GAMEOBJECT_H
#define PROJECTBAHAMUT_GAMEOBJECT_H


#include "SpriteRenderer.h"
#include "Texture.h"

class GameObject {
public:

    GameObject(const std::string &imgSource, ShaderLoader *shader);

    SpriteRenderer sprite;

    void draw() const;

};


#endif //PROJECTBAHAMUT_GAMEOBJECT_H
