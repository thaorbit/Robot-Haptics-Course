#include "Material.h"

using namespace glm;

Material::Material(vec3 amb, vec3 diff, vec3 spec, float shine) {
    ambient = amb;
    diffuse = diff;
    specular = spec;
    shininess = shine;
}

void Material::sendToShader(Shader& shader) {
    shader.setVec3("m_ambient", ambient);
    shader.setVec3("m_diffuse", diffuse);
    shader.setVec3("m_specular", specular);
    shader.setFloat("shininess", shininess);
}