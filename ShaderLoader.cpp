//
// Created by S722778 on 9/13/2022.
//

#include "ShaderLoader.h"

ShaderLoader::ShaderLoader(const std::string& vertexSource, const std::string& fragmentSource) {
    // load shader files
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vertexFile;
    std::ifstream fragmentFile;
    // throw exceptions
    vertexFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fragmentFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    // opening up the shader files
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
    int success;
    char infoLog[512];

    // vertex
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);
    // if errors
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        std::cout << "Vertex Shader failed to compile!\n" << infoLog << std::endl;
    }

    // fragment
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);
    // if errors
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        std::cout << "Fragment shader failed to compile!\n" << infoLog << std::endl;
    }

    shaderProgramID = glCreateProgram();
    glAttachShader(shaderProgramID, vertex);
    glAttachShader(shaderProgramID, fragment);
    glLinkProgram(shaderProgramID);
    // program errors
    glGetShaderiv(shaderProgramID, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shaderProgramID, 512, nullptr, infoLog);
        std::cout << "Shader program failed to link!\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

ShaderLoader & ShaderLoader::useShader() const {
    glUseProgram(this->shaderProgramID);
    return const_cast<ShaderLoader &>(*this);
}

// a bunch of methods that allow dev to edit the shaders uniform variables

void ShaderLoader::editShaderWithMat4(const char *uniformName, glm::mat4 &matrix) const {
    this->useShader();
    glUniformMatrix4fv(glGetUniformLocation(this->shaderProgramID, uniformName), 1, GL_FALSE, glm::value_ptr(matrix));
}

ShaderLoader::ShaderLoader() {
    // load shader files
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vertexFile;
    std::ifstream fragmentFile;
    // throw exceptions
    vertexFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fragmentFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try {
        vertexFile.open("shader/shader.vert");
        fragmentFile.open("shader/shader.frag");
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
    int success;
    char infoLog[512];

    // vertex
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);
    // if errors
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        std::cout << "Vertex Shader failed to compile!\n" << infoLog << std::endl;
    }

    // fragment
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);
    // if errors
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        std::cout << "Fragment shader failed to compile!\n" << infoLog << std::endl;
    }

    shaderProgramID = glCreateProgram();
    glAttachShader(shaderProgramID, vertex);
    glAttachShader(shaderProgramID, fragment);
    glLinkProgram(shaderProgramID);
    // program errors

}
