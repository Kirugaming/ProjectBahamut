//
// Created by kirut on 4/6/2023.
//

#include "Terrain.h"

#include <utility>

Terrain::Terrain() : Terrain("Terrain", R"(default.png)") {}

Terrain::Terrain(std::string name, const std::string& imgSource) : GameObject(std::move(name), imgSource, glm::mat4(1.0f)) {
    heightMap = generateHeightMap(100, 100);

}

std::string Terrain::getClass() {
    return "Terrain";
}

float Terrain::noise(int x, int y) {
    // Generate random gradient vectors
    int x0 = (int)std::floor(x);
    int y0 = (int)std::floor(y);
    int x1 = x0 + 1;
    int y1 = y0 + 1;
    float sx = x - x0;
    float sy = y - y0;

    float n0, n1, ix0, ix1, value;
    n0 = glm::dot(glm::vec2(x - x0, y - y0), glm::normalize(glm::vec2(std::sin(x * 12.9898 + y * 78.233), std::sin(x * 67.231 + y * 67.8999))));
    n1 = glm::dot(glm::vec2(x - x1, y - y0), glm::normalize(glm::vec2(std::sin(x * 12.9898 + y * 78.233), std::sin(x * 67.231 + y * 67.8999))));
    ix0 = glm::mix(n0, n1, sx);

    n0 = glm::dot(glm::vec2(x - x0, y - y1), glm::normalize(glm::vec2(std::sin(x * 12.9898 + y * 78.233), std::sin(x * 67.231 + y * 67.8999))));
    n1 = glm::dot(glm::vec2(x - x1, y - y1), glm::normalize(glm::vec2(std::sin(x * 12.9898 + y * 78.233), std::sin(x * 67.231 + y * 67.8999))));
    ix1 = glm::mix(n0, n1, sx);

    value = glm::mix(ix0, ix1, sy);

    return value;
}

std::vector<float> Terrain::generateHeightMap(int width, int height) {
std::vector<float> methodHeightMap;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            methodHeightMap.push_back(noise(i, j));
        }
    }
    return methodHeightMap;
}
