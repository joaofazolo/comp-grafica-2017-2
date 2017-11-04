#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Rectangle{
public:
    float cx, cy, sidex,sidey, color[3], theta;

public:
    Rectangle(float cx, float cy, float sidex, float sidey, float color[3]);
    void draw();
};

#endif