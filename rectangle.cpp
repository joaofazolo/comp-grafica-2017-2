#include "rectangle.h"

Rectangle::Rectangle(float cx,float cy,float sidex,float sidey, float color[3]){
    this->cx = cx;
    this->cy = cy;
    this->sidex = sidex;
    this->sidey = sidey;
    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];
    this->theta = 0;
}

void Rectangle::draw(){
    glMatrixMode(GL_MODELVIEW);
    glColor3f(color[0],color[1],color[2]);
    glBegin(GL_POLYGON);
        glVertex3f(sidex/2,0,0);
        glVertex3f(sidex/2,sidey,0);
        glVertex3f(-sidex/2,sidey,0);
        glVertex3f(-sidex/2,0,0);
    glEnd();
}