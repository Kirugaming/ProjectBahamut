include(FetchContent)
cmake_minimum_required(VERSION 3.21)

project("ProjectBahamut")

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

find_package( OpenGL REQUIRED )

set(SOURCE_FILES SpriteRenderer.cpp GameObject.cpp ShaderLoader.cpp window.cpp Texture.cpp )
set(HEADER_FILES SpriteRenderer.h GameObject.h ShaderLoader.h stb_image.h Texture.h window.h camera.h Game.cpp Game.h Scene.cpp Scene.h Player.cpp Player.h)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.3.8
)
FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 0.9.9.8
)

FetchContent_MakeAvailable(glfw glm)
add_subdirectory(glad/)


add_executable(${PROJECT_NAME} glfw ${SOURCE_FILES} ${HEADER_FILES} )
target_link_libraries(${PROJECT_NAME} glfw glad glm)