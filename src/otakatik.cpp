

#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <iostream>
using namespace std;

void gotoxy(int x, int y)
{
    move(y, x);

    attron(COLOR_PAIR(1));
    printw("||");
    attroff(COLOR_PAIR(1));
    refresh();
}
void goloxy(int x, int y)
{
    move(y, x);
}

void datar1(int x, int y, int batas)
{
    if (x >= 1 && x <= 250 && y >= 1 && y <= 55)
    {
        for (x >= 1; x <= batas; x++)
        {
            refresh();
            gotoxy(x, y);
        }
    }
}
void turun1(int x, int y, int batas)
{
    if (x >= 1 && x <= 250 && y >= 1 && y <= 54)
    {
        for (y >= 2; y <= batas; y++)
        {
            refresh();
            gotoxy(x, y);
        }
    }
}

int main()
{
    int x, y, a, b, c, d, e, f, b1, b3, b6, b8;
    initscr();
    start_color();                          // Inisialisasi mode warna
    init_pair(1, COLOR_BLACK, COLOR_WHITE); // Definisikan kombinasi warna
    init_pair(2, COLOR_GREEN, COLOR_WHITE);
    bkgd(COLOR_PAIR(2));
    datar1(1, 1, 250);
    datar1(1, 50, 250);
    turun1(1, 2, 50);
    turun1(250, 2, 50);
    datar1(1, 45, 100);
    turun1(30, 2, 44);
    turun1(50, 2, 44);
    turun1(100, 2, 49);
    goloxy(200, 8);
    printw("Wrwwrwf");
    refresh();

    goloxy(200, 10);
    printw("Wawdawdwd");
    refresh();
    clear();

    cin.get();
    endwin();
    return 0;
}
