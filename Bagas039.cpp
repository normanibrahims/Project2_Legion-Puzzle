#include "Bagas039.h"

void MainMenu()
{	
	POINT cursorPosition;
	int mX,mY;
	//Algoritma
	readimagefile("desain/main menu/main.bmp",0,0,800,600);
	readimagefile("desain/main menu/play.bmp",263,309,537,364);
	readimagefile("desain/main menu/highscore.bmp",252,372,394,427);
	readimagefile("desain/main menu/how to play.bmp",406,372,548,427);
	readimagefile("desain/main menu/about us.bmp",252,434,394,489);
	readimagefile("desain/main menu/exit.bmp",406,434,548,489);
	do{
		GetCursorPos(&cursorPosition);
		mX=cursorPosition.x;
		mY=cursorPosition.y;
		if (GetAsyncKeyState(VK_LBUTTON) && mX>=263 && mX<=537 && mY>=339 && mY<=394){
			readimagefile("desain/main menu/play down.bmp",263,309,537,364);
			delay(50);
			readimagefile("desain/main menu/play.bmp",263,309,537,364);
			delay(50);
			Player();
			}
			else if (GetAsyncKeyState(VK_LBUTTON) && mX>=252 && mX<=394 && mY>=402 && mY<=457)
			{
				readimagefile("desain/main menu/highscore down.bmp",252,372,394,427);
				delay(100);
				readimagefile("desain/main menu/highscore.bmp",252,372,394,427);
				delay(50);
				int level=easy;
				HighScore(level);
			}
				else if (GetAsyncKeyState(VK_LBUTTON) && mX>=406 && mX<=548 && mY>=402 && mY<=457)
				{
					readimagefile("desain/main menu/how to play down.bmp",406,372,548,427);
					delay(50);
					readimagefile("desain/main menu/how to play.bmp",406,372,548,427);
					delay(50);
					HowToPlay();
				}
					else if (GetAsyncKeyState(VK_LBUTTON) && mX>=252 && mX<=394 && mY>=464 && mY<=519)
					{
						readimagefile("desain/main menu/about us down.bmp",252,434,394,489);
						delay(50);
						readimagefile("desain/main menu/about us.bmp",252,434,394,489);
						delay(50);
						AboutUs();
					}
						else if (GetAsyncKeyState(VK_LBUTTON) && mX>=406 && mX<=548 && mY>=464 && mY<=519)
						{
							readimagefile("desain/main menu/exit down.bmp",406,434,548,489);
							delay(50);
							readimagefile("desain/main menu/exit.bmp",406,434,548,489);
							delay(200);
							exit(1);
						}
		
	clearmouseclick(WM_LBUTTONDOWN);
	}while(1);
}


void HowToPlay()
{
	POINT cursorPosition;
	int mX,mY;
	
	readimagefile("desain/how to play/how to play hal 1.bmp",0,0,800,600);
	readimagefile("desain/how to play/kanan.bmp",602,319,630,376);

	while(1){
	GetCursorPos(&cursorPosition);
	mX = cursorPosition.x;
	mY = cursorPosition.y;
	if (GetAsyncKeyState(VK_LBUTTON) and mX >= 602 and mX <= 630 and mY >= 349 and mY <= 406)
	{
		readimagefile("desain/how to play/kanan down.bmp",602,319,630,376);
		delay(200);
		readimagefile("desain/how to play/kanan.bmp",602,319,630,376);
		Hal2();
		break;	
	}
	if (GetAsyncKeyState(VK_LBUTTON) and mX >= 736 and mX <= 781 and mY >= 52 and mY <= 97)
	{
		readimagefile("backdown.bmp", 736,22,781,67);
		delay(200);
		readimagefile("back.bmp", 736,22,781,67);
		MainMenu();
		break;
	}
	}	
}

