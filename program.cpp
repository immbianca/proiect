#include<graphics.h>
#include<windows.h>
#include<iostream.h>
#include<fstream>
#include<string>
void instructiuni()
{
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 1);
    int x = 10;
    int y = 20;
    int lineHeight = 20;
    int windowHeight = getmaxy(); 

    std::ifstream file("Assets/fisiere/instructiuni.txt");
    if (!file.is_open()) {
        outtextxy(10, y, "Eroare la deschiderea fisierului!");
        getch();
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (y > windowHeight - lineHeight) {
            outtextxy(10, y, "Text prea lung pentru ecran!");
            return;
        }
        outtextxy(x, y, const_cast<char*>(line.c_str()));
        y += lineHeight;
    }

    file.close();
}
void setari()
{
	outtextxy(200, 200, "Sunet:");
	outtextxy(200,300,"Rezolutie:");
}
bool pagina_principala() {
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
				return 1;
                break;
            case 1:
                cleardevice();
                outtextxy(100, 100, "Meniul instructiuni");
				instructiuni();
                getch();
				return 1;
                break;
            case 2:
                cleardevice();
                outtextxy(100, 100, "Meniul Setari");
				setari();
                getch();
				return 1;
                break;
            case 3:
                running = false;
				return 0;
                break;
            }
            break;
        }
    }
}
int main()
{
	bool var=true;
	int screenWidth= GetSystemMetrics(SM_CXSCREEN);
	int screenHeight= GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "Turnurie din Hanoi");
	while(var)
	{
	 setbkcolor(WHITE);
	 cleardevice();

	 setcolor(RED);
	 settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
	 outtextxy(100, 150, "Turnurile din Hanoi");

	readimagefile("Assets/images/turnuri_v1.jpg", 950, 100, 1450, 700);
	var=pagina_principala();
	}
    closegraph();
    return 0;
}
