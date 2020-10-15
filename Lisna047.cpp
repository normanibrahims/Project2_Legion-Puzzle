#include "lisna047.h"
int goalpuzzle[fieldSize][fieldSize];
int puzzle[fieldSize][fieldSize];

void InitPuzzle(int solvepuzzle[])
{
	int baris,kolom;
	int k=0;
	for(baris=0;baris<fieldSize;baris++)
	{
		for(kolom=0;kolom<fieldSize;kolom++)
		{
			puzzle[baris][kolom]=solvepuzzle[k];
			goalpuzzle[baris][kolom]=puzzle[baris][kolom];
			k++;
		}
	}
}

position SearchInitpos()
{
	position initpos;
	int b,k;
	for(b=0;b<fieldSize;b++){
			for(k=0;k<fieldSize;k++){
				if(puzzle[b][k]==blank){
					initpos.x=b;
					initpos.y=k;
				}
			}
	}
	
	return (initpos);
}

position SearchPos(infotype arah)
{
	position initpos;
	
	if(arah.atas==true){
		if(arah.bawah==true){
			initpos.x=1;
		}else{
			initpos.x=2;
		}
	}else{
		initpos.x=0;
	}
	
	if(arah.kanan==true){
		if(arah.kiri==true){
			initpos.y=1;
		}else{
			initpos.y=0;
		}
	}else{
		initpos.y=2;
	}
	return(initpos);
}

infotype IndexArah(position initpos)
{
	infotype arah;
	
	if(initpos.x==0) arah.atas=0;
	else{ arah.atas=1; }
	if(initpos.x==2) arah.bawah=0;
	else{ arah.bawah=1; }
	if(initpos.y==0) arah.kiri=0;
	else{ arah.kiri=1; }
	if(initpos.y==2) arah.kanan=0;
	else{ arah.kanan=1; }
	
	return(arah);
}

nbAddr SearchParent(address *front)
{
	nbAddr parent;
	
	//Tampil_QueueList(*front);
	DeQue(&(*front),&parent);
	//printf("\nTampil Front\n");
	//printf("\nSearch %d %d %d %d\n",parent->data.atas,parent->data.bawah,parent->data.kanan,parent->data.kiri);
	return(parent);
}

int Acak_InitPuzzle(int jmlElm)
{
	int init;
	
	init=rand()%jmlElm+1;
	
	return(init);
}

nbAddr Get_InitPuzzle(address front, int choose)
{
	nbAddr get;
	address P;
	int count;
	P=front;
	for(count=0;count<choose;count++){
		P=P->next;
	}
	get=P->data;
	
	return(get);
}

Stack Get_Path(address front,nbAddr tree)
{
	//Kamus
	Stack stack;
	int countchild,acak;
	nbAddr init;
	arrowtype arah;
	
	//Program
	CreateEmpty(&stack);
	
	countchild=NbElmt(front);
	printf("\ncountchild = %d\n",countchild);
	
	srand(time(NULL));
	acak=Acak_InitPuzzle(countchild);
	printf("anak yang terpilih = %d \n",acak);
	
	init=Get_InitPuzzle(front,acak);
	printf("%d %d %d %d\t\t", init->data.atas,init->data.bawah,init->data.kanan,init->data.kiri);
	printf("%d %d\n",init->data.move,init->data.reverse);
	do{
		arah.move=init->data.move;
		arah.reverse=init->data.reverse;
		Push(&stack,arah);
		init=init->parent;
	}while(init!=NULL);
	
	return(stack);
}

