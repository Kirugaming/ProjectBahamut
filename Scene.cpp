//
// Created by kirut on 10/25/2022.
//

#include "Scene.h"
#include "GameObject.h"

Scene::Scene() {
    GameObject ground(R"(grass.jpg)", new ShaderLoader(R"(shader\shader.vert)", R"(shader\shader.frag)"),  glm::mat4(1.0f));
    //ground.rotate(-48.0f, glm::vec3(1.0f, 0.0f, 1.0f));

    gameOjbectMap.insert(std::pair<std::string, GameObject>("gorund", ground));

}