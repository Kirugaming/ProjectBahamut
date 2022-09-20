//
// Created by S722778 on 9/12/2022.
//
#include "window.h"
#include "ShaderLoader.h"

int main() {
    if (!glfwInit()) {
        std::cout << "GLFW failed to initialize!" << std::endl;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, TITLE, nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Glad failed to Initialize!" << std::endl;
    }

    float square[] = {
            // positions                     // colors                      // Texture coords
            0.9f,  0.9f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f, // top right
            0.9f, -0.9f, 0.0f,   0.0f, 1.0f, 1.0f,   0.0f, 1.0f, // bottom right
            -0.9f, -0.9f, 0.0f,   0.0f, 0.0f, 1.0f,   1.0f, 1.0f, // bottom left
            -0.9f,  0.9f, 0.0f,   1.0f, 1.0f, 0.0f,   1.0f, 0.0f  // top left

    };
    unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
    };



    ShaderLoader shader(R"(shaders\shader.vert)", R"(shaders\shader.frag)");


    // buffers
    unsigned int VBO, VAO, EBO;
    // bind VAO & VBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &EBO);
    // bring square vertices into the buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(square), square, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) nullptr);
    glEnableVertexAttribArray(0);
    // color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // Texture coord
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    Texture texture(R"(guy.png)");

    while(!glfwWindowShouldClose(window)) {
        keyPressed(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindTexture(GL_TEXTURE_2D, texture.aTexture);

        shader.useShaderProgram();

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

void keyPressed(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
