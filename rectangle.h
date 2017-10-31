#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Rectangle{
    float cx, cy, sidex,sidey;

public:
    Rectangle(float cx, float cy, float sidex, float sidey);
    void draw();
};

#endif