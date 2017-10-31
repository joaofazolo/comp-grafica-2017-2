#ifndef PLAYER_H_
#define PLAYER_H_
#include "circle.h"

class Player{
private:
  float color[3];
  float radius,cx,cy;


public:
  Player(float cx, float cy,float color[3],float radius);
  void Draw();

};


#endif
