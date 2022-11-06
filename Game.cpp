//
// Created by kirut on 10/25/2022.
//

#include "Game.h"

Game::Game() : camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)), player(R"(cat.png)", new ShaderLoader(R"(shader\shader.vert)", R"(shader\shader.frag)"),glm::mat4(1.0f)) {



    GameObject ground(R"(grass.jpg)", new ShaderLoader(R"(shader\shader.vert)", R"(shader\shader.frag)"),  glm::mat4(1.0f));

    ground.transformVector(glm::vec3(0.0f, -1.0f, 0.0f));
    ground.rotate(4.7f, glm::vec3(1.0f, 0.0f, 0.0f));
    ground.scale(glm::vec3(5.0f, 5.0f, 0.0f));
    this->sceneMap.insert(std::pair<std::string, GameObject>("ground", ground));
}

void Game::drawScene() {
    for (std::pair<std::string, GameObject> key: sceneMap) {
        key.second.projection = glm::perspective(glm::radians(camera.Zoom), (float)640 / (float)480, .1f, 100.0f);
        key.second.view = camera.GetViewMatrix();

        key.second.draw();
    }
    this->player.editProjection(glm::perspective(glm::radians(camera.Zoom), (float)640 / (float)480, .1f, 100.0f));
    this->player.editView(camera.GetViewMatrix());

    this->player.draw();


}
