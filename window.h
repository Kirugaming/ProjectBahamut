//
// Created by kirut on 9/12/2022.
//

#ifndef PROJECTBAHAMUT_WINDOW_H
#define PROJECTBAHAMUT_WINDOW_H

#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "EngineGUI.h"
#include "Game.h"
#include <imgui.h>
#include "lib/imgui_impl_glfw.h"
#include "lib/imgui_impl_opengl3.h"


int WIN_WIDTH = 640;
int WIN_HEIGHT = 480;
char TITLE[] = "ProjectBahamut";


void keyPressed(GLFWwindow *window, Game &game, float deltaTime);

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif //PROJECTBAHAMUT_WINDOW_H
