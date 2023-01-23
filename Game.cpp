//
// Created by kirut on 10/25/2022.
//

#include "Game.h"

Game::Game() : camera(glm::vec3(0.0f, 1.5f, 2.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, -45.0f) {

    GameObject ground("ground", R"(grass.jpg)",  glm::mat4(1.0f));


    //ground.setTranslation(glm::vec3(0.0f, -1.0f, 0.0f));
    //ground.setRotation(glm::vec3(1.0f, 0.0f, 0.0f));
    //ground.setScale(glm::vec3(5.0f, 5.0f, 0.0f));
    this->sceneMap.insert(std::pair<std::string, GameObject>("ground", ground));

    GameObject player("player", R"(cat.png)", glm::mat4(1.0f));
    //player.scale(glm::vec3(.5f, .5f, .5f));
    player.transformVector(glm::vec3(0.0f, -0.9f, 0.0f));
    this->sceneMap.insert(std::pair<std::string, GameObject>("player", player));
}

void Game::drawScene() {
    for (std::pair<std::string, GameObject> key: sceneMap) {
        key.second.projection = glm::perspective(glm::radians(camera.Zoom), (float)640 / (float)480, .1f, 100.0f);
        key.second.view = camera.GetViewMatrix();

        key.second.draw();
    }


}