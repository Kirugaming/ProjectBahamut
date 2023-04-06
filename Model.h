//
// Created by locke on 3/30/2023.
//

#ifndef PROJECTBAHAMUT_MODEL_H
#define PROJECTBAHAMUT_MODEL_H


#include "Mesh.h"
#include "ShaderLoader.h"
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
class Model {
    std::vector<MeshTexture> textures_loaded;
public:
    Model(char *path){
        loadModel(path);
    }

    void Draw(ShaderLoader shader);

private:
    std::vector<Mesh> meshes;
    std::string directory;
    void loadModel(std::string path);
    unsigned int TextureFromFile(const char* str,const std::string directory);
    void processNode(aiNode *node,const aiScene *aiScene);
    Mesh processMesh(aiMesh *mesh,const aiScene *aiScene);
    std::vector<MeshTexture>loadMaterialTextures(aiMaterial *mat,aiTextureType type,std::string typeName);
};


#endif //PROJECTBAHAMUT_MODEL_H
