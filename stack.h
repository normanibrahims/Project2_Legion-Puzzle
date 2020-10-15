#ifndef stach_H
#define stack_H
#include <malloc.h>
#include <stdio.h>
#include "boolean.h"
//#include"linked.h"
typedef struct{
	int move,reverse;
}arrowtype;
typedef struct StElmtList *Stack;
typedef struct StElmtList {
arrowtype data;
Stack next;
} StackList;
//typedef address Stack;

void SetTop(Stack *S, Stack NewTop);

void CreateEmpty(Stack *S);

boolean IsEmpty(Stack S);

void Push(Stack *S,arrowtype X);

void Pop(Stack *S,arrowtype *X);

void Tampil_Stack(Stack top);

Stack BalikStack(Stack p);

#endif