void Hal2()
{
	POINT cursorPosition;
	int mX,mY;

	readimagefile("desain/how to play/how to play hal 2.bmp",0,0,800,600);
	readimagefile("desain/how to play/kiri.bmp",170,319,198,376);
	while(1){
	GetCursorPos(&cursorPosition);
	mX = cursorPosition.x;
	mY = cursorPosition.y;
	if (GetAsyncKeyState(VK_LBUTTON) and mX >= 170 and mX <= 198 and mY >= 349 and mY <= 406)
	{
		readimagefile("desain/how to play/kiri down.bmp",170,319,198,376);
		delay(200);
		readimagefile("desain/how to play/kiri.bmp",170,319,198,376);
		HowToPlay();
		break;	
	}
	if (GetAsyncKeyState(VK_LBUTTON) and mX >= 736 and mX <= 781 and mY >= 52 and mY <= 97)
	{
		readimagefile("backdown.bmp", 736,22,781,67);
		delay(200);
		readimagefile("back.bmp", 736,22,781,67);
		MainMenu();
		break;
	}
	}
}

void Winner()
{
	POINT cursorPosition;
	int mX,mY,idx;
	//scoring
//	if(player.Level_Time==unlimited)
//	{
//		printf("%d %d\n", idx, &idx);
//		MakeListScore(&idx);
//		printf("%d %d\n", idx, &idx);
//		InputScore(&idx);
//	}
	//bacground
	cleardevice();
	readimagefile("desain/winner/win.jpg",0,0,800,600);
	readimagefile("desain/winner/main menu.bmp",267,353,531,415);
	readimagefile("desain/winner/exit.bmp",267,420,531,482);
	PlaySound("assets/music/Sequence 01.wav", NULL, SND_SYNC);
//	PlaySound("assets/music/Fire Crackers.wav", NULL, SND_ASYNC);
	PlaySound("assets/music/Kids Cheering.wav", NULL, SND_ASYNC);
	while(1)
	{
		GetCursorPos(&cursorPosition);
		mX=cursorPosition.x;
		mY=cursorPosition.y;
	    if(GetAsyncKeyState(VK_LBUTTON) && mX>=267 && mX<=531 && mY>=383 &&mY<=445)
	    {
	    	readimagefile("desain/winnner/main menu down.bmp",267,353,531,415);
	    	delay(100);
	    	readimagefile("desain/winnner/main menu.bmp",267,353,531,415);
	    	delay(100);
			MainMenu();
	    	break;
	    }
	    if(GetAsyncKeyState(VK_LBUTTON) && mX>=267 && mX<=531 && mY>=450 &&mY<=512)
	    {
	    	readimagefile("desain/winner/exit down.bmp",267,420,531,482);
	    	delay(100);
	    	readimagefile("desain/winner/exit.bmp",267,420,531,482);
	    	delay(100);
			exit(1);
	    	break;
	    }
	}
}

void TimeUp()
{
	POINT cursorPosition;
	int mX,mY;
	//bacground
	cleardevice();
	readimagefile("desain/time up/time up.jpg",0,0,800,600);
	readimagefile("desain/time up/main menu.bmp",267,353,531,415);
	readimagefile("desain/time up/exit.bmp",267,420,531,482);
	while(1)
	{
		GetCursorPos(&cursorPosition);
		mX=cursorPosition.x;
		mY=cursorPosition.y;
	    if(GetAsyncKeyState(VK_LBUTTON) && mX>=267 && mX<=531 && mY>=383 &&mY<=445)
	    {
	    	readimagefile("desain/time up/main menu down.bmp",267,353,531,415);
	    	delay(50);
	    	readimagefile("desain/time up/main menu.bmp",267,353,531,415);
	    	MainMenu();
	    	break;
	    }
	    if(GetAsyncKeyState(VK_LBUTTON) && mX>=267 && mX<=531 && mY>=450 &&mY<=512)
	    {
	    	readimagefile("desain/time up/exit down.bmp",267,420,531,482);
	    	delay(50);
	    	readimagefile("desain/time up/exit.bmp",267,420,531,482);
	    	exit(1);
	    	break;
	    }
	}
}


