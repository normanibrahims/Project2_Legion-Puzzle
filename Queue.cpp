/* File : Queue.cpp
   Deskripsi : Body ADT Linked list Queue (Antrian)
   Dibuat oleh : Lisnawati Srisunda
   Tanggal pembuatan : 12-04-2018 */

#include "Queue.h"
//#include "linked.h"

//-------BODY SUB PROGRAM---------
//-------Predikat untuk test keadaan LIST------

boolean isQueueEmpty(address p) //Mengirim true jika List Kosong
{
	isEmpty(p);
}

void Create_Antrian(address *p)
{
	*p=Nil;
}

void CreateQue(address *p,nbAddr nilai)
{
	Create_Node(&(*p));
	if(isEmpty(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		(*p)->data = nilai;
	}
}

void EnQue(address *p,nbAddr nilai)
{
	//Kamus
	address pNew;
	//Algoritma
	CreateQue(&pNew,nilai);
	//printf("%d",info(pNew));
	Ins_Akhir(&(*p),pNew);
}

void DeQue(address * p, nbAddr *nilai)
{
	Del_Awal(&*p,&*nilai);
}

void Tampil_QueueList(address p)
{
	Tampil_List(p);
}
