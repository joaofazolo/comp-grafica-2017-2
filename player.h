#ifndef PLAYER_H_
#define PLAYER_H_

#include <unistd.h>
#include <iostream>
#include "circle.h"
#include "math.h"

using namespace std;

class Player : public Circle{
private:
  float color[3];
  
 

public:
  Player(float cx, float cy,float radius,float color[3]);
  void draw();
  void jump();
  void moveX(float ds);
  void moveY(float ds);
  int playerColision(Circle* cir);
  int isInside(Circle* cir);
  int isJumping;
  float oldRadius;
  float radius;
  float theta;
  void rotate(float ds);
  void move(float ds);
};


#endif
