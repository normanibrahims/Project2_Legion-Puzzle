/* ANNISA FATHANA 171511037
   HIGH SCORE LAYOUT */
   
#include "Annisa037.h"
typedef struct{
	char nama[30];
	waktu skor;
}Score;
Score HS[MAX];

void EasyScore (int level)
{
	//int idx;
	readimagefile("desain/highscore/easy.bmp", 0,0,800,600);
	readimagefile("desain/highscore/back.bmp", 736,22,781,67);
	readimagefile("desain/highscore/kiriup.bmp", 180, 350, 220, 390);
	readimagefile("desain/highscore/kananup.bmp", 570, 350, 610, 390);
	readimagefile("desain/highscore/list.bmp",220,268,570,494);
	//player.level=easy;
//	printf("%d %d\n", *idx, &*idx);
//	MakeListScore(&*idx);
//	printf("%d %d\n", *idx, &*idx);
	TampilListScore(level);
}

void MediumScore(int level)
{
	//int idx;
	readimagefile("desain/highscore/medium.bmp", 0,0,800,600);
	readimagefile("desain/highscore/back.bmp", 736,22,781,67);
	readimagefile("desain/highscore/kiriup.bmp", 180, 350, 220, 390);
	readimagefile("desain/highscore/kananup.bmp", 570, 350, 610, 390);
	readimagefile("desain/highscore/list.bmp",220,268,570,494);
	//player.level=medium;
	//printf("%d %d\n", *idx, &*idx);
	//MakeListScore(&*idx);
	//printf("%d %d\n", *idx, &*idx);
	TampilListScore(level);
}

void HardScore(int level)
{
	//int idx;
	readimagefile("desain/highscore/hard.bmp", 0,0,800,600);
	readimagefile("desain/highscore/back.bmp", 736,22,781,67);
	readimagefile("desain/highscore/kiriup.bmp", 180, 350, 220, 390);
	readimagefile("desain/highscore/kananup.bmp", 570, 350, 610, 390);
	readimagefile("desain/highscore/list.bmp",220,268,570,494);
	//player.level=hard;
	//printf("%d %d\n", *idx, &idx);
	//MakeListScore(&*idx);
	//printf("%d %d\n", *idx, &idx);
	TampilListScore(level);
}

void Click (int *pos,int level)
{
	if (*pos == 0){
		*pos =3;
	}else if (*pos == 4){
		*pos = 1;
	}
	
	switch (*pos){
		case easy : EasyScore(level);
		break;
		case medium : MediumScore(level);
		break;
		case hard : HardScore(level);
		break;
	}
}

