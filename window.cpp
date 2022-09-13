//
// Created by S722778 on 9/12/2022.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "window.h"
#include "textureLoader.h"

int main() {
    if (!glfwInit()) {
        std::cout << "GLFW failed to initialize!" << std::endl;
    }

    GLFWwindow* window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, TITLE, nullptr, nullptr);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Glad failed to Initialize!" << std::endl;
    }

    textureLoader::loadTexture();

    while(!glfwWindowShouldClose(window)) {
        keyPressed(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

void keyPressed(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
