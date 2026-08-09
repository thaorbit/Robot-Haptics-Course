#include "Sphere.h"
#include <cmath>

Sphere::Sphere(float radius, unsigned int stacks, unsigned int slices) {
    buildGeometry(radius, stacks, slices);
    setupBuffers();
}

void Sphere::buildGeometry(float radius, unsigned int stacks, unsigned int slices) {
    vertices.clear();
    indices.clear();

    for (unsigned int i = 0; i <= stacks; ++i) {
        float theta = i * M_PI / stacks;
        float sinTheta = sin(theta);
        float cosTheta = cos(theta);

        for (unsigned int j = 0; j < slices; ++j) {
            float phi = j * 2.0f * M_PI / slices;
            float sinPhi = sin(phi);
            float cosPhi = cos(phi);

            Vertex v;
            v.x = radius * sinTheta * cosPhi;
            v.y = radius * cosTheta;
            v.z = radius * sinTheta * sinPhi;

            v.nx = v.x / radius;
            v.ny = v.y / radius;
            v.nz = v.z / radius;

            vertices.push_back(v);
        }
    }

    for (unsigned int i = 0; i < stacks; ++i) {
        for (unsigned int j = 0; j < slices; ++j) {
            unsigned int j_next = (j + 1) % slices;

            unsigned int idx00 = i * slices + j;
            unsigned int idx10 = (i + 1) * slices + j;
            unsigned int idx01 = i * slices + j_next;
            unsigned int idx11 = (i + 1) * slices + j_next;

            indices.push_back(idx00);
            indices.push_back(idx10);
            indices.push_back(idx01);

            indices.push_back(idx10);
            indices.push_back(idx11);
            indices.push_back(idx01);
        }
    }
}

void Sphere::setupBuffers() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void Sphere::draw() {
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0);
}

void Sphere::cleanup() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}