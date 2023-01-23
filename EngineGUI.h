//
// Created by kirut on 11/9/2022.
//

#ifndef PROJECTBAHAMUT_ENGINEGUI_H
#define PROJECTBAHAMUT_ENGINEGUI_H


#include "Game.h"

class EngineGUI {
public:
    Game* gamePointer;

    GameObject selectedObject;

    EngineGUI(GLFWwindow* window, Game* game);

    void renderFrames();

    static void objectEditWindow(const GameObject& gameObject);
};


#endif //PROJECTBAHAMUT_ENGINEGUI_H