PuzzleTree GenerateTree(int kedalaman, position initposparent)
{
	//Kamus
	PuzzleTree gamepuzz;
	int countdepth;
	infotype infochild;
	nbAddr parent,child;
	position initposchild;
	
	//Program
	nbCreate(&gamepuzz.root);
	Create_Antrian(&gamepuzz.front);
	CreateEmpty(&gamepuzz.stack);
	
	infochild=IndexArah(initposparent);
	infochild.move=0; //root
	infochild.reverse=0;
	
	child=nbInsert(&gamepuzz.root,gamepuzz.root,infochild);
	parent=gamepuzz.root;
//	printf("atas %d, bawah %d, kanan %d, kiri %d\t\t",(gamepuzz.root)->data.atas,(gamepuzz.root)->data.bawah,(gamepuzz.root)->data.kanan,(gamepuzz.root)->data.kiri);
//	printf("move %d, reverse %d\n",(gamepuzz.root)->data.move,(gamepuzz.root)->data.reverse);
	countdepth=0;
	while(countdepth<=kedalaman){
		if(parent->data.atas==true){
			initposchild.x=initposparent.x-1;
			initposchild.y=initposparent.y;
			infochild=IndexArah(initposchild);
			infochild.move=Atas; infochild.reverse=Bawah;
			if(parent->parent==NULL){
				child=nbInsert(&gamepuzz.root,parent,infochild);
				EnQue(&gamepuzz.front,child);
			}else if(infochild.atas!=parent->parent->data.atas||infochild.bawah!=parent->parent->data.bawah||infochild.kanan!=parent->parent->data.kanan||infochild.kiri!=parent->parent->data.kiri){
					child=nbInsert(&gamepuzz.root,parent,infochild);
					EnQue(&gamepuzz.front,child);
				}
			}
		
		if(parent->data.bawah==true){
			initposchild.x=initposparent.x+1;
			initposchild.y=initposparent.y;
			infochild=IndexArah(initposchild);
			infochild.move=Bawah; infochild.reverse=Atas;
			if(parent->parent==NULL){
				child=nbInsert(&gamepuzz.root,parent,infochild);
				EnQue(&gamepuzz.front,child);
			}else if(infochild.atas!=parent->parent->data.atas||infochild.bawah!=parent->parent->data.bawah||infochild.kanan!=parent->parent->data.kanan||infochild.kiri!=parent->parent->data.kiri){
					child=nbInsert(&gamepuzz.root,parent,infochild);
					EnQue(&gamepuzz.front,child);
				}
			}
		
		
		if(parent->data.kanan==true){
			initposchild.x=initposparent.x;
			initposchild.y=initposparent.y+1;
			infochild=IndexArah(initposchild);
			infochild.move=Kanan; infochild.reverse=Kiri;
			if(parent->parent==NULL){
				child=nbInsert(&gamepuzz.root,parent,infochild);
				EnQue(&gamepuzz.front,child);
			}else if(infochild.atas!=parent->parent->data.atas||infochild.bawah!=parent->parent->data.bawah||infochild.kanan!=parent->parent->data.kanan||infochild.kiri!=parent->parent->data.kiri){
					child=nbInsert(&gamepuzz.root,parent,infochild);
					EnQue(&gamepuzz.front,child);
				}
			}
		
		
		if(parent->data.kiri==true){
			initposchild.x=initposparent.x;
			initposchild.y=initposparent.y-1;
			infochild=IndexArah(initposchild);
			infochild.move=Kiri; infochild.reverse=Kanan;
			if(parent->parent==NULL){
				child=nbInsert(&gamepuzz.root,parent,infochild);
				EnQue(&gamepuzz.front,child);
			}else if(infochild.atas!=parent->parent->data.atas||infochild.bawah!=parent->parent->data.bawah||infochild.kanan!=parent->parent->data.kanan||infochild.kiri!=parent->parent->data.kiri){
					child=nbInsert(&gamepuzz.root,parent,infochild);
					EnQue(&gamepuzz.front,child);
				}
			}
		
		
		parent=SearchParent(&gamepuzz.front);
		
		initposparent=SearchPos(parent->data);
		printf("\ninitposparent.x = %d ; initposparent.y = %d\n",initposparent.x,initposparent.y);
		countdepth=nbDepth(gamepuzz.root);
		printf("count = %d\n",countdepth);
	}
	gamepuzz.stack=Get_Path(gamepuzz.front,gamepuzz.root);
	
	return(gamepuzz);
}

void MakeInitPuzzle(Stack stack)
{
	Stack P;
	position initpos;
	int arah;
	GameControl game;
	initpos=SearchInitpos();
	P=stack->next;
	while(P!=NULL)
	{
		arah=P->data.move;
		game=Move(arah,initpos);
		P=P->next;
	}
}

