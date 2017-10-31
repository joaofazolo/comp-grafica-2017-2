#ifndef _CIRCLE_
#define _CIRCLE_

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Circle{
protected:
    int isJumping;
    float radius1;
    float radius2;
    float color[3];
    float cx;
    float cy;

public:
    Circle();
    Circle(float cx, float cy, float radius, float color[3]);
    Circle(float cx,float cy,float radius1, float radius2, float color[3]);
    void setRadius(float radius);
    void setColors(float* colors);
    void draw(int type);
    void drawCircle(int type);
    void setc(float x, float y);
    float getcX();
    float getcY();
    float getRadius();
    void moveX(float ds);
    void moveY(float ds);
    void jump();
    int colisao(Circle* cir);
    int inside(Circle* cir);
};


#endif
