//
// Created by kirut on 11/9/2022.
//

#include <iostream>
#include "lib/glad.h"
#include <GLFW/glfw3.h>
#include "EngineGUI.h"
#include "lib/imgui/imgui.h"
#include "lib/imgui/imgui_impl_glfw.h"
#include "lib/imgui/imgui_impl_opengl3.h"

EngineGUI::EngineGUI(GLFWwindow* window, Game* game) : gamePointer(game) {
// dear imgui interface stuff
// start imgui stuff
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(window, true); // link to window
    ImGui_ImplOpenGL3_Init();
    ImGui::StyleColorsDark(); // some settings


}

void EngineGUI::renderFrames() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Project Bahamut Test");
    ImGui::Text("Hello, world!");
    ImGui::Separator();
    ImGui::Text("Game Objects:");

    //ImGui::ShowDemoWindow();

    for (std::pair<std::string, GameObject> pair : this->gamePointer->sceneMap) {
        // if char[] is empty then give button with blank name
        if (pair.second.name.empty()) {
            if (ImGui::Button(" ")) {
                std::cout << "Clicked on " << pair.first << std::endl;
                this->selectedObject = pair.second;
            }
        } else {
            char nameBuffer[256];
            std::strcpy(nameBuffer,pair.second.name.c_str());
            if (ImGui::Button(nameBuffer)) {
                //TODO camera goes to object when clicked
                std::cout << "Clicked on " << pair.first << std::endl;
                this->selectedObject = pair.second;
            }
        }

    }

    // if right click on window then show popup
    if (ImGui::BeginPopupContextWindow()) {
        if (ImGui::MenuItem("Add Object")) { // if clicked then run below
            std::cout << "Add Object" << std::endl;
            selectedObject = GameObject();
            // add number to name if same name already exists in sceneMap
            selectedObject.name = "New Object";
            int i = 1;
            while (this->gamePointer->sceneMap.find(selectedObject.name) != this->gamePointer->sceneMap.end()) {
                selectedObject.name = std::string("New Object " + std::to_string(i)).c_str();
                i++;
            }
            this->gamePointer->sceneMap.insert(std::pair<std::string, GameObject>(selectedObject.name, selectedObject));
        }

        ImGui::EndPopup();
    }

    objectEditWindow(selectedObject);




    ImGui::End();



    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void EngineGUI::objectEditWindow( GameObject& gameObject) {
    ImGui::Begin("Object Editor");
    ImGui::Text("This is the object editor window!");
    ImGui::Separator();
    ImGui::Text("Object Name:");
    char nameBuffer[256];
    std::strcpy(nameBuffer,gameObject.name.c_str());
    if(ImGui::InputText("##ObjectName",nameBuffer,64)){
        gameObject.name=nameBuffer;
    }

    ImGui::Separator();
    ImGui::Text("Texture/Model:");
    ImGui::InputText("##TextureModel", gameObject.textureModel, 64);
    ImGui::Separator();
    ImGui::Text("Object Position:");
    ImGui::DragFloat3("##Position xyz", &gameObject.position[0], 0.005f);
    ImGui::Separator();
    ImGui::Text("Object Rotation:");
    ImGui::DragFloat3("##Rotation xyz", &gameObject.rotation[0], 0.05f);
    ImGui::Separator();
    ImGui::Text("Object Scale:");
    ImGui::DragFloat3("##Scale xyz", &gameObject.scale[0], 0.005f);
    ImGui::Separator();

    ImGui::End();
}
