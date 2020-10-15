#ifndef Lisna047_H
#define Lisna047_H
#include "boolean.h"
#include "graphics.h"
#include "nbtree_d.h"
#include "linked.h"
#include "Queue.h"
#include "stack.h"
//#include "Annisa037.h"
#include "Bagas039.h"
#include "Norman055.h"
#include <conio.h>
#include <time.h>

#define puzzle1 1
#define puzzle2 2
#define puzzle3 3
#define puzzle4 4
#define puzzle5 5
#define puzzle6 6
#define puzzle7 7
#define puzzle8 8
#define blank 9

#define unlimited 1
#define lima 2
#define sepuluh 3

#define easy 1
#define medium 2
#define hard 3

#define ERR_NO_NUM -1
#define ERR_NO_MEM -2

#define GRIDSIZE 150

#define keyUp 0x048
#define keyDown 0x050
#define keyLeft 0x04b
#define keyRight 0x04d

#define Atas 1
#define Bawah 2
#define Kanan 3
#define Kiri 4

#define Depth 10
#define fieldSize 3

typedef nbType infotype;
typedef struct{
	int x;
	int y;
}position;

typedef struct{
		int detik;
		int menit;
		int jam;
}waktu;

typedef struct{
	nbAddr root;
	address front;
	Stack stack;
}PuzzleTree;

typedef struct{
	int move;
	waktu timer;
	position initpos;
}GameControl;

typedef struct{
		char player1[10];
		char player2[10];
		int level;
		int leveltime;
		int movescore;
		waktu timescore;
}PuzzleController;

void InitPuzzle(int solvepuzzle[]);
position SearchInitpos();
void TampilanPlayGame(int level);
waktu Timer(int leveltime,waktu timer);
void DrawPuzzle(int level,int img);
void DrawPuzzleEasy(int puzzle);
void DrawPuzzleMedium(int puzzle);
void DrawPuzzleHard(int puzzle);
int SearchPosX(int img);
int SearchPosY(int img);
GameControl Controller(GameControl gm,int level,Stack *stack);
GameControl Move(int arah,position initpos);
boolean CheckPuzzle();
void Pause(int level);
void Solve(Stack *head,int level,GameControl game);

void PlayGame(PuzzleController player);

#endif
