#ifndef ANIMASILOAD_H
#define ANIMASILOAD_H
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <iostream>
#include <string.h>
using namespace std;

void delay(void)
{
    usleep(10000); // Menggunakan usleep untuk delay 1 ms
}

void gotoxy(int x, int y)
{
    move(y, x); // Menggunakan ncurses untuk pindah kursor
}

void berulang(int j)
{
    gotoxy(117, 22);

    attron(COLOR_PAIR(1));            // Aktifkan pasangan warna
    printw("L O A D I N G %d %%", j); // Menggunakan printw untuk menulis teks
    attroff(COLOR_PAIR(1));           // Nonaktifkan pasangan warna
}

void load()
{
    int i;
    char ulang;

    clear();
    refresh();
    start_color();                          // Mulai mode warna
    init_pair(1, COLOR_BLACK, COLOR_GREEN); // Pasangan warna merah dengan latar belakang hitam

    init_pair(2, COLOR_GREEN, COLOR_GREEN); // Pasangan warna merah dengan latar belakang hitam
    bkgd(COLOR_PAIR(2));                    // Set latar belakang menggunakan pasangan warna

    for (i = 100; i < 150; i++)
    {
        gotoxy(i, 20);
        attron(COLOR_PAIR(1));  // Aktifkan pasangan warna
        printw("#");            // Cetak teks dengan warna merah
        attroff(COLOR_PAIR(1)); // Nonaktifkan pasangan warna
        gotoxy(i, 24);
        attron(COLOR_PAIR(1));  // Aktifkan pasangan warna
        printw("#");            // Cetak teks dengan warna merah
        attroff(COLOR_PAIR(1)); // Nonaktifkan pasangan warna
        delay();
        refresh(); // Perbarui tampilan
    }
    gotoxy(100, 21);
    attron(COLOR_PAIR(1)); // Aktifkan pasangan warna
    printw("||");
    attroff(COLOR_PAIR(1)); // Nonaktifkan pasangan warna
    gotoxy(100, 22);
    attron(COLOR_PAIR(1)); // Aktifkan pasangan warna
    printw("||");
    attroff(COLOR_PAIR(1)); // Nonaktifkan pasangan warna
    gotoxy(100, 23);
    attron(COLOR_PAIR(1)); // Aktifkan pasangan warna
    printw("||");
    attroff(COLOR_PAIR(1)); // Nonaktifkan pasangan warna
    gotoxy(148, 21);
    attron(COLOR_PAIR(1)); // Aktifkan pasangan warna
    printw("||");
    attroff(COLOR_PAIR(1)); // Nonaktifkan pasangan warna
    gotoxy(148, 22);
    attron(COLOR_PAIR(1)); // Aktifkan pasangan warna
    printw("||");
    attroff(COLOR_PAIR(1)); // Nonaktifkan pasangan warna
    gotoxy(148, 23);
    attron(COLOR_PAIR(1)); // Aktifkan pasangan warna
    printw("||");
    attroff(COLOR_PAIR(1)); // Nonaktifkan pasangan warna
    for (int j = 1; j <= 100; j++)
    {
        berulang(j);
        refresh();
        usleep(10000); // Menggunakan usleep untuk memberikan jeda 100ms (0.1 detik)
    }
    clear();
}
#endif