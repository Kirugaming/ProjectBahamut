//
// Created by S722778 on 9/12/2022.
//
#include "window.h"

int main() {
    if (!glfwInit()) {
        std::cout << "GLFW failed to initialize!" << std::endl;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // get monitor to go sudo fullscreen
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* monitorInfo = glfwGetVideoMode(monitor);

    GLFWwindow* window = glfwCreateWindow(monitorInfo->width, monitorInfo->height, TITLE, nullptr, nullptr); // making the window and it's settings
    glfwMakeContextCurrent(window); // renders in the window
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // the resize window method

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Glad failed to Initialize!" << std::endl;
    }





    Game game; // to create the game objects for now

    EngineGUI engineGui(window, &game);

    // for camera controls right now
    float deltaTime;
    float currentFrame = 0.0;
    float lastFrame;

    glEnable(GL_DEPTH_TEST);

    ImVec4 skyboxColor = ImVec4(0.2f, 0.3f, 0.3f, 1.0f);
    while(!glfwWindowShouldClose(window)) {
        currentFrame = (float) glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // skybox color
        glClearColor(skyboxColor.x * skyboxColor.w, skyboxColor.y * skyboxColor.w, skyboxColor.z * skyboxColor.w, skyboxColor.w);
        // camera controls
        keyPressed(window, game, deltaTime);

        // helps so that you can't see through an object
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);





        // draw all scene game objects
        game.drawScene();


        // draw engine ui
        engineGui.renderFrames();






        glfwSwapBuffers(window);
        //  callbacks and such
        glfwPollEvents();
    }

    // shutdown engine ui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // shutdown rendering
    glfwTerminate();
}

void keyPressed(GLFWwindow *window, Game &game, float deltaTime) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        game.camera.ProcessKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        game.camera.ProcessKeyboard(FORWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        game.camera.ProcessKeyboard(BACKWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        game.camera.ProcessKeyboard(RIGHT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        game.camera.setYaw(-1);
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        game.camera.setPitch(1);
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        game.camera.setPitch(-1);
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        game.camera.setYaw(1);
    }

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
