//
// Created by kirut on 9/12/2022.
//

#ifndef PROJECTBAHAMUT_WINDOW_H
#define PROJECTBAHAMUT_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "textureLoader.h"

int WIN_WIDTH = 640;
int WIN_HEIGHT = 480;
char TITLE[] = "ProjectBahamut";


void keyPressed(GLFWwindow *window);

#endif //PROJECTBAHAMUT_WINDOW_H
