#include<graphics.h>

int main(int argc, char const *argv[])
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    circle(100, 100, 50);
    getch();
    closegraph();
    return 0;
}
