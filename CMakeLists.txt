cmake_minimum_required(VERSION 3.21)

project("ProjectBahamut")

# find dependencies
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
#set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/build/")

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES SpriteRenderer.cpp GameObject.cpp ShaderLoader.cpp window.cpp Texture.cpp )
set(HEADER_FILES SpriteRenderer.h GameObject.h ShaderLoader.h Texture.h window.h camera.h Game.cpp Game.h EngineGUI.cpp EngineGUI.h Mesh.h Mesh.cpp Model.cpp Model.h)
set(HEADER_FILES SpriteRenderer.h GameObject.h ShaderLoader.h Texture.h window.h camera.h Game.cpp Game.h EngineGUI.cpp EngineGUI.h Terrain.cpp Terrain.h Model.cpp Mesh.cpp)






add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES} )


find_package(OpenGL REQUIRED)

# glfw3
find_package(glfw3 REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw)

# glad
find_package(glad REQUIRED)
target_link_libraries(${PROJECT_NAME} glad::glad)

# glm
find_package(glm REQUIRED)
target_link_libraries(${PROJECT_NAME} glm::glm)

# assimp
find_package(assimp REQUIRED)
target_link_libraries(${PROJECT_NAME} assimp::assimp)

# stb
find_package(stb REQUIRED)
target_link_libraries(${PROJECT_NAME} stb::stb)

# imgui
find_package(imgui REQUIRED)
target_link_libraries(${PROJECT_NAME} imgui::imgui)

list(APPEND sources
        lib/imgui_impl_glfw.cpp
        lib/imgui_impl_opengl3.cpp
        lib/imgui_demo.cpp
        )
target_sources(${PROJECT_NAME} PRIVATE ${sources})


