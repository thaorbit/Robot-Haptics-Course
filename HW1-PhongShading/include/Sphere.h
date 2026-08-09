#pragma once
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

struct Vertex {
    float x, y, z;
    float nx, ny, nz;
};

class Sphere {
public:
    vector<Vertex> vertices;
    vector<unsigned int> indices;

    GLuint VAO, VBO, EBO;

    Sphere(float radius, unsigned int stacks, unsigned int slices);

    void buildGeometry(float radius, unsigned int stacks, unsigned int slices);
    void setupBuffers();
    void draw();
    void cleanup();
};