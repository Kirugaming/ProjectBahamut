//
// Created by S722778 on 9/13/2022.
//

#ifndef PROJECTBAHAMUT_SHADERLOADER_H
#define PROJECTBAHAMUT_SHADERLOADER_H

#include "glad/glad.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


class ShaderLoader {
public:
    unsigned int shaderProgramID;


    ShaderLoader();

    ShaderLoader(const std::string& vertexSource, const std::string& fragmentSource);

    static void getShaderProgramLinkInfoLog(unsigned int shaderProgramID) ;
    static void getShaderCompileInfoLog(unsigned int shaderID) ;

    void editShaderWithMat4(const char* uniformName, glm::mat4 &matrix) const;
    void editShaderWithVec3(const char* uniformName, glm:: vec3 &colors)const;
    ShaderLoader &useShader();
    void setInt(const std::string &name, int value) const;


};


#endif //PROJECTBAHAMUT_SHADERLOADER_H
