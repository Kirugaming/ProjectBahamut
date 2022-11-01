//
// Created by S722778 on 9/12/2022.
//
#include "window.h"
#include "ShaderLoader.h"
#include "GameObject.h"
#include "Game.h"

int main() {
    if (!glfwInit()) {
        std::cout << "GLFW failed to initialize!" << std::endl;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, TITLE, nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Glad failed to Initialize!" << std::endl;
    }




    GameObject player(R"(cat.png)", new ShaderLoader(R"(shader\shader.vert)", R"(shader\shader.frag)"),glm::mat4(1.0f));
    player.scale(glm::vec3(.5f, .5f, .5f));

    Game game;


    while(!glfwWindowShouldClose(window)) {
        keyPressed(window, player);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        game.camera.Position = glm::vec3(sin(0.0f), 0.0f, cos(glfwGetTime() * 1.0f));

        //std::cout << game.camera.Position.x << std::endl;


        game.drawScene();






        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

void keyPressed(GLFWwindow *window, GameObject &box) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
        box.scale(glm::vec3(.9f, .9, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
        box.scale(glm::vec3(1.1f, 1.1f, 0.0f));
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        box.transformVector(glm::vec3(-0.1f, 0.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        box.transformVector(glm::vec3(0.1f, 0.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        box.transformVector(glm::vec3(0.0f, 0.1f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        box.transformVector(glm::vec3(0.0f, -0.1f, 0.0f));
    }

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
