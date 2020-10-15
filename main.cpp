//#include "Annisa037.h"
#include "Bagas039.h"
#include "Lisna047.h"
#include "Hisyam049.h"
#include "Norman055.h"

int main()
{
	//Algoritma
	initwindow(800,600,"MenuGame",0,0);
	
	PlaySound("assets/music/A Hero's Journey.wav", NULL, SND_ASYNC);
	MainMenu();
	
    getch();
	closegraph();
	return 0;
}
