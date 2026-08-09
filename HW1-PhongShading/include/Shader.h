#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>

using namespace glm;

class Shader {
public:
    GLuint programID;

    Shader(const char* vertexSource, const char* fragmentSource);

    void use();
    void setMat4(const char* name, const mat4& value);
    void setMat3(const char* name, const mat3& value);
    void setVec3(const char* name, const vec3& value);
    void setFloat(const char* name, float value);
};