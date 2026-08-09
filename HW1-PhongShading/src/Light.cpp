#include "Light.h"

using namespace glm;

Light::Light(vec3 pos, vec3 amb, vec3 diff, vec3 spec) {
    position = pos;
    ambient = amb;
    diffuse = diff;
    specular = spec;
}

void Light::sendToShader(Shader& shader) {
    shader.setVec3("lightPos", position);
    shader.setVec3("s_ambient", ambient);
    shader.setVec3("s_diffuse", diffuse);
    shader.setVec3("s_specular", specular);
}