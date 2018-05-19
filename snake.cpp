#include <stdlib.h>
#include <graphics.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
//#include <Windows.h>

const int XWindow = 270;
const int YWindow = 360;
const int XFixWind = 8;
const int YFixWind = 4;




void LVL(int Xprint,int Yprint){
	char *text[]={
		"Select LVL",	//0
		"Easy",			//1
		"Medium",		//2
		"Hard"			//3
	};

	RECT WindowPos;
	POINT CursPos;
	int PosX,PosY;
	outtextxy(Xprint,Yprint,text[0]);
	setcolor(2);
	settextstyle(3,HORIZ_DIR,1);
	outtextxy(Xprint+27,Yprint+50,text[1]);
	setcolor(14);
	outtextxy(Xprint+13,Yprint+80,text[2]);
	setcolor(4);
	outtextxy(Xprint+27,Yprint+110,text[3]);
	while (1){
		GetWindowRect(GetForegroundWindow(), &WindowPos);
		GetCursorPos(&CursPos);
		PosX = CursPos.x - WindowPos.left - XFixWind;
		PosY = CursPos.y - WindowPos.bottom+360 - YFixWind;
		
		if ((PosX>Xprint+10)&&(PosX<Xprint+85)&&(PosY>Yprint+45)&&(PosY<Yprint+80)){
			setcolor(15);
			outtextxy(Xprint+16,Yprint+50,">");
			outtextxy(Xprint+68,Yprint+50,"<");
			while ((PosX>Xprint+10)&&(PosX<Xprint+85)&&(PosY>Yprint+45)&&(PosY<Yprint+80)){
				GetWindowRect(GetForegroundWindow(), &WindowPos);
				GetCursorPos(&CursPos);
				PosX = CursPos.x - WindowPos.left - XFixWind;
				PosY = CursPos.y - WindowPos.bottom+360 - YFixWind;	
			}
			setcolor(0);
			outtextxy(Xprint+16,Yprint+50,">");
			outtextxy(Xprint+68,Yprint+50,"<");			
		}
		
		if ((PosX>Xprint-4)&&(PosX<Xprint+99)&&(PosY>Yprint+75)&&(PosY<Yprint+110)){
			setcolor(15);
			outtextxy(Xprint+2,Yprint+80,">");
			outtextxy(Xprint+82,Yprint+80,"<");
			while ((PosX>Xprint-4)&&(PosX<Xprint+99)&&(PosY>Yprint+75)&&(PosY<Yprint+110)){
				GetWindowRect(GetForegroundWindow(), &WindowPos);
				GetCursorPos(&CursPos);
				PosX = CursPos.x - WindowPos.left - XFixWind;
				PosY = CursPos.y - WindowPos.bottom+360 - YFixWind;	
			}
			setcolor(0);
			outtextxy(Xprint+2,Yprint+80,">");
			outtextxy(Xprint+82,Yprint+80,"<");			
		}		
		
		if ((PosX>Xprint+10)&&(PosX<Xprint+85)&&(PosY>Yprint+110)&&(PosY<Yprint+140)){
			setcolor(15);
			outtextxy(Xprint+16,Yprint+110,">");
			outtextxy(Xprint+68,Yprint+110,"<");
			while ((PosX>Xprint+10)&&(PosX<Xprint+85)&&(PosY>Yprint+110)&&(PosY<Yprint+140)){
				GetWindowRect(GetForegroundWindow(), &WindowPos);
				GetCursorPos(&CursPos);
				PosX = CursPos.x - WindowPos.left - XFixWind;
				PosY = CursPos.y - WindowPos.bottom+360 - YFixWind;	
			}
			setcolor(0);
			outtextxy(Xprint+16,Yprint+110,">");
			outtextxy(Xprint+68,Yprint+110,"<");			
		}
		
		printf("%d , %d\n%d , %d",WindowPos.left,WindowPos.bottom-360, CursPos.x - WindowPos.left - XFixWind, CursPos.y - WindowPos.bottom+360 - YFixWind);
		//circle(PosX,PosY,4);
		system("CLS");
	}
	
}
void game(){
	initwindow(XWindow,YWindow); //3:4
	settextstyle(3,HORIZ_DIR,2);
	LVL(80,120); //default x=80,y=140;
}


int main(){
	game();
	return 0;
}

