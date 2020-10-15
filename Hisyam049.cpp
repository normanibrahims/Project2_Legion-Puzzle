#include "Hisyam049.h"

int solvepuzzzle[3][3]={{1,2,3},{4,5,6},{7,8,9}};
char static pazzle[3];

void AboutUs()
{
	POINT cursorPosition;
	int mX,mY;
	setcolor(BLACK);
	setbkcolor(15);
    readimagefile("desain/about us/about us.bmp",0,0,800,600);
/*    rectangle(262,362,354,486);
    readimagefile("desain/about us/186049.jpg",262,362,354,486);
    rectangle(177,195,269,319);
    readimagefile("desain/about us/FOTO MAHASISWA.jpg",177,195,269,319);
    rectangle(353,195,445 ,319);
    readimagefile("desain/about us/171511047.jpg",353,195,445 ,319);
    rectangle(433,362,525,486);
    readimagefile("desain/about us/20680.jpg",433,362,525,486);
    rectangle(519,195,611,319);
    readimagefile("desain/about us/171511055.jpg",519,195,611,319);
    rectangle(736,22,781,67);
    readimagefile("desain/about us/back.bmp",736,22,781,67);

	settextstyle(3,HORIZ_DIR,1);
	outtextxy(190,321,"Annisa F.");
	outtextxy(277,488,"Bagas F.");
	outtextxy(358,321,"Lisnawati S.");
	outtextxy(432,483,"M. Hisyamul I.");
	outtextxy(524,321,"Norman I. S.");
   
	outtextxy(180,340,"171511037");
	outtextxy(270,505,"171511039");	
	outtextxy(358,340,"171511047");	
	outtextxy(436,505,"171511049");
	outtextxy(524,341,"171511055");*/
	
	
	while(1){
		GetCursorPos(&cursorPosition);
		mX = cursorPosition.x;
		mY = cursorPosition.y;
		
		if (GetAsyncKeyState(VK_LBUTTON) and mX >= 736 and mX <= 781 and mY >= 22)
		{
			readimagefile("desain/about us/backdown.bmp", 736,22,781,67);
			delay(200);
			readimagefile("desain/about us/back.bmp", 736,22,781,67);
			MainMenu();
			break;
		}
	}
}

void Dinamis(char nama[],int level,int leveltime)
{
	PuzzleController player;
	char c;
	int a,sama,j;
	int i=0;
	int isi[9];
	char* temp;
	strcpy(player.player1,nama);
    player.level=level;
    player.leveltime=leveltime;
	while(i<=8){
		c=getch();
		a=c-'0';
		sama=0;
		printf("a = %d",a);
		//sprintf(temp,"%d",a);
		for(j=0;j<i;j++){
			if(a==isi[j]){
				sama=1;
			}
		}
		if(sama!=1){
			isi[i]=a;
			i++;
			InitPuzzle(isi);
			DrawPuzzle(player.level,a);
			//outtextxy(90,75,temp);
		}
	}
	printf("\n");

	InitPuzzle(isi);
	for(i=0;i<=8;i++){
		printf("%d \t",isi[i]);
	}
	PlayGame(player);
}


void CustomGame(char nama[],int level,int leveltime){
	POINT cursorPosition;
	PuzzleController player;
	int mX,mY;
    readimagefile("desain/custom/game.bmp",0,0,800,600);
    readimagefile("desain/custom/pause.bmp",736,22,781,67);
    strcpy(player.player1,nama);
    player.level=level;
    player.leveltime=leveltime;
    while(1){
		Dinamis(player.player1,player.level,player.leveltime);
		GetCursorPos(&cursorPosition);
		mX = cursorPosition.x;
		mY = cursorPosition.y;
		
		if (GetAsyncKeyState(VK_LBUTTON) and mX >= 736 and mX <= 781 and mY >= 52 and mY <= 97)
		{
			readimagefile("desain/about us/pause down.bmp", 736,22,781,67);
			delay(200);
			readimagefile("desain/about us/pause.bmp", 736,22,781,67);
			MainMenu();
			break;
		}
	}
}

