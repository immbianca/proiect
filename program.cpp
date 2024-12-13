#include<graphics.h>
#include<windows.h>
#include<iostream.h>

void pagina_principala() {
    int option=0;
    bool running=true;

    while(running){
        setcolor(BLUE);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);

        if (option == 0) setcolor(GREEN);
        outtextxy(200, 350, "START");
        setcolor(BLUE);
        if (option == 1) setcolor(GREEN);
        outtextxy(200, 400, "INSTRUCTIUNI");
        setcolor(BLUE);
        if (option == 2) setcolor(GREEN);
        outtextxy(200, 450, "SETARI");
        setcolor(BLUE);
        if (option == 3) setcolor(GREEN);
        outtextxy(200, 500, "EXIT");
        setcolor(BLUE);

        int key = getch();
        switch (key) {
        case 72: 
            option = (option - 1 + 4) % 4;
            break;
        case 80: 
            option = (option + 1) % 4;
            break;
        case 13: 
            switch (option) {
            case 0:
                cleardevice();
                outtextxy(100, 100, "Meniul Start");
                getch();
                break;
            case 1:
                cleardevice();
                outtextxy(100, 100, "Meniul instructiuni");
                getch();
                break;
            case 2:
                cleardevice();
                outtextxy(100, 100, "Meniul Setari");
                getch();
                break;
            case 3:
                running = false;
                break;
            }
            break;
        }
    }
}
int main()
{
	int screenWidth= GetSystemMetrics(SM_CXSCREEN);
	int screenHeight= GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "Turnurie din Hanoi");
	
	 setbkcolor(WHITE);
	 cleardevice();

	 setcolor(RED);
	 settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
	 outtextxy(100, 150, "Turnurile din Hanoi");

	readimagefile("Assets/images/turnuri_v1.jpg", 950, 100, 1450, 700);
	pagina_principala();
	
    closegraph();
    return 0;
}
