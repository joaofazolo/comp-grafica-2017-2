#ifndef _CIRCLE_
#define _CIRCLE_

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Circle{
protected:
    int isJumping = 0;
    float radius;
    float color[3];
    float centerx;
    float centery;

public:
    Circle();
    Circle(float centerx, float centery, float radius, float color[3]);
    void setRadius(float radius);
    void setColors(float* colors);
    void draw();
    void setCenter(float x, float y);
    float getCenterX();
    float getCenterY();
    float getRadius();
    void moveX(float ds);
    void moveY(float ds);
    void jump();
    int colisao(Circle* cir);
    int inside(Circle* cir);
};


#endif
