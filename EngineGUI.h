//
// Created by kirut on 11/9/2022.
//

#ifndef PROJECTBAHAMUT_ENGINEGUI_H
#define PROJECTBAHAMUT_ENGINEGUI_H


#include "Game.h"
#include "Terrain.h"
#include "lib/imgui_impl_glfw.h"
#include "lib/imgui_impl_opengl3.h"

class EngineGUI {
public:
    Game* gamePointer;

    GameObject *selectedObject= nullptr;

    std::vector<umTexture> iconAssets;

    EngineGUI(GLFWwindow* window, Game* game);

    void renderFrames();

    static void objectEditWindow(GameObject *gameObject);
};


#endif //PROJECTBAHAMUT_ENGINEGUI_H
