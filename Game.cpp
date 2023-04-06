//
// Created by kirut on 10/25/2022.
//

#include "Game.h"
#include "GameObject.h"
Game::Game() : camera(glm::vec3(0.0f, 1.5f, 2.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, -45.0f) {
    // where i create the game objects that are displayed
    // these game objects are built-ins for debug purposes

    GameObject ground("ground", R"(grass.jpg)",  glm::mat4(1.0f));
    ground.transformVector(glm::vec3(0.0f, -2.0f, 0.0f));
    this->sceneMap.insert(std::pair<std::string, GameObject>("ground", ground)); // the map is stupid, and we could just do an arraylist

    GameObject player("player", R"(pixelbg.jpg)", glm::mat4(1.0f));

    player.transformVector(glm::vec3(0.0f, -0.9f, 0.0f));
    this->sceneMap.insert(std::pair<std::string, GameObject>("player", player));
}

void Game::drawScene() {
    for (std::pair<std::string, GameObject> key: sceneMap) {
        // setup camera stuff for object
        key.second.projection = glm::perspective(glm::radians(camera.Zoom), (float)640 / (float)480, .1f, 100.0f); // look into this
        key.second.view = camera.GetViewMatrix();

        // draw game object
        key.second.draw();
    }


}