#include<graphics.h>
#include<windows.h>



int main()
{
	int screenWidth= GetSystemMetrics(SM_CXSCREEN);
	int screenHeight= GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "Turnurie din Hanoi");
	
	setbkcolor(WHITE);
	cleardevice();
	
    setcolor(BLUE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR, 3);
	outtextxy(200,200,"START");
	outtextxy(200,250,"INSTRUCTIUNI");
	outtextxy(200,300,"SETARI");
	outtextxy(200,350,"EXIT");
	
	readimagefile("Assets/images/turnuri_v1.jpg",800,200, 900,500);
    getch();
    closegraph();
    return 0;
}
