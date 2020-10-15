/*
File	: nbtree_d.h
Author	: SN
Last Updt : 25-5-2011
*/

#ifndef nbtree_d_H
#define nbtree_d_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "nbtree_d.h"
//#include "Queue.h"

typedef struct{
	boolean atas,bawah,kiri,kanan;
	int move,reverse;
}nbType;

typedef struct nbTreeNode *nbAddr;

typedef struct nbTreeNode{
	nbAddr fs; //First child
	nbAddr nb; //Next brother
	nbAddr parent;
	nbType data;
}ElmtTree;

//struct nbTree{
//	nbAddr root;
//};

/* ---------------- Konstruktor Tree ---------------- */
void nbCreate(nbAddr *x);
//Membuat tree kosong (X.root=NULL)

/* ---------------- Alokasi node baru Tree ---------------- */
nbAddr nbCNode(nbType X);
//Alokasi untuk membuat node baru

/* ---------------- Operasi-operasi Tree ---------------- */
nbAddr nbInsert(nbAddr *tRoot, nbAddr parent, nbType X);
// Menambah element pada node parent

nbAddr nbSearch(nbAddr root, nbType src);
// Mencari node dengan info ttn dan mengembalikan addressnya

void nbUpgrade(nbAddr *root);
// Mengupgrade parent dari beberapa node. (digunakan pada proses penghapusan)

void nbDelete(nbAddr *pDel, nbAddr *pTree);
// Menghapus node tertentu dan digantikan oleh fs dari node tsb

int nbDepth(nbAddr root);
// Mengukur kedalaman suatu node dari root


/* ---------------- TRAVERSAL Tree ---------------- */
void nbPost(nbAddr root); // Postorder traversing
void nbPre(nbAddr root); // Preorder traversing
//void nbIn(nbAddr root); // Inorder traversing
void nbLevelOrder(nbAddr root,int curLevel, int desLevel); // Levelorder traversing

/* ---------------- PRINT TREE ---------------- */
void nbPrint(nbAddr node, char tab[]);

#endif
