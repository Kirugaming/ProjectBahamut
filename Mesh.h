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
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
    //bone indexes which will influence this vertex
    int m_BoneIDs[4];
    //weights from each bone
    float m_Weights[4];
};

struct Colors{
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    glm::vec3 emissive;
};
struct Texture{
    unsigned int id;
    std::string type;
    std::string path;
};
class Mesh{
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;
    Mesh(std::vector<Vertex>vertices,std::vector<unsigned int>indices,std::vector<Texture>textures);
    Colors colors;
    Mesh(std::vector<Vertex>vertices,std::vector<unsigned int>indices,std::vector<Texture>textures,Colors colors);
    void draw(ShaderLoader &shader );
private:
    unsigned int VBO,VAO,EBO;
    void setUpMesh();
};
#endif //PROJECTBAHAMUT_MESH_H
