//
// Created by locke on 3/28/2023.
//
#include <string>
#include "glm/vec3.hpp"
#include "ShaderLoader.h"
#include <vector>
#ifndef PROJECTBAHAMUT_MESH_H
#define PROJECTBAHAMUT_MESH_H
struct Vertex{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 Coords;
};
struct MeshTexture{
    unsigned int id;
    std::string type;
    std::string path;
};
class Mesh{
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<MeshTexture> textures;
    Mesh(std::vector<Vertex>vertices,std::vector<unsigned int>indices,std::vector<MeshTexture>textures);
    void draw(ShaderLoader &shader );
private:
    unsigned int VBO,VAO,EBO;
    void setUpMesh();
};
#endif //PROJECTBAHAMUT_MESH_H
