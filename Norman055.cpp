#include "Norman055.h"
//#include "Lisna047.h"
point a,b,c,d,e,f,g,h;
int i,j,k,l,m,n,o,p,r;

void Player()
{
	POINT cursorPosition;
	int mX,mY;
	cleardevice();
	readimagefile("desain/player/main.bmp",0,0,800,600);
	//Back
	readimagefile("desain/player/back.bmp",736, 22 , 781, 67);
	p=13;
	//OnePlayer
	readimagefile("desain/player/1 player.bmp",266,312,530,394);
	n=11;
	//TwoPlayer
	readimagefile("desain/player/2 player.bmp",266,404,530,486);
	o=12;
	do
    {
        GetCursorPos(&cursorPosition);
        mX=cursorPosition.x;
        mY=cursorPosition.y;
        
    // EFFECT CLICK 
		if (n==11 && GetAsyncKeyState(VK_LBUTTON) && mX>=266 && mX<=530 && mY>=342 && mY<=424)
		{		readimagefile("desain/player/1 player down.bmp",266,312,530,394);
				delay(200);
				readimagefile("desain/player/1 player.bmp",266,312,530,394);
				delay(100);
				Player1();
				break;
			
		}
			else if (o==12 && GetAsyncKeyState(VK_LBUTTON) && mX>=266 && mX<=530 && mY>=434 && mY<=516)
			{	
		   		readimagefile("desain/player/2 player down.bmp",266,404,530,486);
				delay(200);
				readimagefile("desain/player/2 player.bmp",266,404,530,486);
				//Player2();
				delay(100);
			}
				else if (p==13 && GetAsyncKeyState(VK_LBUTTON) && mX>=736 && mX<=781 && mY>=52 && mY<=97)
				{		
		   			readimagefile("desain/player/back down.bmp",736, 22 , 781, 67);
					delay(200);
					readimagefile("desain/player/back.bmp",736, 22 , 781, 67);
					delay(100);
					MainMenu();
					break;
				}
		
	delay(50);
    clearmouseclick(WM_LBUTTONDOWN);
	}while(1);
}

void Player1()
{
	int idx;
    char c;
    char inputbuf[12],player[12];
    int input_pos;
    int the_end;
    cleardevice();
    readimagefile("desain/player/main.bmp",0,0,800,600);
	
    for(idx=0;idx<12;idx++)
    inputbuf[idx]=0;
    input_pos = 0;
    the_end=0;
        do
        {
//          cleardevice();
            setcolor(15);
            readimagefile("desain/main/main.bmp",0,0,800,600);
            readimagefile("desain/Level/back.bmp",736, 22 , 781, 67);
			rectangle(250,270,550,390);
			setfillstyle(1,BLACK);
			floodfill(300,340,WHITE);
			settextstyle(8, HORIZ_DIR,4);
			outtextxy(318,260,"PLAYER 1");
            settextstyle(3, HORIZ_DIR,4);
//			setcolor(WHITE);
//			setbkcolor(WHITE);
			outtextxy(260,295," >> Isi Nama <<");
            outtextxy (273, 340, inputbuf);
            c = getch();
            switch (c)
            {
                case 8: /* backspace */
                        if (input_pos)
                        {
                            input_pos--;
                            inputbuf[input_pos] = ' ';
//                          rectangle(250,270,550,390);
//							setfillstyle(SOLID_FILL,BLACK);
//							floodfill(300,340,WHITE);
                        }
                        break;
                case 13: /* return */
                        the_end = 1;
                        break;
                default:
                if (input_pos < 12-1 && c >= 'A' && c <= 'z')
                {
                    inputbuf[input_pos] = c;
                    input_pos++;
                    inputbuf[input_pos] = 0;
                }
            }
        }while (!the_end);
    strcpy(player, inputbuf);
//  cleardevice();
    SettingGame(player);
}

