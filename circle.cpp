#include "circle.h"
#include <math.h>
#include <stdio.h>
#include <ctime>

#define PI 3.1415926535897932384626433832795

Circle::Circle(){};

Circle::Circle(float centerx,float centery,float radius, float color[3]){
    this->centerx = centerx;
    this->centery = centery;
    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];
    this->radius = radius;
}

void Circle::setRadius(float radius){
    this->radius = radius;
}

void Circle::setColors(float* colors){
    this->color[0] = colors[0];
    this->color[1] = colors[1];
    this->color[2] = colors[2];
    printf("%.2f,%.2f,%.2f\n",colors[0],colors[1],colors[2]);
}

void Circle::draw(){
    //All triangles fan out starting with this point
    glBegin(GL_POLYGON);
    //glVertex3f(centerx/600,centery/600,0.0);
    //printf("centro: (%f,%f)\n",centerx,centery);
    glColor3d(this->color[0],this->color[1],this->color[2]);
    int nSides = 100;
    float x,y;
    int nVertex = nSides + 2;
    for (int i = 0; i < nVertex; i++ )
    {
        x = centerx+radius*cos(i*2.0*PI/nSides);
        y = centery+radius*sin(i*2.0*PI/nSides);
        y = 1000-y;
        glVertex3f(x,y,0.0);
    }
    glEnd();
    //glFlush();
}

void Circle::setCenter(float x, float y) {
  this->centerx = x;
  this->centery = y;
}

float Circle::getRadius(){
    return (this->radius);
}

float Circle::getCenterX() {
    return this->centerx;
}

float Circle::getCenterY() {
    return this->centery;
}

void Circle::moveX(float ds){
    this->centerx += ds;
}

void Circle::moveY(float ds){
    this->centery += ds;
}

void Circle::jump(){
    this->radius += 0.2;
}

int Circle::colisao(Circle* cir){
    float dist = sqrt(pow(this->centerx-cir->centerx,2)+pow(this->centery-cir->centery,2));
    if(pow(dist,2)<pow(this->radius+cir->radius,2))
        return 1;
    return 0;
}

int Circle::inside(Circle* cir){
    float dist = sqrt(pow(this->centerx-cir->centerx,2)+pow(this->centery-cir->centery,2));
    if(dist<cir->radius-this->radius)
        return 1;
    return 0;
}
