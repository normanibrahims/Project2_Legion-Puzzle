/* File : Queue.h */
/* Deskripsi : ADT linked list dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* InfoType adalah integer */
/* Dibuat oleh : Lisnawati Srisunda */

#ifndef Queue_H
#define Queue_H

#include <stdio.h>
#include <limits.h>
#include <malloc.h>
#include "linked.h"
#include "boolean.h"
//#include "nbtree_d.h"

#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

//typedef infotype infotype;
//typedef struct tElmtList *address;
//typedef struct tElmtList {
//	infotype data;
//	address next;
//}ElmtList;
//typedef nbAddr address;

boolean isQueueEmpty(address p);
void Create_Antrian(address *p);
void CreateQue(address *p,nbAddr nilai);
void EnQue(address *p,nbAddr nilai);
void DeQue(address * p, nbAddr *nilai);
void Tampil_QueueList(address p);

#endif