//void Player2()
//{
//	int idx;
//    char c;
//    char inputbuf[12];
//    int input_pos;
//    int the_end;
//    int i=2;
//	cleardevice();
//    readimagefile("desain/player/main.bmp",0,0,800,600);
//    readimagefile("desain/Level/back.bmp",736, 22 , 781, 67);
//	if(i=2)
//	{
//    for(idx=0;idx<12;idx++)
//    inputbuf[idx]=0;
//    input_pos = 0;
//    the_end=0;
//        do
//        {
////          cleardevice();
//            setcolor(15);
//            readimagefile("desain/main/main.bmp",0,0,800,600);
//			rectangle(250,270,550,390);
//			setfillstyle(1,BLACK);
//			floodfill(300,340,WHITE);
//			settextstyle(8, HORIZ_DIR,4);
//			outtextxy(318,260,"PLAYER 1");
//            settextstyle(3, HORIZ_DIR,4);
////          setcolor(BLACK);
////			setbkcolor(3);
//			outtextxy(260,295," >> Isi Nama <<");
//            outtextxy (273, 340, inputbuf);
//            
//            
//			rectangle(250,420,550,540);
//			setfillstyle(1,BLACK);
//			floodfill(300,440,WHITE);
//			settextstyle(8, HORIZ_DIR,4);
//			outtextxy(318,410,"PLAYER 2");
//	        settextstyle(3, HORIZ_DIR,4);
//	//      setcolor(BLACK);
//	//		setbkcolor(3);
//			outtextxy(260,445," >> Isi Nama <<");
//		
//		
//            c = getch();
//            switch (c)
//            {
//                case 8: /* backspace */
//                        if (input_pos)
//                        {
//                            input_pos--;
//                            inputbuf[input_pos] = 0;
//                        }
//                        break;
//                case 13: /* return */
//                        the_end = 1;
//                        InputPlayer2();
//                        break;
//                default:
//                if (input_pos < 12-1 && c >= 'A' && c <= 'z')
//                {
//                    inputbuf[input_pos] = c;
//                    input_pos++;
//                    inputbuf[input_pos] = 0;
//                }
//            }
//        }while (!the_end);
//    strcpy(player.player1, inputbuf);
//	
//	}
//}

//void InputPlayer2()
//{	
//	int idx;
//    char c;
//    char inputbuf[12];
//    int input_pos;
//    int the_end;
//
//    for(idx=0;idx<12;idx++)
//    inputbuf[idx]=0;
//    input_pos = 0;
//    the_end=0;
//        do
//        {
////            cleardevice();
//            setcolor(15);
//            readimagefile("desain/main/main.bmp",0,0,800,600);
//            readimagefile("desain/Level/back.bmp",736, 22 , 781, 67);
//			rectangle(250,420,550,540);
//			setfillstyle(1,BLACK);
//			floodfill(300,440,WHITE);
//			settextstyle(8, HORIZ_DIR,4);
//			outtextxy(318,410,"PLAYER 2");
//            settextstyle(3, HORIZ_DIR,4);
////            setcolor(BLACK);
////			setbkcolor(3);
//			outtextxy(260,445," >> Isi Nama <<");
//            outtextxy (273, 490, inputbuf);
//            c = getch();
//            switch (c)
//            {
//                case 8: /* backspace */
//                        if (input_pos)
//                        {
//                            input_pos--;
//                            inputbuf[input_pos] = 0;
//                        }
//                        break;
//                case 13: /* return */
//                        the_end = 1;
//                        break;
//                default:
//                if (input_pos < 12-1 && c >= 'A' && c <= 'z')
//                {
//                    inputbuf[input_pos] = c;
//                    input_pos++;
//                    inputbuf[input_pos] = 0;
//                }
//            }
//        }while (!the_end);
////    strcpy(HS[MAX-1].nama, inputbuf);
//}

