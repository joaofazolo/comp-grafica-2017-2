#include <GL/glut.h>
#include "tinyxml2.h"
#include "circle.h"
#include "player.h"
#include <string>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>

using namespace tinyxml2;
using namespace std;

int keyboard[256] = {0};



void LeXML(string nomeArq);
//colors setup
float blue[] = {0,0,1};
float white[] = {1,1,1};
float red[] = {1,0,0};
float green[] = {0,1,0};
float black[] = {0,0,0};
map<const char*,float*> colorMap{
  {"blue",blue},
  {"white",white},
  {"red",red},
  {"black",black},
  {"green",green}
};

//circles
Circle* outer = nullptr;
Circle* inner = nullptr;
vector<Circle*> enemies;
vector<Circle*> obstacles;
//Circle* player = nullptr;
Player* player = nullptr;




//incrementos
float ds = 0.1;
float dtheta = 1;
float velPlayer;
float velTiro;

void init(void) {
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(outer->getcX()-outer->getRadius(), outer->getcX()+outer->getRadius(), outer->getcY()-outer->getRadius(), outer->getcY()+outer->getRadius(), -1.0, 1.0);
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  //if(outer!=nullptr)
  outer->draw(1);
  inner->draw(1);
  for(aux : enemies){
    aux->draw(1);
  }
  for(aux : obstacles){
    aux->draw(1);
  }
  player->draw();
  //teste->Draw();

  //glutSwapBuffers();
  glFlush();
}

void keyDown(unsigned char key, int x, int y){
  keyboard[key] = 1;
}

void keyUp(unsigned char key, int x, int y){
  keyboard[key] = 0;
}

void stopJumping(int nada){
  while(player->radius!=player->oldRadius){
    player->radius-=0.1;
  }
  player->isJumping = 0;
}

void idle(){
  if(keyboard['a']){/*
    player->moveX(-ds);
    if(player->colisao(inner)){
      player->moveX(ds);
      return;
    }
    if(!player->isInside(outer)){
      player->moveX(ds);
    }
    for(enemie : enemies){
      if(player->colisao(enemie))
      player->moveX(ds);
    }
    for(obstacle : obstacles){
      if(player->colisao(obstacle))
      player->moveX(ds);
    }
    */
    player->rotate(dtheta);

  }
  if(keyboard['d']){
    player->moveX(ds);
    if(player->colisao(inner)){
      player->moveX(-ds);
      return;
    }
    if(!player->isInside(outer)){
      player->moveX(-ds);
    }
    for(enemie : enemies){
      if(player->colisao(enemie))
      player->moveX(-ds);
    }
    for(obstacle : obstacles){
      if(player->colisao(obstacle))
      player->moveX(-ds);
    }
  }
  if(keyboard['w']){
    //player->moveY(-ds);
    player->move(ds);
    if(player->colisao(inner)){
      player->moveY(ds);
      return;
    }
    if(!player->isInside(outer)){
      player->moveY(ds);
    }
    for(enemie : enemies){
      if(player->colisao(enemie))
      player->moveY(ds);
    }
    for(obstacle : obstacles){
      if(player->colisao(obstacle))
      player->moveY(ds);
    }
  }
  if(keyboard['s']){
    player->moveY(ds);
    if(player->colisao(inner)){
      player->moveY(-ds);
      return;
    }
    if(!player->isInside(outer)){
      player->moveY(-ds);
    }
    for(enemie : enemies){
      if(player->colisao(enemie))
      player->moveY(-ds);
    }
    for(obstacle : obstacles){
      if(player->colisao(obstacle))
      player->moveY(-ds);
    }
  }
  if(keyboard['p']){
    if(player->isJumping)
      return;
    player->jump();
    glutTimerFunc(1000,stopJumping,0);
  }
  glutPostRedisplay();
}

int main(int argc, char** argv) {
    //Ler config
    XMLDocument config;
    config.LoadFile(argv[1]);
    string strArena;

    //Le arquivo de configuraçoes
    strArena = string(config.FirstChildElement("aplicacao")->FirstChildElement("arquivoDaArena")->Attribute("caminho"))+
    string(config.FirstChildElement("aplicacao")->FirstChildElement("arquivoDaArena")->Attribute("nome"))+"."+
    string(config.FirstChildElement("aplicacao")->FirstChildElement("arquivoDaArena")->Attribute("tipo"));

    //Le configuraçoes do jogador
    XMLElement* nodePlayer = config.FirstChildElement("aplicacao")->FirstChildElement("jogador");
    velPlayer = nodePlayer->FloatAttribute("vel");
    velTiro = nodePlayer->FloatAttribute("velTiro");

    //Le configuracoes da arena
    LeXML(strArena);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(outer->getRadius()*2, outer->getRadius()*2);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("teste");
    init();
    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);

    glutIdleFunc(idle);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;

}

void LeXML(string nomeArq){
  XMLDocument arena;
  arena.LoadFile(nomeArq.c_str());
  XMLElement* svg = arena.FirstChildElement("svg");
  XMLElement* aux;
  for(aux = svg->FirstChildElement("circle");aux!=nullptr;aux = aux->NextSiblingElement()){
    if(strcmp(aux->Attribute("fill"),("blue")) == 0){
      outer = new Circle(aux->FloatAttribute("cx"),aux->FloatAttribute("cy"),aux->FloatAttribute("r"),colorMap["blue"]);
    }
    if(strcmp(aux->Attribute("fill"),("white")) == 0){
      inner = new Circle(aux->FloatAttribute("cx"),aux->FloatAttribute("cy"),aux->FloatAttribute("r"),colorMap["white"]);
    }
    if(strcmp(aux->Attribute("fill"),("red")) == 0){
       enemies.push_back(new Circle(aux->FloatAttribute("cx"),aux->FloatAttribute("cy"),aux->FloatAttribute("r"),colorMap["red"]));
    }
    if(strcmp(aux->Attribute("fill"),("black")) == 0){
      obstacles.push_back(new Circle(aux->FloatAttribute("cx"),aux->FloatAttribute("cy"),aux->FloatAttribute("r"),colorMap["black"]));
    }
    if(strcmp(aux->Attribute("fill"),("green")) == 0){
      player = new Player(aux->FloatAttribute("cx"),aux->FloatAttribute("cy"),aux->FloatAttribute("r"),colorMap["green"]);
    }

  }
}
