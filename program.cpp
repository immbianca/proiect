#include<graphics.h>
#include<windows.h>

int main()
{
	int screenWidth= GetSystemMetrics(SM_CXSCREEN);
	int screenHeight= GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "Turnurie din Hanoi");
    circle(100, 100, 50);
    getch();
    closegraph();
    return 0;
}