void SettingGame(char nama[])
{	
	PuzzleController player;
	POINT cursorPosition;
	int mX,mY;
	readimagefile("desain/Level/level.bmp",0, 0 , 800, 600);
	Menu();
	Start();
	Custom();
	strcpy(player.player1,nama);
	//TULISAN GAMBAR PUZZLE 
	setcolor(BLACK);
	setbkcolor(7);
	settextstyle(8,HORIZ_DIR,3);
	outtextxy(171,316,"G");
	settextstyle(8,HORIZ_DIR,1);
	outtextxy(186,320,"AMBAR ");
	settextstyle(8,HORIZ_DIR,3);
	outtextxy(250,316,"P");
	settextstyle(8,HORIZ_DIR,1);
	outtextxy(265,320,"UZZLE");
	
	//TULISAN NAMA PEMAIN
	settextstyle(8,HORIZ_DIR,3);
	outtextxy(390,316,"N");
	settextstyle(8,HORIZ_DIR,1);
	outtextxy(405,320,"AMA ");
	settextstyle(8,HORIZ_DIR,3);
	outtextxy(445,316,"P");
	settextstyle(8,HORIZ_DIR,1);
	outtextxy(459,320,"EMAIN : ");
	
	settextstyle(8,HORIZ_DIR,3);
	//outtextxy(545,317,"MONZE");
	outtextxy(543,317,player.player1);
	
	//TULISAN TINGKAT KESULITAN
	settextstyle(8,HORIZ_DIR,3);
	outtextxy(335,361,"T");
	settextstyle(8,HORIZ_DIR,1);
	outtextxy(348,365,"INGKAT");
	settextstyle(8,HORIZ_DIR,3);
	outtextxy(425,361,"K");
	settextstyle(8,HORIZ_DIR,1);
	outtextxy(441,365,"ESULITAN");
	
	player.level=Easy();
//	settextstyle(8,HORIZ_DIR,3);
//	outtextxy(405,382,"EASY");
	
	//TANDA PANAH TINGKAT KESULITAN
	readimagefile("desain/Level/kiri up.bmp",365,385,380,402);
	readimagefile("desain/Level/kanan up.bmp",490,385,505,402);
	
	//TULISAN WAKTU
	settextstyle(8,HORIZ_DIR,3);
	outtextxy(576,361,"W");
	settextstyle(8,HORIZ_DIR,1);
	outtextxy(590,365,"AKTU");
	
	player.leveltime=Unlimited();
	
	//TANDA PANAH WAKTU
	readimagefile("desain/Level/kiri up.bmp",554,385,569,402);
	readimagefile("desain/Level/kanan up.bmp",639,385,655,402);
	
	//KOTAK PUZZLE
//	rectangle(170,348,320,498);
	
//	rectangle(170,348,220,398);
//	rectangle(170,398,220,448);
//	rectangle(170,448,220,498);
	
//	rectangle(220,348,270,398);
//	rectangle(220,398,270,448);
//	rectangle(220,448,270,498);
	
//	rectangle(270,348,320,398);
//	rectangle(270,398,320,448);
//	rectangle(270,448,320,498);
	
	tkte();

	//TANDA PANAH KOTAK PUZZLE
	readimagefile("desain/Level/kanan up.bmp",325,408,345,438);
	readimagefile("desain/Level/kiri up.bmp",145,408,165,438);
	
	//EFFECT CLICK 1
	do
    {
        GetCursorPos(&cursorPosition);
        mX=cursorPosition.x;
        mY=cursorPosition.y;
        
    // PANAH UNTUK TINGKAT KESULITAN
				if (i==1 && GetAsyncKeyState(VK_LBUTTON) && mX>=490 && mX<=505 && mY>=415 && mY<=432)
       			{		readimagefile("desain/Level/kanan down.bmp",490,385,505,402);
						delay(200);
						readimagefile("desain/Level/kanan up.bmp",490,385,505,402);		
						delay(100);
//						TampilanMedUnlTT();
						player.level=Medium();
						tktm();
//						break;
					
				}
					else if (i==2 && GetAsyncKeyState(VK_LBUTTON) && mX>=490 && mX<=505 && mY>=415 && mY<=432)
       				{	
				   		readimagefile("desain/Level/kanan down.bmp",490,385,505,402);
						delay(200);
						readimagefile("desain/Level/kanan up.bmp",490,385,505,402);		
						delay(100);
						player.level=Hard();
						tkth();
					}
						else if (i==3 && GetAsyncKeyState(VK_LBUTTON) && mX>=490 && mX<=505 && mY>=415 && mY<=432)
       					{		
				   			readimagefile("desain/Level/kanan down.bmp",490,385,505,402);
							delay(200);
							readimagefile("desain/Level/kanan up.bmp",490,385,505,402);		
							delay(100);
							player.level=Easy();
							tkte();
						}
							else if (i==3 && GetAsyncKeyState(VK_LBUTTON) && mX>=365 && mX<=380 && mY>=415 && mY<=432)
    			   			{
								readimagefile("desain/Level/kiri down.bmp",365,385,380,402);
								delay(200);
								readimagefile("desain/Level/kiri up.bmp",365,385,380,402);
								delay(100);
								player.level=Medium();
								tktm();
							}	
								else if (i==2 && GetAsyncKeyState(VK_LBUTTON) && mX>=365 && mX<=380 && mY>=415 && mY<=432)
    			   				{
									readimagefile("desain/Level/kiri down.bmp",365,385,380,402);
									delay(200);
									readimagefile("desain/Level/kiri up.bmp",365,385,380,402);
									delay(100);
									player.level=Easy();
									tkte();
								}	
									else if (i==1 && GetAsyncKeyState(VK_LBUTTON) && mX>=365 && mX<=380 && mY>=415 && mY<=432)
    			   					{
										readimagefile("desain/Level/kiri down.bmp",365,385,380,402);
										delay(200);
										readimagefile("desain/Level/kiri up.bmp",365,385,380,402);
										delay(100);
										player.level=Hard();
										tkth();
									}
	
	//PANAH UNNTUK WAKTU							
		else if (j==4 && GetAsyncKeyState(VK_LBUTTON) && mX>=639 && mX<=655 && mY>=385 && mY>=415 && mY<=432)
       			{		readimagefile("desain/Level/kanan down.bmp",639,385,655,402);
						delay(200);
						readimagefile("desain/Level/kanan up.bmp",639,385,655,402);		
						delay(100);
//						TampilanMedUnlTT();
						player.leveltime=Lima();
//						break;
					
				}
					else if (j==5 && GetAsyncKeyState(VK_LBUTTON) && mX>=639 && mX<=655 && mY>=415 && mY<=432)
       				{	
				   		readimagefile("desain/Level/kanan down.bmp",639,385,655,402);
						delay(200);
						readimagefile("desain/Level/kanan up.bmp",639,385,655,402);		
						delay(100);
						player.leveltime=Sepuluh();
					}
						else if (j==6 && GetAsyncKeyState(VK_LBUTTON) && mX>=639 && mX<=655 && mY>=415 && mY<=432)
       					{		
				   			readimagefile("desain/Level/kanan down.bmp",639,385,655,402);
							delay(200);
							readimagefile("desain/Level/kanan up.bmp",639,385,655,402);		
							delay(100);
							player.leveltime=Unlimited();
						}
							else if (j==6 && GetAsyncKeyState(VK_LBUTTON) && mX>=554 && mX<=569 && mY>=415 && mY<=432)
    			   			{
								readimagefile("desain/Level/kiri down.bmp",554,385,569,402);
								delay(200);
								readimagefile("desain/Level/kiri up.bmp",554,385,569,402);
								delay(100);
								player.leveltime=Lima();
							}	
								else if (j==5 && GetAsyncKeyState(VK_LBUTTON) && mX>=554 && mX<=569 && mY>=415 && mY<=432)
    			   				{
									readimagefile("desain/Level/kiri down.bmp",554,385,569,402);
									delay(200);
									readimagefile("desain/Level/kiri up.bmp",554,385,569,402);
									delay(100);
									player.leveltime=Unlimited();
								}	
									else if (j==4 && GetAsyncKeyState(VK_LBUTTON) && mX>=554 && mX<=569 && mY>=385 && mY<=402)
    			   					{
										readimagefile("desain/Level/kiri down.bmp",554,385,569,402);
										delay(200);
										readimagefile("desain/Level/kiri up.bmp",554,385,569,402);
										delay(100);
										player.leveltime=Sepuluh();
									}
	
    // PANAH UNTUK GAMBAR PUZZLE
			else if (k==7 && GetAsyncKeyState(VK_LBUTTON) && mX>=325 && mX<=345 && mY>=438 && mY<=468)
       			{		readimagefile("desain/Level/kanan down.bmp",325,408,345,438);
						delay(200);
						readimagefile("desain/Level/kanan up.bmp",325,408,345,438);		
						delay(100);
//						TampilanMedUnlTT();
						tktm();
						player.level=Medium();
//						break;
					
				}
					else if (k==8 && GetAsyncKeyState(VK_LBUTTON) && mX>=325 && mX<=345 && mY>=438 && mY<=468)
       				{	
				   		readimagefile("desain/Level/kanan down.bmp",325,408,345,438);
						delay(200);
						readimagefile("desain/Level/kanan up.bmp",325,408,345,438);		
						delay(100);
						tkth();
						player.level=Hard();
					}
							else if (k==9 && GetAsyncKeyState(VK_LBUTTON) && mX>=325 && mX<=345 && mY>=438 && mY<=468)
    			   			{
								readimagefile("desain/Level/kanan down.bmp",325,408,345,438);
								delay(200);
								readimagefile("desain/Level/kanan up.bmp",325,408,345,438);
								delay(100);
								tkte();
								player.level=Easy();
							}	
								else if (k==7 && GetAsyncKeyState(VK_LBUTTON) && mX>=145 && mX<=165 && mY>=438 && mY<=4688)
    			   				{
									readimagefile("desain/Level/kiri down.bmp",145,408,165,438);
									delay(200);
									readimagefile("desain/Level/kiri up.bmp",145,408,165,438);
									delay(100);
									tkth();
									player.level=Hard();
								}	
								else if (k==9 && GetAsyncKeyState(VK_LBUTTON) && mX>=145 && mX<=165 && mY>=438 && mY<=468)
    			   				{
									readimagefile("desain/Level/kiri down.bmp",145,408,165,438);
									delay(200);
									readimagefile("desain/Level/kiri up.bmp",145,408,165,438);
									delay(100);
									tktm();
									player.level=Medium();
								}
									else if (k==8 && GetAsyncKeyState(VK_LBUTTON) && mX>=145 && mX<=165 && mY>=438 && mY<=468)
    			   					{
										readimagefile("desain/Level/kiri down.bmp",145,408,165,438);
										delay(200);
										readimagefile("desain/Level/kiri up.bmp",145,408,165,438);
										delay(100);
										tkte();
										player.level=Easy();
									}

	// TOMBOL START
	else if (l==9 && GetAsyncKeyState(VK_LBUTTON) && mX>=465 && mX<=634 && mY>=466 && mY<=528)
       			{		
				   		readimagefile("desain/Level/startdown.bmp",465,436,638,498);
						delay(200);
						readimagefile("desain/Level/start.bmp",465,436,638,498);
						delay(100);
						StartPlayGame();
						PlayGame(player);
						break;
				}
				
	// TOMBOL CUSTOM
	else if (r==10 && GetAsyncKeyState(VK_LBUTTON) && mX>=370 && mX<=449 && mY>=473 && mY<=523)
       			{		
				   		readimagefile("desain/Level/custom.bmp",370,443,449,493);
						delay(200);
						readimagefile("desain/Level/customdown.bmp",370,443,449,493);
						delay(100);
						CustomGame(player.player1,player.level,player.leveltime);
						break;
				}

	// TOMBOL MENU
	else if (m==10 && GetAsyncKeyState(VK_LBUTTON) && mX>=736 && mX<=781 && mY>=52 && mY<=97)
       			{	
				   		readimagefile("desain/Level/back down.bmp",736, 22 , 781, 67);
						delay(200);
						readimagefile("desain/Level/back.bmp",736, 22 , 781, 67);
						delay(100);
						Player();
						break;
				}
    
	delay(50);
    clearmouseclick(WM_LBUTTONDOWN);
	}while(1);
}



