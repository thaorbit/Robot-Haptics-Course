#pragma once
#include <glm/glm.hpp>
#include "Shader.h"

using namespace glm;

class Light {
public:
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    Light(vec3 pos, vec3 amb, vec3 diff, vec3 spec);

    void sendToShader(Shader& shader);
};