void CustomPlay()
{
	POINT cursorPosition;
	int mX, mY,solve,timeup,b,k;
	GameControl game;
	boolean found;
	char ch,tmr[10],mv[5];
	PuzzleTree gamepuzz;
	
	//Background
	readimagefile("desain/custom/background.bmp",0,0,800,600);
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
	//Game
	
	DrawPuzzleCustom();
/*
	readimagefile("desain/custom/gambar easy/1.bmp",60,79,210,229);
	readimagefile("desain/custom/gambar easy/2.bmp",210,79,360,229);
	readimagefile("desain/custom/gambar easy/3.bmp",360,79,510,229);
	readimagefile("desain/custom/gambar easy/4.bmp",60,229,210,379);
	readimagefile("desain/custom/gambar easy/5.bmp",210,229,360,379);
	readimagefile("desain/custom/gambar easy/6.bmp",360,229,510,379);
	readimagefile("desain/custom/gambar easy/7.bmp",60,379,210,529);
	readimagefile("desain/custom/gambar easy/8.bmp",210,379,360,529);
	readimagefile("desain/custom/gambar easy/x.bmp",360,379,510,529);
*/

	if(solve){
//		player.timescore=game.timer;
//		player.timescore.detik=timer.detik;
//		player.timescore.menit=timer.menit;
//		player.timescore.jam=timer.jam;
		Winner();
	}

}

void DrawPuzzleCustom()
{
	position pos;
	readimagefile("desain/custom/gambar easy/1.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
	readimagefile("desain/custom/gambar easy/2.bmp",210,79,360,229);
	readimagefile("desain/custom/gambar easy/3.bmp",360,79,510,229);
	readimagefile("desain/custom/gambar easy/4.bmp",60,229,210,379);
	readimagefile("desain/custom/gambar easy/5.bmp",210,229,360,379);
	readimagefile("desain/custom/gambar easy/6.bmp",360,229,510,379);
	readimagefile("desain/custom/gambar easy/7.bmp",60,379,210,529);
	readimagefile("desain/custom/gambar easy/8.bmp",210,379,360,529);
	readimagefile("desain/custom/gambar easy/x.bmp",360,379,510,529);
/*	position pos;
    switch(isi){
        case puzzle1 :
		pos.x=SearchPosX(puzzle1);
        pos.y=SearchPosY(puzzle1);
		readimagefile("desain/custom/gambar easy/1.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle2 :
		pos.x=SearchPosX(puzzle2);
        pos.y=SearchPosY(puzzle2);
		readimagefile("desain/custom/gambar easy/2.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle3 :
		pos.x=SearchPosX(puzzle3);
        pos.y=SearchPosY(puzzle3);
        readimagefile("desain/custom/gambar easy/3.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle4 :
		pos.x=SearchPosX(puzzle4);
        pos.y=SearchPosY(puzzle4);
        readimagefile("desain/custom/gambar easy/4.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle5 : 
		pos.x=SearchPosX(puzzle5);
        pos.y=SearchPosY(puzzle5);
        readimagefile("desain/custom/gambar easy/5.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle6 : 
		pos.x=SearchPosX(puzzle6);
        pos.y=SearchPosY(puzzle6);
        readimagefile("desain/custom/gambar easy/6.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle7 : 
		pos.x=SearchPosX(puzzle7);
        pos.y=SearchPosY(puzzle7);
        readimagefile("desain/custom/gambar easy/7.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case puzzle8 : 
		pos.x=SearchPosX(puzzle8);
        pos.y=SearchPosY(puzzle8);
        readimagefile("desain/custom/gambar easy/8.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case blank : 
        pos.x=SearchPosX(blank);
        pos.y=SearchPosY(blank);
		readimagefile("desain/custom/gambar easy/x.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        */
        
}
