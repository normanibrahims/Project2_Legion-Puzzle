#ifndef Annisa037_H
#define Annisa037_H

#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <malloc.h>
#include <string.h>

#define easy 1
#define medium 2
#define hard 3
#define MAX 50

//typedef struct{
//	int detik;
//	int menit;
//	int jam;
//}waktu;

#include "graphics.h"
#include "Norman055.h"
#include "Bagas039.h"
#include "Lisna047.h"

//typedef waktu waktu;

void EasyScore(int level);
void MediumScore(int level);
void HardScore(int level);
void Click(int *pos,int level);
void Sorting(int *idx,int level);
//void InputScore(int *idx,PuzzleController player);
void MakeListScore(int *idx);
void TampilListScore(int level);
void HighScore(int level);
#endif