void Sorting(int *idx,int level)
{	
	Score temp;
	int high;
	int j, k, n,init,inif;
	switch(level){
		case easy:
			init=0;
			inif=5;
			//break;
		case medium:
			init=5;
			inif=10;
			//break;
		case hard:
			init=10;
			inif=15;
			//break;
	}
	
	for (j=init;j < inif;j++)
	{
		for(k=j+1;k <inif; k++)
		{
			/* Sorting berdasarkan jam */
			if(HS[j].skor.jam > HS[k].skor.jam)
			{
				strcpy(temp.nama, HS[j].nama);
				temp.skor.jam = HS[j].skor.jam;
				temp.skor.menit = HS[j].skor.menit;
				temp.skor.detik = HS[j].skor.detik;
					
				strcpy(HS[j].nama, HS[k].nama);
				HS[j].skor.jam = HS[k].skor.jam;
				HS[j].skor.menit = HS[k].skor.menit;
				HS[j].skor.detik = HS[k].skor.detik;
					
				strcpy(HS[k].nama, temp.nama);
				HS[k].skor.jam = temp.skor.jam;
				HS[k].skor.menit = temp.skor.menit;
				HS[k].skor.detik = temp.skor.detik;
			}
			/* kondisi jika jam sama maka akan di sort berdasarkan menit */
			else if(HS[j].skor.jam == HS[k].skor.jam){
				/* Sorting berdasarkan menit */
				if(HS[j].skor.menit > HS[k].skor.menit){
					strcpy(temp.nama, HS[j].nama);
					temp.skor.jam = HS[j].skor.jam;
					temp.skor.menit = HS[j].skor.menit;
					temp.skor.detik = HS[j].skor.detik;
						
					strcpy(HS[j].nama, HS[k].nama);
					HS[j].skor.jam = HS[k].skor.jam;
					HS[j].skor.menit = HS[k].skor.menit;
					HS[j].skor.detik = HS[k].skor.detik;
						
					strcpy(HS[k].nama, temp.nama);
					HS[k].skor.jam = temp.skor.jam;
					HS[k].skor.menit = temp.skor.menit;
					HS[k].skor.detik = temp.skor.detik;
				}
				/* kondisi jika menit sama maka akan di sort berdasarkan detik */
				else if(HS[j].skor.menit == HS[k].skor.menit){
					/* Sorting berdasarkan detik */
					if(HS[j].skor.detik > HS[k].skor.detik){
						strcpy(temp.nama, HS[j].nama);
						temp.skor.jam = HS[j].skor.jam;
						temp.skor.menit = HS[j].skor.menit;
						temp.skor.detik = HS[j].skor.detik;
							
						strcpy(HS[j].nama, HS[k].nama);
						HS[j].skor.jam = HS[k].skor.jam;
						HS[j].skor.menit = HS[k].skor.menit;
						HS[j].skor.detik = HS[k].skor.detik;
							
						strcpy(HS[k].nama, temp.nama);
						HS[k].skor.jam = temp.skor.jam;
						HS[k].skor.menit = temp.skor.menit;
						HS[k].skor.detik = temp.skor.detik;
					}
				}
			}
		}
	}
	
	for(n=0; n < *idx; n++){
		printf("%s : %d:%d:%d\n",HS[n].nama, HS[n].skor.jam, HS[n].skor.menit, HS[n].skor.detik);
	}
	
	FILE *f=fopen("assets/highscore/highscore.txt","w+");
	for(n=0; n < *idx; n++){
		fprintf(f,"%s | %d | %d | %d\n",HS[n].nama, HS[n].skor.jam, HS[n].skor.menit, HS[n].skor.detik);
	}	
	fclose(f);
}

void InputScore(int *idx,PuzzleController player)
{
	int inif;
	printf("%d",player.level);
	switch(player.level){
		case easy:
			inif=5;
			break;
		case medium:
			inif=10;
			break;
		case hard:
			inif=15;
			break;
	}
	
	if(HS[inif-1].nama=="-"){
		strcpy(HS[inif-1].nama,player.player1);
		HS[inif-1].skor.jam = player.timescore.jam;
		HS[inif-1].skor.menit = player.timescore.menit;
		HS[inif-1].skor.detik = player.timescore.detik;
		printf("Masuk sana\n");
		//++(*idx);
	}
	/* Kondisi jika array sudah terisi penuh maka akan di cek apakah nilai terakhir di array lebih besar dari nilai player */
	else if(HS[inif-1].skor.jam > player.timescore.jam){
		printf("Masuk sini\n");
		strcpy(HS[inif-1].nama,player.player1);
		HS[inif-1].skor.jam = player.timescore.jam;
		HS[inif-1].skor.menit = player.timescore.menit;
		HS[inif-1].skor.detik = player.timescore.detik;
	}
	else if(HS[inif-1].skor.jam == player.timescore.jam){
		if(HS[inif-1].skor.menit > player.timescore.menit){
			strcpy(HS[inif-1].nama,player.player1);
			HS[inif-1].skor.jam = player.timescore.jam;
			HS[inif-1].skor.menit = player.timescore.menit;
			HS[inif-1].skor.detik = player.timescore.detik;
		}
		else if(HS[inif-1].skor.menit == player.timescore.menit){
			if(HS[inif-1].skor.detik > player.timescore.detik){
				strcpy(HS[inif-1].nama,player.player1);
				HS[inif-1].skor.jam = player.timescore.jam;
				HS[inif-1].skor.menit = player.timescore.menit;
				HS[inif-1].skor.detik = player.timescore.detik;
			}
		}
	}
	
//	printf("%d\n",*idx);
	
//	printf("%s : %d:%d:%d\n",player.nama, player.skor.jam, player.skor.menit, player.skor.detik);
	
//	for(int n=0; n < *idx; n++){
//		printf("%s : %d:%d:%d\n",HS[n].nama, HS[n].skor.jam, HS[n].skor.menit, HS[n].skor.detik);
//	}
	
	/* Pemanggilan modul sorting */
	Sorting(&(*idx),player.level);
}