void TampilanPlayGame(int level)
{
	//Background
	readimagefile("desain/game/game.bmp",0,0,800,600);
	//Gambar Puzzle Asli
	switch(level){
		case easy: readimagefile("desain/game/gambar easy/gambar easy.bmp",557,93,757,293);
					break;
		case medium: readimagefile("desain/game/gambar medium/gambar medium.jpg",557,93,757,293);
					break;
		case hard: readimagefile("desain/game/gambar hard/gambar hard.jpg",557,93,757,293);
					break;
	}
	//Cursor
	readimagefile("desain/game/arrow atas.bmp",625,410,695,480);
	readimagefile("desain/game/arrow kiri.bmp",549,485,619,555);
	readimagefile("desain/game/arrow bawah.bmp",625,485,695,555);
	readimagefile("desain/game/arrow kanan.bmp",701,485,771,555);
	//TIME&SCORE
	readimagefile("desain/game/time move.bmp",544,303,769,393);
	//Tombol pause
	readimagefile("desain/game/pause.bmp",736,22,781,67);
	//Solve
	readimagefile("desain/game/solve.bmp",549,410,619,480);
}

waktu Timer(int leveltime,waktu timer)
{
	switch(leveltime){
		case unlimited:
			if(timer.detik>=59){
				timer.detik=00;
				timer.menit=timer.menit+1;
			}
			if(timer.menit>=59){
				timer.menit=00;
				timer.jam=timer.jam+1;
			}
			timer.detik=timer.detik+1;
			break;
		case lima:
			if(timer.detik<=0){
				timer.detik=59;
				timer.menit=timer.menit-1;
			}
			timer.detik=timer.detik-1;
			break;
		case sepuluh:
			if(timer.detik<=0){
				timer.detik=59;
				timer.menit=timer.menit-1;
			}
			timer.detik=timer.detik-1;
			break;
	}
	return(timer);
}

void DrawPuzzle(int level,int img)
{
	switch(level){
		case easy : DrawPuzzleEasy(img);
		break;
		case medium : DrawPuzzleMedium(img);
		break;
		case hard : DrawPuzzleHard(img);
		break;
	}
}

