#include "Shader.h"
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const char* vertexSource, const char* fragmentSource) {
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
    glCompileShader(fragmentShader);

    programID = glCreateProgram();
    glAttachShader(programID, vertexShader);
    glAttachShader(programID, fragmentShader);
    glLinkProgram(programID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::use() {
    glUseProgram(programID);
}

void Shader::setMat4(const char* name, const glm::mat4& value) {
    GLint loc = glGetUniformLocation(programID, name);
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::setMat3(const char* name, const glm::mat3& value) {
    GLint loc = glGetUniformLocation(programID, name);
    glUniformMatrix3fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::setVec3(const char* name, const glm::vec3& value) {
    GLint loc = glGetUniformLocation(programID, name);
    glUniform3fv(loc, 1, glm::value_ptr(value));
}

void Shader::setFloat(const char* name, float value) {
    GLint loc = glGetUniformLocation(programID, name);
    glUniform1f(loc, value);
}