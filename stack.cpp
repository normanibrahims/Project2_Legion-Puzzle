#include"stack.h"

void SetTop(Stack *S, Stack NewTop){
	
	*S = NewTop; 
	
}

void CreateEmpty(Stack *S){
	
	*S = NULL;
	
}

boolean IsEmpty(Stack S){
	
	if(S == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void Create_Stack (Stack *p){
	
	*p = (Stack)malloc(sizeof(StackList));
	if(p != NULL){
		//printf("Alokasi Berhasil dengan Alamat : %p.\n",*p);
	}else{
		printf("Gagal Alokasi\n");
	}
	
}

void Isi_Stack (Stack *p , arrowtype nilai){
	
	if(IsEmpty(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		(*p)->next = NULL;
		(*p)->data.move = nilai.move;
		(*p)->data.reverse = nilai.reverse;
	}
	
}

void Ins_Stack (Stack *p, Stack PNew){
	
	(PNew)->next = *p;
	*p = PNew;
}

void Push(Stack *S,arrowtype X){
	
	Stack a = NULL;
	
	Create_Stack(&a);
	Isi_Stack(&a, X);
	Ins_Stack(&(*S),a);
	
}

void Del_Stack (Stack * p, arrowtype * X){
	
	Stack A,B;
	if(IsEmpty(*p)){
		printf("List Kosong");
	}else{
		A = *p;
		(*X)=(A)->data;
//		(*X).bawah = (A)->data.bawah;
//		(*X).atas = (A)->data.atas;
//		(*X).kanan = (A)->data.kanan;
//		(*X).kiri = (A)->data.kiri;
//		(*X).initpos = (A)->data.initpos;
		*p = (*p)->next;
		(A)->next = NULL;
		free(A);
	}
//	A = *p;
//	if(IsEmpty(*p)){
//		printf("List Kosong");
//	}else if((*p)->next == NULL){
//		*p = NULL;
//		free(A);
//	}else{
//		while((A)->next->next != NULL){
//			A = A->next;
//		}
//		B = A->next;
//		A->next = NULL;
//		*X = (B)->data;
//		free(B);
//	}
}

void Pop(Stack *S,arrowtype *X){
	
	Del_Stack(&(*S),&(*X));
	
}

void Tampil_Stack(Stack top)
{
	Stack p;
	p=top;
	if(IsEmpty(top)){
		printf("List Kosong\n");
	}
	else{		
		while(!IsEmpty(p)){
			
			printf("%d %d", p->data.move,p->data.reverse);
			p = (p)->next;
			if(p != NULL){
				printf("->");
			}
			
		}
		printf("\n");
	}
}

Stack BalikStack (Stack p){
	
	Stack NodeAfter = NULL; Stack NodeBefore= NULL;
	
	while(p != NULL){
		
		NodeAfter = p->next;
		p->next = NodeBefore;
		NodeBefore = p;
		p = NodeAfter;
		
	}
	
	return NodeBefore;
	
}