void DrawPuzzleEasy(int puzzle)
{
	position pos;
    switch(puzzle){
        case puzzle1 :
		pos.x=SearchPosX(puzzle1);
        pos.y=SearchPosY(puzzle1);
		readimagefile("desain/game/gambar easy/1.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle2 :
		pos.x=SearchPosX(puzzle2);
        pos.y=SearchPosY(puzzle2);
		readimagefile("desain/game/gambar easy/2.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle3 :
		pos.x=SearchPosX(puzzle3);
        pos.y=SearchPosY(puzzle3);
        readimagefile("desain/game/gambar easy/3.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle4 :
		pos.x=SearchPosX(puzzle4);
        pos.y=SearchPosY(puzzle4);
        readimagefile("desain/game/gambar easy/4.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle5 : 
		pos.x=SearchPosX(puzzle5);
        pos.y=SearchPosY(puzzle5);
        readimagefile("desain/game/gambar easy/5.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle6 : 
		pos.x=SearchPosX(puzzle6);
        pos.y=SearchPosY(puzzle6);
        readimagefile("desain/game/gambar easy/6.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle7 : 
		pos.x=SearchPosX(puzzle7);
        pos.y=SearchPosY(puzzle7);
        readimagefile("desain/game/gambar easy/7.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle8 : 
		pos.x=SearchPosX(puzzle8);
        pos.y=SearchPosY(puzzle8);
        readimagefile("desain/game/gambar easy/8.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case blank : 
        pos.x=SearchPosX(blank);
        pos.y=SearchPosY(blank);
		readimagefile("desain/game/gambar easy/x.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
    }
}

void DrawPuzzleMedium(int puzzle)
{
	position pos;
    switch(puzzle){
        case puzzle1 :
		pos.x=SearchPosX(puzzle1);
        pos.y=SearchPosY(puzzle1);
		readimagefile("desain/game/gambar medium/1.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle2 :
		pos.x=SearchPosX(puzzle2);
        pos.y=SearchPosY(puzzle2);
		readimagefile("desain/game/gambar medium/2.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle3 :
		pos.x=SearchPosX(puzzle3);
        pos.y=SearchPosY(puzzle3);
        readimagefile("desain/game/gambar medium/3.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle4 :
		pos.x=SearchPosX(puzzle4);
        pos.y=SearchPosY(puzzle4);
        readimagefile("desain/game/gambar medium/4.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle5 : 
		pos.x=SearchPosX(puzzle5);
        pos.y=SearchPosY(puzzle5);
        readimagefile("desain/game/gambar medium/5.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle6 : 
		pos.x=SearchPosX(puzzle6);
        pos.y=SearchPosY(puzzle6);
        readimagefile("desain/game/gambar medium/6.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle7 : 
		pos.x=SearchPosX(puzzle7);
        pos.y=SearchPosY(puzzle7);
        readimagefile("desain/game/gambar medium/7.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle8 : 
		pos.x=SearchPosX(puzzle8);
        pos.y=SearchPosY(puzzle8);
        readimagefile("desain/game/gambar medium/8.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case blank : 
        pos.x=SearchPosX(blank);
        pos.y=SearchPosY(blank);
		readimagefile("desain/game/gambar medium/x.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
    }
}

void DrawPuzzleHard(int puzzle)
{
	position pos;
    switch(puzzle){
        case puzzle1 :
		pos.x=SearchPosX(puzzle1);
        pos.y=SearchPosY(puzzle1);
		readimagefile("desain/game/gambar hard/1.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle2 :
		pos.x=SearchPosX(puzzle2);
        pos.y=SearchPosY(puzzle2);
		readimagefile("desain/game/gambar hard/2.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle3 :
		pos.x=SearchPosX(puzzle3);
        pos.y=SearchPosY(puzzle3);
        readimagefile("desain/game/gambar hard/3.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle4 :
		pos.x=SearchPosX(puzzle4);
        pos.y=SearchPosY(puzzle4);
        readimagefile("desain/game/gambar hard/4.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle5 : 
		pos.x=SearchPosX(puzzle5);
        pos.y=SearchPosY(puzzle5);
        readimagefile("desain/game/gambar hard/5.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle6 : 
		pos.x=SearchPosX(puzzle6);
        pos.y=SearchPosY(puzzle6);
        readimagefile("desain/game/gambar hard/6.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle7 : 
		pos.x=SearchPosX(puzzle7);
        pos.y=SearchPosY(puzzle7);
        readimagefile("desain/game/gambar hard/7.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle8 : 
		pos.x=SearchPosX(puzzle8);
        pos.y=SearchPosY(puzzle8);
        readimagefile("desain/game/gambar hard/8.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case blank : 
        pos.x=SearchPosX(blank);
        pos.y=SearchPosY(blank);
		readimagefile("desain/game/gambar hard/x.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
    }
}

int SearchPosX(int img)
{
	int found;
	int b,k,kolom;
	found=false;
	while(!found){
		for(b=0;b<5;b++){
			for(k=0;k<5;k++){
				if(img==puzzle[b][k]){
					kolom=k;
					found=true;
				}
			}
		}
	}
	if(kolom==0){
		return (60);
	}else{
		if(kolom==1){
			return (210);
		}else{
			return (360);
		}
	}
}

int SearchPosY(int img)
{
	int found;
	int b,k,baris;
	found=false;
	while(!found){
		for(b=0;b<5;b++){
			for(k=0;k<5;k++){
				if(img==puzzle[b][k]){
					baris=b;
					found=true;
				}
			}
		}
	}
	if(baris==0){
		return (79);
	}else{
		if(baris==1){
			return (229);
		}else{
			return (379);
		}
	}
}

GameControl Controller(GameControl gm,int level,Stack *stack)
{
	GameControl game,sm;
	game=gm;
	char ch;
	arrowtype keys;
	//int sm;
		while(kbhit()){ 
          ch = getch();
           switch(ch)
           {
             case keyUp :
             	keys.move=Atas; keys.reverse=Bawah;
             	Push(&(*stack),keys);
             	readimagefile("desain/game/arrow atas up.bmp",625,410,695,480);
       			delay(100);
       			readimagefile("desain/game/arrow atas.bmp",625,410,695,480);
       			sm=Move(Atas,game.initpos);
       			delay(100);
       			DrawPuzzle(level,blank);
       			DrawPuzzle(level,puzzle[sm.initpos.x+1][sm.initpos.y]);
       			game.initpos.x=sm.initpos.x;
				game.initpos.y=sm.initpos.y;
       			game.move=game.move+sm.move;
       			break;
			 case keyDown : 
			 	keys.move=Bawah; keys.reverse=Atas;
             	Push(&(*stack),keys);
			 	readimagefile("desain/game/arrow bawah up.bmp",625,485,695,555);
        		delay(100);
        		readimagefile("desain/game/arrow bawah.bmp",625,485,695,555);
        		sm=Move(Bawah,game.initpos);
        		delay(100);
        		DrawPuzzle(level,blank);
       			DrawPuzzle(level,puzzle[sm.initpos.x-1][sm.initpos.y]);
        		game.initpos.x=sm.initpos.x;
				game.initpos.y=sm.initpos.y;
       			game.move=game.move+sm.move;
				break;
			 case keyRight :
			 	keys.move=Kanan; keys.reverse=Kiri;
             	Push(&(*stack),keys);
			 	readimagefile("desain/game/arrow kanan up.bmp",701,485,771,555);
				delay(100);
				readimagefile("desain/game/arrow kanan.bmp",701,485,771,555);
				sm=Move(Kanan,game.initpos);
				delay(100);
				DrawPuzzle(level,blank);
       			DrawPuzzle(level,puzzle[sm.initpos.x][sm.initpos.y-1]);
				game.initpos.x=sm.initpos.x;
				game.initpos.y=sm.initpos.y;
       			game.move=game.move+sm.move;
				break;
			 case keyLeft :	
			 	keys.move=Kiri; keys.reverse=Kanan;
             	Push(&(*stack),keys);
				readimagefile("desain/game/arrow kiri up.bmp",549,485,619,555);
				delay(100);
				readimagefile("desain/game/arrow kiri.bmp",549,485,619,555);
				sm=Move(Kiri,game.initpos);
				delay(100);
				DrawPuzzle(level,blank);
       			DrawPuzzle(level,puzzle[sm.initpos.x][sm.initpos.y+1]);
				game.initpos.x=sm.initpos.x;
				game.initpos.y=sm.initpos.y;
       			game.move=game.move+sm.move;
				break;
           }
           
       }
       return(game);
}

GameControl Move(int arah,position initpos)
{
	int temp,b,k;
	GameControl game;
	
	printf("position initpos x %d, y %d\n",initpos.x,initpos.y);
	
	initpos=SearchInitpos();

	switch(arah){
		case Atas:
			if(initpos.x-1!=-1){
				temp=puzzle[initpos.x][initpos.y];
				puzzle[initpos.x][initpos.y]=puzzle[initpos.x-1][initpos.y];
				puzzle[initpos.x-1][initpos.y]=temp;
				initpos.x=initpos.x-1;
				game.initpos.x=initpos.x;
				game.initpos.y=initpos.y;
				game.move=1;
				return(game);
			}else{
				game.initpos.x=initpos.x;
				game.initpos.y=initpos.y;
				game.move=0;
				return(game);
			}
			break;
		case Bawah:
			if(initpos.x+1!=fieldSize){
				temp=puzzle[initpos.x][initpos.y];
				puzzle[initpos.x][initpos.y]=puzzle[initpos.x+1][initpos.y];
				puzzle[initpos.x+1][initpos.y]=temp;
				initpos.x=initpos.x+1;
				game.initpos.x=initpos.x;
				game.initpos.y=initpos.y;
				game.move=1;
				return(game);
			}else{
				game.initpos.x=initpos.x;
				game.initpos.y=initpos.y;
				game.move=0;
				return(game);
			}
			break;
		case Kanan:
			if(initpos.y+1!=fieldSize){
				temp=puzzle[initpos.x][initpos.y];
				puzzle[initpos.x][initpos.y]=puzzle[initpos.x][initpos.y+1];
				puzzle[initpos.x][initpos.y+1]=temp;
				initpos.y=initpos.y+1;
				game.initpos.x=initpos.x;
				game.initpos.y=initpos.y;
				game.move=1;
				return(game);
			}else{
				game.initpos.x=initpos.x;
				game.initpos.y=initpos.y;
				game.move=0;
				return(game);
			}
			break;
		case Kiri:
			if(initpos.y-1!=-1){
				temp=puzzle[initpos.x][initpos.y];
				puzzle[initpos.x][initpos.y]=puzzle[initpos.x][initpos.y-1];
				puzzle[initpos.x][initpos.y-1]=temp;
				initpos.y=initpos.y-1;
				game.initpos.x=initpos.x;
				game.initpos.y=initpos.y;
				game.move=1;
				return(game);
			}else{
				game.initpos.x=initpos.x;
				game.initpos.y=initpos.y;
				game.move=0;
				return(game);
			}
			break;
	}
}

boolean CheckPuzzle()
{
	int solve;
	int b,k,c=1;
	solve=true;
	for(b=0;b<=fieldSize-1;b++)
	{
		for(k=0;k<=fieldSize-1;k++)
		{
			if(puzzle[b][k]!=goalpuzzle[b][k]){
				solve=false;
			}
		}
	}
	return(solve);
}

void Pause(int level)
{
	POINT cursorPosition;
	int mX,mY,b,k;
	//bacground
	cleardevice();
	readimagefile("desain/Pause/background.bmp",0,0,800,600);//layar kiri atas
	readimagefile("desain/Pause/back to game.bmp",267,286,531,348);
	readimagefile("desain/Pause/main menu.bmp",267,353,531,415);
	readimagefile("desain/Pause/exit.bmp",267,420,531,482);
	while(1)
	{
		GetCursorPos(&cursorPosition);
		mX=cursorPosition.x;
		mY=cursorPosition.y;
	    if(GetAsyncKeyState(VK_LBUTTON) && mX>=267 && mX<=531 && mY>=286 &&mY<=348)
	    {
	    	readimagefile("desain/Pause/back to game down.bmp",267,286,531,348);
	    	delay(50);
	    	readimagefile("desain/Pause/back to game.bmp",267,286,531,348);
	    	cleardevice();
			TampilanPlayGame(level);
			for(b=0;b<=fieldSize-1;b++) //Menggambar semua puzzle
			{
				for(k=0;k<=fieldSize-1;k++)
				{
					DrawPuzzle(level,puzzle[b][k]);
				}
			}
	    	break;
	    }
	    if(GetAsyncKeyState(VK_LBUTTON) && mX>=267 && mX<=531 && mY>=353 &&mY<=415)
	    {
	    	readimagefile("desain/Pause/main menu down.bmp",267,353,531,415);
	    	delay(50);
	    	readimagefile("desain/Pause/main menu.bmp",267,353,531,415);
	    	MainMenu();
	    	break;
	    }
	    if(GetAsyncKeyState(VK_LBUTTON) && mX>=267 && mX<=531 && mY>=420 &&mY<=482)
	    {
	    	readimagefile("desain/Pause/exit down.bmp",267,420,531,482);
	    	delay(50);
	    	readimagefile("desain/Pause/exit.bmp",267,420,531,482);
	    	exit(1);
	    	break;
	    }
	}
}

void Solve(Stack *head,int level,GameControl game)
{
	arrowtype arah;
	int b,k;
	printf("Solve");
	while(*head!=NULL)
	{
		Pop(&(*head),&arah);
		printf("\n%d\n",arah.reverse);
		delay(500);
		switch(arah.reverse){
			case(Atas):
				game=Move(arah.reverse,game.initpos);
				delay(200);
				DrawPuzzle(level,blank);
       			DrawPuzzle(level,puzzle[game.initpos.x+1][game.initpos.y]);
				break;
			case(Bawah):
				game=Move(arah.reverse,game.initpos);
				delay(200);
				DrawPuzzle(level,blank);
       			DrawPuzzle(level,puzzle[game.initpos.x-1][game.initpos.y]);
				break;
			case(Kanan):
				game=Move(arah.reverse,game.initpos);
				delay(200);
				DrawPuzzle(level,blank);
       			DrawPuzzle(level,puzzle[game.initpos.x][game.initpos.y-1]);
				break;
			case(Kiri):
				game=Move(arah.reverse,game.initpos);
				delay(200);
				DrawPuzzle(level,blank);
       			DrawPuzzle(level,puzzle[game.initpos.x][game.initpos.y+1]);
				break;
		}
		printf("Solve baris %d kolom %d\n",game.initpos.x,game.initpos.y);
	}
	printf("EndSolve\n");
}

void PlayGame(PuzzleController player)
{
	//Kamus Lokal
	POINT cursorPosition;
	int mX, mY,solve,timeup,b,k;
	GameControl game;
	boolean found;
	char ch,tmr[10],mv[5];
	PuzzleTree gamepuzz;
	//Algoritma
	game.move=0;
	game.timer.detik=0;
	game.timer.jam=0;
	switch(player.leveltime){
		case unlimited:
			game.timer.menit=0;
			break;
		case lima:
			game.timer.menit=5;
			break;
		case sepuluh:
			game.timer.menit=10;
			break;
	}
	
	//Kondisi awal untuk looping dalam game
	solve=false;
	timeup=false;
	
	//Memasukkan goalpuzzle ke initpuzzle untuk di random
	//InitPuzzle();
	
	//Menentukan initpos
	game.initpos=SearchInitpos();
	printf("\n%d %d\n\n",game.initpos.x,game.initpos.y);
	
	//Mendapatkan initial state puzzle dari merandom angka 1-9
	gamepuzz=GenerateTree(Depth,game.initpos);
	Tampil_Stack(gamepuzz.stack);
	
    //Menggambar background
	cleardevice();
	TampilanPlayGame(player.level);
	MakeInitPuzzle(gamepuzz.stack);
	gamepuzz.stack=BalikStack(gamepuzz.stack);
	//Menggambar semua puzzle
	for(b=0;b<=fieldSize-1;b++)
	{
		for(k=0;k<=fieldSize-1;k++)
		{
			printf("\nDraw\n%d %d\n",player.level,puzzle[b][k]);
			DrawPuzzle(player.level,puzzle[b][k]);
		}
	}
	
	//GamePlay
	while(!solve&&!timeup){
		setcolor(BLACK);
		setbkcolor(7);
		readimagefile("desain/game/time move.bmp",544,303,769,393);
		sprintf(tmr,"%d:%d:%d",game.timer.jam,game.timer.menit,game.timer.detik);
		settextstyle(6,HORIZ_DIR,1);
		outtextxy(570,350,tmr);

		game.timer=Timer(player.leveltime,game.timer);
		if(game.timer.detik==0){
			timeup=false;
		}
		
		game=Controller(game,player.level,&gamepuzz.stack);
		//printf("\n%d\n",(game.puzzle)->data.move);
		
		sprintf(mv,"%d",game.move);
		settextstyle(6,HORIZ_DIR,1);
		outtextxy(705,350,mv);
		delay(1000);
		
		solve=CheckPuzzle();
		
		GetCursorPos(&cursorPosition);
		mX=cursorPosition.x;
		mY=cursorPosition.y;
	    if(GetAsyncKeyState(VK_LBUTTON) && mX>=736 && mX<=781 && mY>=22 &&mY<=67)
	    {
	    	readimagefile("desain/game/pause down.bmp",736,22,781,67);
	    	delay(50);
	    	readimagefile("desain/game/pause.bmp",736,22,781,67);
	    	Pause(player.level);
	    }else if(GetAsyncKeyState(VK_LBUTTON) && mX>=549 && mX<=619 && mY>=440 &&mY<=510) //Solve puzzle
		    {
		    	readimagefile("desain/game/solve down.bmp",549,410,619,480);
		    	delay(100);
		    	readimagefile("desain/game/solve.bmp",549,410,619,480);
		    	Solve(&gamepuzz.stack,player.level,game);
		    	delay(1000);
				solve=CheckPuzzle();
	    }
	}
	
	if(solve){
		player.timescore=game.timer;
//		player.timescore.detik=timer.detik;
//		player.timescore.menit=timer.menit;
//		player.timescore.jam=timer.jam;
		Winner();
	}else if(timeup){
		TimeUp();
	}
}
