//
// Created by S722778 on 9/13/2022.
//

#ifndef PROJECTBAHAMUT_SHADERLOADER_H
#define PROJECTBAHAMUT_SHADERLOADER_H

#include "glad/glad.h"
#include <fstream>
#include <sstream>
#include <iostream>


class ShaderLoader {
public:
    unsigned int shaderProgramID;



    ShaderLoader(const std::string& vertexSource, const std::string& fragmentSource);

    void useShaderProgram() const;
};


#endif //PROJECTBAHAMUT_SHADERLOADER_H
