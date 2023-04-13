//
// Created by kirut on 11/9/2022.
//

#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "EngineGUI.h"
#include "Plane.h"
#include <imgui.h>


EngineGUI::EngineGUI(GLFWwindow* window, Game* game) : gamePointer(game) {
// dear imgui interface stuff
// start imgui stuff
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(window, true); // link to window
    ImGui_ImplOpenGL3_Init();
    ImGui::StyleColorsDark(); // some settings

    // Load Icon Assets into Memory
    iconAssets.insert(iconAssets.end(), Texture("Assets/icons/cube-solid.png"));


}

void EngineGUI::renderFrames() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // window settings
    ImGuiWindowFlags guiWindowFlags = 0;
    guiWindowFlags |= ImGuiWindowFlags_NoMove;
    guiWindowFlags |= ImGuiWindowFlags_NoResize;
    guiWindowFlags |= ImGuiWindowFlags_NoCollapse;
    guiWindowFlags |= ImGuiWindowFlags_NoNav;
    guiWindowFlags |= ImGuiWindowFlags_NoTitleBar;

    // set positions of these imgui windows
    // set main one to top right corner
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x - 300, 0), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(300, 300), ImGuiCond_Once);

    ImGui::Begin("Game Object Editor", reinterpret_cast<bool *>(true), guiWindowFlags);
    ImGui::Text("Game Object Editor\t\t");
    ImGui::SameLine();
    ImGui::Button("Map Editor");
    ImGui::Separator();
    ImGui::Text("Game Objects:");



    ImGui::ShowDemoWindow(); // test window for imgui that helps reference its many functions


    for (auto object : this->gamePointer->sceneList) {
        // if char[] is empty then give button with blank name
        if (object->name.empty()) {
            if (ImGui::Button(" ")) {
                std::cout << "Clicked on " << object->name << std::endl;
                this->selectedObject = object;
            }
        } else {
            // icon
            auto iconTexuture = reinterpret_cast<ImTextureID>(iconAssets[0].textureId);
            ImGui::PushID("gameobject_icon");

            //                                                              | this part rotates horizontally
            ImGui::Image(iconTexuture, ImVec2(20, 20), ImVec2(0, 1), ImVec2(1, 0));
            ImGui::SameLine();
            std::string nameBuffer = object->name;
            if (ImGui::Button(nameBuffer.c_str())) {
                std::cout << "Clicked on " << object->name << std::endl;
                this->selectedObject = object;
            }

            ImGui::PopID();
        }

    }

    // if right click on window then show popup
    if (ImGui::BeginPopupContextWindow()) {
        if (ImGui::MenuItem("Add Object")) { // if clicked then run below
            std::cout << "Add Object" << std::endl;
            //selectedObject = new Plane();
            // add number to name if same name already exists in sceneMap
            int count = 0;
            for (auto object : this->gamePointer->sceneList) {
                if (object->name == selectedObject->name) {
                    count++;
                }
            }

            this->gamePointer->sceneList.push_back(selectedObject);
            

        }

        ImGui::EndPopup();
    }

    if (selectedObject != nullptr) {
        objectEditWindow(selectedObject);
    }



    ImGui::End();



    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void EngineGUI::objectEditWindow(GameObject *gameObject) {
    ImGui::SetNextWindowSize(ImVec2(300, 300), ImGuiCond_Once);
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x - 300, 300), ImGuiCond_Once);
    ImGui::Begin("Object Editor", reinterpret_cast<bool *>(true), ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
    ImGui::Text("This is the object editor window!");
    ImGui::Separator();
    ImGui::Text("Object Name:");  // Where users can edit the name of game objects
    char buffer[256]; // Make sure the buffer is large enough
    strcpy(buffer, gameObject->name.c_str());
    if (ImGui::InputText("##Object Name", buffer, 256)) {gameObject->name = std::string(buffer);
        std::cout << "Changed name to " << gameObject->name << std::endl;
    }

    ImGui::Separator();
    ImGui::Text("Texture/Model:"); // where users can change the model (texture as of now since the engine only renders 3d planes)
    char textureModelBuffer[64];
    strcpy(textureModelBuffer, gameObject->textureModel.c_str());
    if (ImGui::InputText("##Texture/Model", textureModelBuffer, 64)) {
        gameObject->textureModel = std::string(textureModelBuffer);
        std::cout << "Changed texture/model to " << gameObject->textureModel << std::endl;
    }
    ImGui::Separator();
    // where users can change various transformation stuff
    ImGui::Text("Object Position:");
    glm::vec3 position = gameObject->getPosition();
    if (ImGui::DragFloat3("##Position xyz", glm::value_ptr(position), 0.005f)) {
        gameObject->translate(position - gameObject->getPosition());
    }
    ImGui::Separator();
    ImGui::Text("Object Rotation:");
    glm::vec3 rotation = gameObject->getRotation();
    if (ImGui::DragFloat3("##Rotation xyz", glm::value_ptr(rotation), 0.05f)) {
        gameObject->rotateXYZ(rotation - gameObject->getRotation());
    }
    ImGui::Separator();
    ImGui::Text("Object Scale:");
    glm::vec3 scale = gameObject->getScale();
    if (ImGui::DragFloat3("##Scale xyz", glm::value_ptr(scale), 0.005f)) {
        gameObject->scale(scale);
    }
    ImGui::Separator();

    ImGui::End();
}
