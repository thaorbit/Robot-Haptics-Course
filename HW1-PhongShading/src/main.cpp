#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Window.h"
#include "Shader.h"
#include "Sphere.h"
#include "Light.h"
#include "Material.h"

using namespace std;
using namespace glm;

const char* vertexShaderSource = R"(
    #version 330 core
    layout(location = 0) in vec3 aPos;
    layout(location = 1) in vec3 aNormal;

    uniform mat4 mvp;
    uniform mat4 model;
    uniform mat3 normalMatrix;

    out vec3 FragPos;
    out vec3 Normal;

    void main() {
        FragPos = vec3(model * vec4(aPos, 1.0));
        Normal = normalMatrix * aNormal;
        gl_Position = mvp * vec4(aPos, 1.0);
    }
)";

const char* fragmentShaderSource = R"(
    #version 330 core

    in vec3 FragPos;
    in vec3 Normal;

    uniform vec3 lightPos;
    uniform vec3 viewPos;
    uniform vec3 s_ambient;
    uniform vec3 s_diffuse;
    uniform vec3 s_specular;

    uniform vec3 m_ambient;
    uniform vec3 m_diffuse;
    uniform vec3 m_specular;
    uniform float shininess;

    out vec4 FragColor;

    void main() {
        vec3 N = normalize(Normal);
        vec3 L = normalize(lightPos - FragPos);
        vec3 V = normalize(viewPos - FragPos);
        vec3 R = reflect(-L, N);

        vec3 c_amb = s_ambient * m_ambient;

        float diff = max(dot(N, L), 0.0);
        vec3 c_diff = diff * s_diffuse * m_diffuse;

        float spec = pow(max(dot(R, V), 0.0), shininess);
        vec3 c_spec = spec * (s_specular * m_specular);

        vec3 result = c_amb + c_diff + c_spec;
        FragColor = vec4(result, 1.0);
    }
)";

int main() {
    Window window(800, 600, "Homework1 - Phong Shading");
    if (!window.isValid()) {
        return -1;
    }

    Shader shader(vertexShaderSource, fragmentShaderSource);
    shader.use();

    Sphere sphere(1.0f, 30, 30);

    mat4 model = mat4(1.0f);
    mat4 projection = perspective(radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    mat4 view = lookAt(vec3(0.0f, 0.0f, 5.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
    mat3 normalMatrix = mat3(transpose(inverse(model)));
    mat4 mvp = projection * view * model;

    shader.setMat4("mvp", mvp);
    shader.setMat4("model", model);
    shader.setMat3("normalMatrix", normalMatrix);

    vec3 cameraPos = vec3(0.0f, 0.0f, 5.0f);

    Light light(
        vec3(5.0f, 5.0f, 5.0f),
        vec3(0.2f, 0.2f, 0.2f),
        vec3(1.0f, 1.0f, 1.0f),
        vec3(1.0f, 1.0f, 1.0f)
    );

    Material material(
        vec3(0.2f, 0.17f, 0.0f),
        vec3(1.0f, 0.85f, 0.0f),
        vec3(1.0f, 1.0f, 1.0f),
        32.0f
    );

    shader.setVec3("viewPos", cameraPos);
    light.sendToShader(shader);
    material.sendToShader(shader);

    while (!window.shouldClose()) {
        glClearColor(0.53f, 0.81f, 0.92f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        sphere.draw();

        window.swapBuffers();
        window.pollEvents();
    }

    sphere.cleanup();
    window.close();
    return 0;
}