//
// Created by S722778 on 9/13/2022.
//

#include "ShaderLoader.h"

// default constructor
ShaderLoader::ShaderLoader() : ShaderLoader("shaders/shader.vert", "shaders/shader.frag") {}

ShaderLoader::ShaderLoader(const std::string& vertexSource, const std::string& fragmentSource) {
    // load shaders files
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vertexFile;
    std::ifstream fragmentFile;
    // throw exceptions
    vertexFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fragmentFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    // opening up the shaders files
    try {
        vertexFile.open(vertexSource);
        fragmentFile.open(fragmentSource);
        std::stringstream  vertexStream, fragmentStream;
        // read string buffer from file
        vertexStream << vertexFile.rdbuf();
        fragmentStream << fragmentFile.rdbuf();

        vertexFile.close();
        fragmentFile.close();
        // make stream into string
        vertexCode = vertexStream.str();
        fragmentCode = fragmentStream.str();
    }
    catch(std::exception& exception) {
        std::cout << "Shader failed to load from file!" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    // load shaders
    unsigned int vertex, fragment;
    // vertex
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);
    // if errors
    getShaderCompileInfoLog(vertex);

    // fragment
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);
    // if errors
    getShaderCompileInfoLog(fragment);

    // shader program

    shaderProgramID = glCreateProgram();
    if (shaderProgramID <= 0) {
        std::cout << "Shader program creation failed!" << std::endl;
        return;
    }
    glAttachShader(shaderProgramID, vertex);
    glAttachShader(shaderProgramID, fragment);
    glLinkProgram(shaderProgramID);
    // program errors
    getShaderProgramLinkInfoLog(shaderProgramID);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

ShaderLoader& ShaderLoader::useShader() {
    if (this->shaderProgramID == 0) {
        throw std::runtime_error("No shader program loaded");
    }
    glUseProgram(this->shaderProgramID);
    return *this;
}
// a bunch of methods that allow dev to edit the shaders uniform variables

void ShaderLoader::editShaderWithMat4(const char *uniformName, glm::mat4 &matrix) const {
    glUniformMatrix4fv(glGetUniformLocation(this->shaderProgramID, uniformName), 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderLoader::getShaderProgramLinkInfoLog(unsigned int shaderProgramID) {
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgramID, 512, nullptr, infoLog);
        std::cout << "Shader program failed to link! - " << infoLog << std::endl;
    }
}

void ShaderLoader::getShaderCompileInfoLog(unsigned int shaderID) {
    int success;
    char infoLog[512];
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
        // get shaders type and print
        std::cout << "Shader failed to compile! - " << infoLog << std::endl;
    }

}
// need to have more to edit the shaders


