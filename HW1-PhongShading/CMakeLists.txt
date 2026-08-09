cmake_minimum_required(VERSION 3.14)
project(HW1_PhongShader LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# 1. GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    glfw
    URL https://github.com/glfw/glfw/archive/refs/tags/3.4.zip
)
FetchContent_MakeAvailable(glfw)

# 2. GLAD (use the repository's local generated loader)
add_library(glad STATIC
    src/glad.c
)
target_include_directories(glad PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(glad PUBLIC OpenGL::GL)

# 3. GLM
FetchContent_Declare(
    glm
    URL https://github.com/g-truc/glm/archive/refs/tags/1.0.1.zip
)
FetchContent_MakeAvailable(glm)

# 4. OpenGL
find_package(OpenGL REQUIRED)

# 5. Target executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Window.cpp
    src/Shader.cpp
    src/Sphere.cpp
    src/Light.cpp
    src/Material.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        glfw
        glad
        OpenGL::GL
)