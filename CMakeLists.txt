include(FetchContent)
cmake_minimum_required(VERSION 3.21)

project("ProjectBahamut")

# find dependencies
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/lib/cmake/")

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

set(SOURCE_FILES SpriteRenderer.cpp GameObject.cpp ShaderLoader.cpp window.cpp Texture.cpp )
set(HEADER_FILES SpriteRenderer.h GameObject.h ShaderLoader.h lib/glad.c Texture.h window.h camera.h Player.cpp Player.h Game.cpp Game.h EngineGUI.cpp EngineGUI.h)








add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES} )

find_package(OpenGL REQUIRED)

# glfw3
find_package(glfw3 REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw)



# stb
link_libraries(STB_IMAGE lib/stb_image.h)
# imgui
list(APPEND sources
        lib/imgui/imgui.cpp
        lib/imgui/imgui_stdlib.cpp
        lib/imgui/imgui_draw.cpp
        lib/imgui/imgui_tables.cpp
        lib/imgui/imgui_widgets.cpp
        lib/imgui/imgui_impl_glfw.cpp
        lib/imgui/imgui_impl_opengl3.cpp
        lib/imgui/imgui_demo.cpp
        )
target_sources(${PROJECT_NAME} PRIVATE ${sources})


