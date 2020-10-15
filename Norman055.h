#ifndef Norman055_H
#define Norman055_H
#include "graphics.h"
#include "Bagas039.h"
#include "Lisna047.h"
//#include "Annisa037.h"

//typedef PuzzleController PuzzleController;
typedef struct
{
	int x, y;
}point;

void Player();
void Player1();
//void Player2();
//void InputPlayer2();
void SettingGame(char nama[]);
int Easy();
int Medium();
int Hard();
int Lima();
int Sepuluh();
int Unlimited();
void tkte();
void tktm();
void tkth();
void eke();
void Start();
void Custom();
void Menu();
void StartPlayGame();

#endif