int Easy()
{
	//player.level=easy;
	readimagefile("desain/Level/easy.bmp",385,381,482,406);
	i=1;
	return(easy);
}

int Medium()
{	
	//player.level=medium;
	readimagefile("desain/Level/medium.bmp",385,381,482,406);
	i=2;
	return(medium);
}

int Hard()
{
	//player.level=hard;
	readimagefile("desain/Level/hard.bmp",385,381,482,406);
	i=3;
	return(hard);
}

int Unlimited()
{
	//player.Level_Time=unlimited;
	readimagefile("desain/Level/unlimited.bmp",576,385,632,402);
	j=4;
	return(unlimited);	
}

int Lima()
{
	//player.Level_Time=lima;
	readimagefile("desain/Level/5m.bmp",576,385,632,402);
	j=5;
	return(lima);
}

int Sepuluh()
{
	//player.Level_Time=sepuluh;
	readimagefile("desain/Level/10m.bmp",576,385,632,402);
	j=6;
	return(sepuluh);
}

void tkte()
{
	readimagefile("desain/Level/gambar1.bmp",170,348,320,498);
	k=7;
}

void tktm()
{
	readimagefile("desain/Level/gambar2.jpg",170,348,320,498);
	k=8;
}

void tkth()
{
	readimagefile("desain/Level/gambar3.jpg",170,348,320,498);
	k=9;
}

void eke()
{
	readimagefile("desain/Level/gambar1.bmp",170,348,320,498);
	k=8;
}

void Start()
{
	readimagefile("desain/Level/start.bmp",465,436,638,498);
	l=9;
}

void Custom()
{
	readimagefile("desain/Level/custom.bmp",370,443,449,493);
	r=10;
}

void Menu()
{
	readimagefile("desain/Level/back.bmp",736, 22 , 781, 67);
	m=10;
}

void StartPlayGame()
{
	int solvepuzzle[9]={1,2,3,4,5,6,7,8,9};
	
	InitPuzzle(solvepuzzle);
}
