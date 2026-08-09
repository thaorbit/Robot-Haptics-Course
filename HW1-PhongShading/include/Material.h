#pragma once
#include <glm/glm.hpp>
#include "Shader.h"

using namespace glm;

class Material {
public:
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;

    Material(vec3 amb, vec3 diff, vec3 spec, float shine);

    void sendToShader(Shader& shader);
};