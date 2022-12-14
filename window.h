//
// Created by kirut on 9/12/2022.
//

#ifndef PROJECTBAHAMUT_WINDOW_H
#define PROJECTBAHAMUT_WINDOW_H

#include "lib\glad.c"
#include <GLFW/glfw3.h>
#include <iostream>
#include "Texture.h"
#include "GameObject.h"
#include "Game.h"
#include "lib/imgui/imgui.h"
#include "lib/imgui/imgui_impl_glfw.h"
#include "lib/imgui/imgui_impl_opengl3.h"
#include "glm/gtx/matrix_decompose.hpp"


int WIN_WIDTH = 640;
int WIN_HEIGHT = 480;
char TITLE[] = "ProjectBahamut";


void keyPressed(GLFWwindow *window, Game &game, float deltaTime);

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif //PROJECTBAHAMUT_WINDOW_H
