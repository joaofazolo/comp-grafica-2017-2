#include "player.h"

Player::Player(float cx, float cy,float color[3],float radius){
  this->color[0] = color[0];
  this->color[1] = color[1];
  this->color[2] = color[2];
  this->radius = radius;
  this->cx = cx;
  this->cy = cy;
}

void Player::Draw(){
  Circle* body = new Circle(cx,cy,0.8*radius,this->color);
  body->draw();
}
