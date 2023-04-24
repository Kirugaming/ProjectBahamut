//
// Created by locke on 3/30/2023.
//

#include "Model.h"
#include "stb_image.h"
void Model::Draw(ShaderLoader shader) {
    for(unsigned int i=0;i<meshes.size();i++){
        meshes[i].draw(shader);
    }
}
void Model::loadModel(std::string path) {
    Assimp::Importer importer;
    const aiScene *scene =importer.ReadFile(path,aiProcess_Triangulate | aiProcess_FlipUVs);
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        std::cout << "IMPORT ERROR " << importer.GetErrorString()<<std::endl;
        return;
    }
    directory=path.substr(0,path.find_last_of("/"));
    processNode(scene->mRootNode,scene);
}

void Model::processNode(aiNode *node, const aiScene *scene) {
    for(unsigned int i=0;i<node->mNumMeshes;i++){
        aiMesh *mesh=scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh,scene));
    }
    for(unsigned int i=0;i<node->mNumChildren;i++){
        processNode(node->mChildren[i],scene);
    }
}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene) {
    std::vector<Vertex>vertices;
    std::vector<unsigned int> indices;
    std::vector<MeshTexture> textures;
    Colors colors;
    for(unsigned int i=0;i<mesh->mNumVertices;i++){
        Vertex vertex;
        //copy vertices over
        vertex.Position=glm::vec3(mesh->mVertices[i].x,mesh->mVertices[i].y,mesh->mVertices[i].z);
        //copy normals over
        vertex.Normal=glm::vec3(mesh->mNormals[i].x,mesh->mNormals[i].y,mesh->mNormals[i].z);

        //copy textures, if any otherwise default to 0's
        if(mesh->mTextureCoords[0]){
            vertex.Coords=glm::vec2(mesh->mTextureCoords[0][i].x,mesh->mTextureCoords[0][i].y);

        }
        else{
            vertex.Coords=glm::vec2(0.0f,0.0f);
        }
        vertices.push_back(vertex);
    }
    for(unsigned int i=0;i<mesh->mNumFaces;i++){
        aiFace face=mesh->mFaces[i];
        for(unsigned int j=0;j<face.mNumIndices;j++){
            indices.push_back(face.mIndices[j]);
        }
    }
    if(mesh->mMaterialIndex>=0){
        aiMaterial *mat=scene->mMaterials[mesh->mMaterialIndex];
        std::vector<MeshTexture>diffuseMaps= loadMaterialTextures(mat,aiTextureType_DIFFUSE,"texture_diffuse");
        textures.insert(textures.end(),diffuseMaps.begin(),diffuseMaps.end());
        std::vector<MeshTexture>specularMaps= loadMaterialTextures(mat,aiTextureType_SPECULAR,"texture_specular");
        textures.insert(textures.end(),specularMaps.begin(),specularMaps.end());
        aiColor3D ambient;
        mat->Get(AI_MATKEY_COLOR_AMBIENT,ambient);
        colors.ambient=glm::vec3(ambient.r,ambient.g,ambient.b);
        aiColor3D diffuse;
        mat->Get(AI_MATKEY_COLOR_DIFFUSE,diffuse);
        colors.diffuse=glm::vec3(diffuse.r,diffuse.g,diffuse.b);
        aiColor3D emissive;
        mat->Get(AI_MATKEY_COLOR_EMISSIVE,emissive);
        colors.emissive=glm::vec3(emissive.r,emissive.g,emissive.b);
        aiColor3D specular;
        mat->Get(AI_MATKEY_COLOR_EMISSIVE,specular);
        colors.emissive=glm::vec3(specular.r,specular.g,specular.b);
    }


    return {vertices,indices,textures,colors};
}

std::vector<MeshTexture> Model::loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName)
{
    std::vector<MeshTexture> textures;
    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
        bool skip = false;
        for(unsigned int j = 0; j < textures_loaded.size(); j++)
        {
            if(std::strcmp(textures_loaded[j].path.data(), str.C_Str()) == 0)
            {
                textures.push_back(textures_loaded[j]);
                skip = true;
                break;
            }
        }
        if(!skip)
        {   // if texture hasn't been loaded already, load it
            MeshTexture texture;
            texture.id = TextureFromFile(str.C_Str(), directory);
            texture.type = typeName;
            texture.path = str.C_Str();
            textures.push_back(texture);
            textures_loaded.push_back(texture); // add to loaded textures
        }
    }
    return textures;
}

unsigned int Model::TextureFromFile(const char *path, const std::string directory) {
    std::string fname=std::string(path);
    fname=directory+"/"+fname;
    unsigned int texId;
    int width,height,nrComponents;
    unsigned char *data= stbi_load(fname.c_str(),&width,&height,&nrComponents,0);
    if(data){
        GLenum format;
        if(nrComponents==1){
            format=GL_RED;
        }
        else if(nrComponents==3){
            format=GL_RGB;
        }
        else if(nrComponents==4){
            format=GL_RGBA;
        }
        glGenTextures(1,&texId);
        glBindTexture(GL_TEXTURE_2D,texId);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // filtering
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_image_free(data);
    }
    else{
        std::cout<< "Texture failed to load at path" <<std::endl;
        stbi_image_free(data);
    }
    return texId;
}

