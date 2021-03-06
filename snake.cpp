//#include <stdlib.h>
#include <graphics.h>
#include <stdio.h>
#include <time.h>
//#include <iostream>
//#include <sstream>


const int XWindow = 270;
const int YWindow = 360;
const int XFixWind = 8;
const int YFixWind = 4;

const int XGameWind = 360;
const int YGameWind = 480;
bool isLButtonDown()
{
  SHORT state = GetAsyncKeyState(VK_LBUTTON);
  return (state & 0x8000) != 0;
}

void CursXYPos(int &PosX, int &PosY){
	RECT WindowPos;
	POINT CursPos;
	GetWindowRect(GetForegroundWindow(), &WindowPos);
	GetCursorPos(&CursPos);
	PosX = CursPos.x - WindowPos.left - XFixWind;
	PosY = CursPos.y - WindowPos.bottom+YWindow - YFixWind;	
}

void game();

void GameOver(int Speed, int Length){
	int Score = (500-Speed)*Length;
	int PosX,PosY;
	char Text[16];
	setcolor(BLUE);
	rectangle (XGameWind/2-100, YGameWind/2-100, XGameWind/2+100, YGameWind/2);
	setfillstyle(1,BLACK);
	floodfill(XGameWind/2,YGameWind/2-50,BLUE);
	setcolor(WHITE);
	settextstyle(3,HORIZ_DIR,4);
	outtextxy(XGameWind/2-83,YGameWind/2-95,"Game Over");
	settextstyle(3,HORIZ_DIR,2);
	outtextxy(XGameWind/2-50,YGameWind/2-60,"Your Score:");
	sprintf (Text, "%d", Score);
	outtextxy(XGameWind/2-25,YGameWind/2-30,Text);
	
	setcolor(BLUE);
	rectangle (XGameWind/2-150, YGameWind/2+35, XGameWind/2-20, YGameWind/2+100);
	setfillstyle(1,BLACK);
	floodfill(XGameWind/2-40,YGameWind/2+50,BLUE);
			
	rectangle (XGameWind/2+20, YGameWind/2+35, XGameWind/2+150, YGameWind/2+100);
	setfillstyle(1,BLACK);
	floodfill(XGameWind/2+40,YGameWind/2+50,BLUE);
		
	setcolor(WHITE);
	outtextxy(XGameWind/2-134, YGameWind/2+55,"New Game");
	outtextxy(XGameWind/2+38, YGameWind/2+55,"Main Menu");
	while (true){
		delay(1);
		CursXYPos(PosX,PosY);
		if ((PosX>=(XGameWind/2-150))&&(PosY>=(YGameWind/2-85))&&(PosX<=(XGameWind/2-20))&&(PosY<=(YGameWind/2-20))){
			setcolor(BLUE);
			outtextxy(XGameWind/2-134, YGameWind/2+55,"New Game");
			while ((PosX>=(XGameWind/2-150))&&(PosY>=(YGameWind/2-85))&&(PosX<=(XGameWind/2-20))&&(PosY<=(YGameWind/2-20))){
				CursXYPos(PosX,PosY);
				if (isLButtonDown()){
					closegraph();
					game();
					return;
				}
			}
			setcolor(WHITE);
			outtextxy(XGameWind/2-134, YGameWind/2+55,"New Game");
		}
		
		
		if ((PosX>=(XGameWind/2+20))&&(PosY>=(YGameWind/2-85))&&(PosX<=(XGameWind/2+150))&&(PosY<=(YGameWind/2-20))){
			setcolor(BLUE);
			outtextxy(XGameWind/2+38, YGameWind/2+55,"Main Menu");
			while ((PosX>=(XGameWind/2+20))&&(PosY>=(YGameWind/2-85))&&(PosX<=(XGameWind/2+150))&&(PosY<=(YGameWind/2-20)))
				CursXYPos(PosX,PosY);
			setcolor(WHITE);
			outtextxy(XGameWind/2+38, YGameWind/2+55,"Main Menu");
		}
		
	}
	
	getch();
}

