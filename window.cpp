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

    // dear imgui interface stuff
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    std::cout << reinterpret_cast<const char *>(glGetString(GL_VERSION)) << std::endl;
    ImGui_ImplOpenGL3_Init();
    ImGui::StyleColorsDark();



    GameObject player(R"(cat.png)", new ShaderLoader(R"(shader\shader.vert)", R"(shader\shader.frag)"),glm::mat4(1.0f));
    player.scale(glm::vec3(.5f, .5f, .5f));

    Game game;

    float deltaTime;
    float currentFrame = 0.0;
    float lastFrame;

    glEnable(GL_DEPTH_TEST);


    ImVec4 skyboxColor = ImVec4(0.2f, 0.3f, 0.3f, 1.0f);
    while(!glfwWindowShouldClose(window)) {
        currentFrame = (float) glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        keyPressed(window, game, deltaTime);

        glClearColor(skyboxColor.x * skyboxColor.w, skyboxColor.y * skyboxColor.w, skyboxColor.z * skyboxColor.w, skyboxColor.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        // imgui
        // feed inputs to dear imgui, start new frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        game.drawScene();



        ImGui::Begin("Project Bahamut Test! Hello World!");
        ImGui::Button("This is big if true!!");
        ImGui::ColorEdit3("Skybox Color", reinterpret_cast<float *>(&skyboxColor));

        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

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
