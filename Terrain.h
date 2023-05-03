//
// Created by kirut on 4/6/2023.
//

#ifndef PROJECTBAHAMUT_TERRAIN_H
#define PROJECTBAHAMUT_TERRAIN_H


#include <vector>
#include "GameObject.h"

class Terrain : public GameObject {
public:

    std::vector<float> heightMap;
    //std::vector<Vertex> vertices;


    Terrain();

    Terrain(std::string name, const std::string &imgSource);

    void draw();
    std::string getClass() override;

private:
    static float noise(int x, int y);
    static std::vector<float> generateHeightMap(int width, int height);
};


#endif //PROJECTBAHAMUT_TERRAIN_H