int LVL(int Xprint,int Yprint){
	initwindow(XWindow,YWindow);
	char *text[]={
		"Select LVL",	//0
		"Easy",			//1
		"Medium",		//2
		"Hard"			//3
	};
	int PosX,PosY;
	settextstyle(3,HORIZ_DIR,3);
	outtextxy(Xprint-8,Yprint,text[0]);
	setcolor(2);
	settextstyle(3,HORIZ_DIR,1);
	outtextxy(Xprint+27,Yprint+50,text[1]);
	setcolor(14);
	outtextxy(Xprint+13,Yprint+80,text[2]);
	setcolor(4);
	outtextxy(Xprint+27,Yprint+110,text[3]);
	while (true){
		delay(1);
		CursXYPos(PosX,PosY);
		if ((PosX>Xprint+10)&&(PosX<Xprint+85)&&(PosY>Yprint+45)&&(PosY<Yprint+80)){
			setcolor(15);
			outtextxy(Xprint+16,Yprint+50,">");
			outtextxy(Xprint+68,Yprint+50,"<");
			while ((PosX>Xprint+10)&&(PosX<Xprint+85)&&(PosY>Yprint+45)&&(PosY<Yprint+80)){
				CursXYPos(PosX,PosY);
				if (isLButtonDown()) {
					closegraph();
					return 400;
				}
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
				CursXYPos(PosX,PosY);
				if (isLButtonDown()) {
					closegraph();
					return 300;
				}
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
				CursXYPos(PosX,PosY);
				if (isLButtonDown()) {
					closegraph();
					return 200;
				}
			}
			setcolor(0);
			outtextxy(Xprint+16,Yprint+110,">");
			outtextxy(Xprint+68,Yprint+110,"<");			
		}
		
	//	printf("%d , %d\n%d , %d",WindowPos.left,WindowPos.bottom-360, CursPos.x - WindowPos.left - XFixWind, CursPos.y - WindowPos.bottom+360 - YFixWind);
	
	//	circle(PosX,PosY,15);
		system("CLS");
	}
	
}
void PrintCircle(int x, int y, int col){
	setcolor(col);
	circle(x*29+16,y*29+16,14);
	setfillstyle(1,col);
	floodfill(x*29+10,y*29+10,col);
}


void game(){
	char Button,_Button;
	int Speed;
	int Length;
	int Life = 1;
	struct _SnakePos{
		int X;
		int Y;
	}SnakePos[(XGameWind/30)*(YGameWind/30)];
	struct _FructPos{
		int RdX;
		int RdY;
	}FructPos;
	SnakePos[0].X=1;
	SnakePos[0].Y=7;
	FructPos.RdX=1;
	FructPos.RdY=7;
	Length=0;
	Button = 'd';
	Speed = LVL(80,120);  //default x=80,y=120;
	initwindow(XGameWind,YGameWind); //3:4
	while (true){
		
		if ((FructPos.RdX==SnakePos[0].X)&&(FructPos.RdY==SnakePos[0].Y)){
			Length++;	
			Rand:;
			FructPos.RdX=rand()%12;
			FructPos.RdY=rand()%16;
			
			for (int i=0;i!=Length;i++){
				if ((FructPos.RdX==SnakePos[i].X)&&(FructPos.RdY==SnakePos[i].Y)){
					goto Rand;
				}
			}		
		}
		
		PrintCircle(FructPos.RdX,FructPos.RdY,WHITE);
		PrintCircle(SnakePos[1].X,SnakePos[1].Y,GREEN);
		PrintCircle(SnakePos[0].X,SnakePos[0].Y,RED);
		
		for (int i=Length+1;i!=0;i--){
			SnakePos[i].X=SnakePos[i-1].X;
			SnakePos[i].Y=SnakePos[i-1].Y;
		}
		delay(Speed/2);
		if (kbhit()!=0) _Button=getch();
		delay(Speed/2);
		if ((_Button=='w')&&(Button=='s') || (_Button=='s')&&(Button=='w') || (_Button=='a')&&(Button=='d') || (_Button=='d')&&(Button=='a')) {;} else {
			if ((_Button=='a') || (_Button=='d') || (_Button=='w') || (_Button=='s'))
				Button=_Button;
		}
		if (Button=='w') SnakePos[0].Y--;
		if (Button=='s') SnakePos[0].Y++;
		if (Button=='a') SnakePos[0].X--; 
		if (Button=='d') SnakePos[0].X++;	
		
		if ((SnakePos[0].X<0)||(SnakePos[0].X>=(XGameWind/30))||(SnakePos[0].Y<0)||(SnakePos[0].Y>=(YGameWind/30))){
			Life=0;
			printf("1");
		}
			
		for (int i=Length;i>0;i--){
			if ((SnakePos[i].X==SnakePos[0].X)&&(SnakePos[i].Y==SnakePos[0].Y)){
				Life=0;
				printf("2");
			}		
		}
		
		if (Life==0){
			GameOver(Speed,Length);
			return;
		}
		
		PrintCircle(SnakePos[Length+1].X,SnakePos[Length+1].Y,BLACK);
	}	
}


int main(){
	//settextstyle(3,HORIZ_DIR,2);
	srand(time(NULL));
	using namespace std;
	game();
//	initwindow(XGameWind,YGameWind);
//	GameOver(200,10);
	closegraph();
	return 0;
}

