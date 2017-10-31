#include "circle.h"
#include <math.h>
#include <stdio.h>
#include <ctime>

#define PI 3.1415926535897932384626433832795

Circle::Circle(){};

Circle::Circle(float cx,float cy,float radius, float color[3]){
    this->cx = cx;
    this->cy = cy;
    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];
    this->radius1 = radius;
    this->radius2 = radius;
}

Circle::Circle(float cx,float cy,float radius1, float radius2, float color[3]){
    this->cx = cx;
    this->cy = cy;
    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];
    this->radius1 = radius1;
    this->radius2 = radius2;
}

void Circle::setRadius(float radius){
    this->radius1 = radius1;
}

void Circle::setColors(float* colors){
    this->color[0] = colors[0];
    this->color[1] = colors[1];
    this->color[2] = colors[2];
    printf("%.2f,%.2f,%.2f\n",colors[0],colors[1],colors[2]);
}

void Circle::drawCircle(int type){
    //All triangles fan out starting with this point
    if(type){
        glColor3d(this->color[0],this->color[1],this->color[2]);
        glBegin(GL_TRIANGLE_FAN);
    }
    else{
        glColor3d(0,0,0);
        glLineWidth(3); 
        glBegin(GL_LINE_LOOP);
    }
    //glVertex3f(cx/600,cy/600,0.0);
    //printf("centro: (%f,%f)\n",cx,cy);
    int nSides = 100;
    float x,y;
    int nVertex = nSides + 2;
    for (int i = 0; i < nVertex; i++ )
    {
        x = radius1*cos(i*2.0*PI/nSides);
        y = radius2*sin(i*2.0*PI/nSides);
        
        glVertex3f(x,y,0.0);
    }
    glEnd();
    
}

void Circle::draw(int type){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(cx,1000-cy,0);
    drawCircle(type);
    glPopMatrix();
    /*
    //All triangles fan out starting with this point
    glMatrixMode(GL_MODELVIEW);
    glColor3d(this->color[0],this->color[1],this->color[2]);
    
    glPushMatrix();
    //cy = 1000-cy;
    glTranslatef(cx,1000-cy,0);
    glBegin(GL_POLYGON);
    //glVertex3f(cx/600,cy/600,0.0);
    //printf("centro: (%f,%f)\n",cx,cy);
    int nSides = 100;
    float x,y;
    int nVertex = nSides + 2;
    for (int i = 0; i < nVertex; i++ )
    {
        x = radius*cos(i*2.0*PI/nSides);
        y = radius*sin(i*2.0*PI/nSides);
        //y = 1000-y;
        glVertex3f(x,y,0.0);
    }
    //printf("cx = %f, cy = %f\n",cx,1000-cy);
    glEnd();
    glPopMatrix();
    //glFlush();
    */
}

void Circle::setc(float x, float y) {
  this->cx = x;
  this->cy = y;
}

float Circle::getRadius(){
    return (this->radius1);
}

float Circle::getcX() {
    return this->cx;
}

float Circle::getcY() {
    return this->cy;
}

void Circle::moveX(float ds){
    this->cx += ds;
}

void Circle::moveY(float ds){
    this->cy += ds;
}

void Circle::jump(){
    this->radius1 += 0.2;
}

int Circle::colisao(Circle* cir){
    float dist = sqrt(pow(this->cx-cir->cx,2)+pow(this->cy-cir->cy,2));
    printf("pow(this->cx-cir->cx,2) = %f\n",pow(this->cx-cir->cx,2));
    if(pow(dist,2)<pow(this->radius1+cir->radius1,2)){
        
        return 1;
    }
    else{
        //printf("%f\n",pow(dist,2)<pow(this->radius+cir->radius,2));
        return 0;
    }
}

int Circle::inside(Circle* cir){
    float dist = sqrt(pow(this->cx-cir->cx,2)+pow(this->cy-cir->cy,2));
    if(dist<cir->radius1-this->radius1)
        return 1;
    return 0;
}
