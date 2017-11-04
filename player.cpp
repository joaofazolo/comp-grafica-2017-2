#include "player.h"

#define PI 3.1415926535897932384626433832795



Player::Player(float cx, float cy,float radius,float color[3]) : Circle(cx,cy,radius,color){
  this->color[0] = color[0];
  this->color[1] = color[1];
  this->color[2] = color[2];
  this->oldRadius = radius;
  this->radius = radius;
  this->isJumping = 0;
  this->theta = 0;
  this->thetaArm = 0;
  //this->colider = NULL;
  //this->colider = new Circle(0,0,radius,color);
  //this->colider;
}

void Player::draw(){
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(this->cx,1000-this->cy,0);
  glRotatef(this->theta,0,0,1);

  float black[3] = {0,0,0};
  float green[3] = {0,1,0};

  //Circle::drawCircle();
  Circle* arms = new Circle(0,0,this->radius,this->radius/4.5,this->color);
  Circle* head = new Circle(0,0,this->radius/1.8,color);
  Rectangle* leftLeg = new Rectangle(0,0,6,20,black);
  Rectangle* rightLeg = new Rectangle(0,0,6,20,black);
  Rectangle* arm = new Rectangle(0,0,5,20,green);

  glPushMatrix();
    glTranslatef(-this->radius/3,0,0);
    leftLeg->draw();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(this->radius/3,0,0);  
    glRotatef(180,0,0,1);
    rightLeg->draw();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(this->radius,0,0);
    glRotatef(this->thetaArm,0,0,1);    
    arm->draw();
  glPopMatrix();
  
  arms->drawCircle(1);
  arms->drawCircle(0);
  head->drawCircle(1);
  head->drawCircle(0);
  glPopMatrix();

}

void Player::jump(){
  if(this->isJumping)
    return;
  this->isJumping = 1;
  while(this->radius!=this->oldRadius*2){
    this->radius+=0.2;

  }
}

void Player::moveX(float ds){
  this->cx += ds;
}

void Player::moveY(float ds){
  this->cy += ds;
}

int Player::playerColision(Circle* cir){
  return this->colisao(cir);
}

int Player::isInside(Circle* cir){
  return this->inside(cir);
}

void Player::rotate(float ds){
  this->theta+=ds;
}

void Player::move(float ds){
  this->cy+=ds*cos(this->theta*PI/180);
  this->cx+=ds*sin(this->theta*PI/180);
}

void Player::rotateArm(float x, float y){
  cout << x << " , " << cx << endl;
  if(x+200>cx)
    thetaArm-=1;
  else thetaArm+=1;
  if(thetaArm>45)
    thetaArm-=1;
  if(thetaArm<-45)
    thetaArm+=1;
}
