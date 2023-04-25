//
// Created by kirut on 10/25/2022.
//

#include "Game.h"
#include "GameObject.h"
#include "Terrain.h"

Game::Game() : camera(glm::vec3(0.0f, 1.5f, 2.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, -45.0f) {
    // where i create the game objects that are displayed
    // these game objects are built-ins for debug purposes

    /*
    auto* ground = new Plane"ground", R"(grass.jpg)");

    this->sceneList.push_back(ground);

    auto* player = new Plane(std::string(), nullptr, "player", R"(stopstaring.png)", glm::mat4(1.0f));

    this->sceneList.push_back(player);

    */
    auto* portalGun=new GameObject("PortalGun", glm::mat4(1.0f), *new Model(R"(portal/gun.obj)"));

    portalGun->translate(glm::vec3(0.0f));
    portalGun->scale(glm::vec3(1.0f));
    this->sceneList.push_back(portalGun);
}

void Game::drawScene() {
    for (GameObject* key : this->sceneList) {
        // setup camera stuff for object
        key->projection = glm::perspective(glm::radians(camera.Zoom), (float)640 / (float)480, .1f, 100.0f); // look into this
        key->view = camera.GetViewMatrix();

        // draw game object
        key->draw();
    }


}