void MakeListScore(int *idx) //membaca file dan menampilkan data dari file
{
	int i;
	char a;
	
	/* membaca data dari file dan di simpan k dalam array */
	FILE *f=fopen("assets/highscore/highscore.txt","r");
	while(fscanf(f,"%s | %d | %d | %d\n",&HS[(*idx)].nama,&HS[(*idx)].skor.jam,&HS[(*idx)].skor.menit,&HS[(*idx)].skor.detik)!=EOF){
		++(*idx);
	}
	printf("%d %d\n", idx, &idx);
}

void TampilListScore(int level)
{
	int i;
	char scr[10];
	int pos;
	pos=280;
	/* Menampilkan data dari array yg sudah diisi data dari file */
	switch(level){
		case easy:
			/* Menyimpan data yg sudah di sorting ke file */
			for(i=5; i < 10; i++){
				sprintf(scr,"%s",HS[i].nama);
				setcolor(15);
				setbkcolor(6);
				pos=pos+34;
				outtextxy(260,pos,scr);
				sprintf(scr,"%d : %d : %d",HS[i].skor.jam, HS[i].skor.menit, HS[i].skor.detik);
				outtextxy(430,pos,scr);
			}
			break;
		case medium:
			/* Menyimpan data yg sudah di sorting ke file */
			for(i=5; i < 10; i++){
				sprintf(scr,"%s",HS[i].nama);
				setcolor(15);
				setbkcolor(6);
				pos=pos+34;
				outtextxy(260,pos,scr);
				sprintf(scr,"%d : %d : %d",HS[i].skor.jam, HS[i].skor.menit, HS[i].skor.detik);
				outtextxy(430,pos,scr);
			}
			break;
		case hard:
			/* Menyimpan data yg sudah di sorting ke file */
			for(i=5; i < 10; i++){
				sprintf(scr,"%s",HS[i].nama);
				setcolor(15);
				setbkcolor(6);
				pos=pos+34;
				outtextxy(260,pos,scr);
				sprintf(scr,"%d : %d : %d",HS[i].skor.jam, HS[i].skor.menit, HS[i].skor.detik);
				outtextxy(430,pos,scr);
			}
			break;
	}
}

void HighScore(int level)
{
	int static pos;
	pos = 1;
	POINT cursorPosition;
	int mX,mY,idx;
	MakeListScore(&idx);
	printf("%d %d\n", idx, &idx);
	//delay(100);
	EasyScore(level);

	while(1){
		GetCursorPos(&cursorPosition);
		mX = cursorPosition.x;
		mY = cursorPosition.y;
	
		// sesudah
		if (GetAsyncKeyState(VK_LBUTTON) and mX >= 570 and mX <= 610 and mY >= 350)
		{
			readimagefile("desain/highscore/kanandown.bmp", 570, 350, 610, 390);
			delay(200);
			readimagefile("desain/highscore/kananup.bmp", 570, 350, 610, 390);
			pos = pos + 1;
			Click(&pos,level);
		}
		if (GetAsyncKeyState(VK_LBUTTON) and mX >= 180 and mX <= 220 and mY >= 350)
		{
			readimagefile("desain/highscore/kiridown.bmp", 180, 350, 220, 390);
			delay(200);
			readimagefile("desain/highscore/kiriup.bmp",180, 350, 220, 390);
			pos = pos - 1;
			Click(&pos,level);
		}
		if (GetAsyncKeyState(VK_LBUTTON) and mX >= 736 and mX <= 781 and mY >= 22)
		{
			readimagefile("desain/highscore/backdown.bmp", 736,22,781,67);
			delay(100);
			readimagefile("desain/highscore/back.bmp", 736,22,781,67);
			MainMenu();
			break;
		}
	}
}
