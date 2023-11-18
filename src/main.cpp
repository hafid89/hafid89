#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include <limits.h>
#include <string>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <fstream>
#include <sstream>
#include "signup.h"
#include "animasiload.h"
#include "datapasien.h"
using namespace std;
void gosoxy(int x, int y)
{
     move(y, x);
}

void gopoxy(int x, int y)
{
     move(y, x);

     attron(COLOR_PAIR(1));
     printw("||");
     attroff(COLOR_PAIR(1));
     refresh();
}

void datar1(int x, int y, int batas)
{
     if (x >= 1 && x <= 250 && y >= 1 && y <= 55)
     {
          for (x >= 1; x <= batas; x++)
          {
               refresh();
               gopoxy(x, y);
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
               gopoxy(x, y);
          }
     }
}
int main()
{

     initscr(); // Memulai mode ncurses
menuawal:
     load();
     srand(time(0));
     char user[100], pass[100];
     int pilihan, awal;
     muat();
     clear();

     refresh();
     // gosoxy(96, 2);
     printw("\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 4);
     printw("    ++==================================++\n ");
     refresh(); // Perbarui tampilan
     gosoxy(96, 5);
     printw("  (+)                                    (+)\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 6);
     printw("  ||   SELAMAT DATANG DI RUMAH SAKIT      ||\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 7);
     printw("  ||       Dr.Hafid Dwi Saputra           ||\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 8);
     printw("  ||                                      ||\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 9);
     printw("  ||++++++++++++++++++++++++++++++++++++++||\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 10);
     printw("  ||                                      ||\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 11);
     printw("  ||        Pengunjung di harap           ||\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 12);
     printw("  ||    untuk login terlebih dahulu       ||\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 13);
     printw("  ||     demi kenyamanan pelayanan        ||\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 14);
     printw("  ||                                      ||\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 15);
     printw("  ||++++++++++++++++++++++++++++++++++++++||\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 16);
     printw("  (+)                                    (+)\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 17);
     printw("    ++==================================++\n ");
     refresh(); // Perbarui tampilan
     gosoxy(96, 18);
     printw("\n\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 19);
     printw(" ########################################\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 20);
     printw(" Silahkan memilih terlebih dahulu!!\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 21);
     printw("        1. Login\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 22);
     printw("        2. Sign up\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 23);
     printw("        3. Exit\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 24);
     printw(" Masukkan pilihan anda : ");

     datar1(1, 1, 245);
     datar1(1, 54, 245);
     turun1(1, 1, 54);
     turun1(245, 2, 54);
     refresh(); // Perbarui tampilan
     gosoxy(122, 24);
     scanw("%d", &awal);
     refresh(); // Perbarui tampilan
     gosoxy(96, 25);
     printw(" ########################################\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 26);
     printw(" tekan [enter]\n");
     refresh(); // Perbarui tampilan
     gosoxy(96, 27);
     cin.get(); // pause sementara!!
     switch (awal)
     {
     case 1:

     login:
          load();
          refresh();
          //
          printw("\t\t\t\t\t\t\t\t\t\t\t\t      Please Login Rs.Hafid Account First!\n\n");
          printw("\t\t\t\t\t\t\t\t\t\t\t\t[]--Silahkan isi username akun anda :-----------------[]\n");
          printw("\t\t\t\t\t\t\t\t\t\t\t\t[]                                                    []\n");
          printw("\t\t\t\t\t\t\t\t\t\t\t\t               ");
          scanw("%99[^\n]", user); // Mendapatkan input hingga karakter newline atau 99 karakter, termasuk spasi
          refresh();               // Perbarui tampilan
          printw("\t\t\t\t\t\t\t\t\t\t\t\t[]                                                    []\n");
          printw("\t\t\t\t\t\t\t\t\t\t\t\t[]----------------------------------------------------[]\n");
          printw("\n");
          printw("\n");
          printw("\t\t\t\t\t\t\t\t\t\t\t\t[]--Silahkan isi password akun anda :-----------------[]\n");
          printw("\t\t\t\t\t\t\t\t\t\t\t\t[]                                                    []\n");
          printw("\t\t\t\t\t\t\t\t\t\t\t\t               ");
          scanw("%99[^\n]", pass); // Mendapatkan input hingga karakter newline atau 99 karakter, termasuk spasi
          refresh();               // Perbarui tampilan
          printw("\t\t\t\t\t\t\t\t\t\t\t\t[]                                                    []\n");
          printw("\t\t\t\t\t\t\t\t\t\t\t\t[]----------------------------------------------------[]\n");
          printw("\t\t\t\t\t\t\t\t\t\t\t\ttekan [enter]");
          refresh(); // Perbarui tampilan
          cin.get(); // pause sementara!!
          refresh(); // Perbarui tampilan
          if (verifikasiAkun(user, pass))
          {
               load();
               //

          utama:
               clear();
               refresh();
               printw("   ++==================================++\n ");
               refresh();
               printw("(+)                                    (+)\n ");
               refresh();
               printw("||   SELAMAT DATANG DI RUMAH SAKIT      ||\n");
               refresh();
               printw(" ||       Dr.Hafid Dwi Saputra           ||\n");
               refresh();
               printw(" ||                                      ||\n");
               refresh();
               printw(" ||++++++++++++++++++++++++++++++++++++++||\n");
               refresh();
               printw(" ||                                      ||\n");
               refresh();
               printw("         %s             \n", user);
               refresh();
               printw(" ||   Selamat Datang di Menu Informasi   ||\n");
               refresh();
               printw(" ||   Silahkan tentukan pilihan anda!!   ||\n");
               refresh();
               printw(" ||                                      ||\n");
               refresh();
               printw(" ||++++++++++++++++++++++++++++++++++++++||\n");
               refresh();
               printw(" (+)                                    (+)\n");
               refresh();
               printw("   ++==================================++\n ");
               refresh();
               printw("\n\n");
               refresh();
               printw("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
               refresh();
               printw("1. Registrasi pemeriksaan\n");
               refresh();
               printw("2. Informasi Kunjungan Pasien\n");
               refresh();
               printw("3. Cek Status Pemeriksaan\n");
               refresh();
               printw("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
               refresh();
               printw("Isi pilihan anda :");
               refresh();
               scanw("%d", &pilihan);
               if (pilihan == 1)
               {
                    char registrasiout;
                    clear();
                    registrasi();
                    printw("Ingin kembali ke menu utama atau exit?\n");
                    printw("back(y)/exit(n)\n");
                    scanw("%c", &registrasiout);
                    if (registrasiout == 'y')
                    {
                         goto utama;
                    }
                    else if (registrasiout == 'n')
                    {
                         break;
                    }
               }
               else
               {

                    break;
               }
          }
          else if (!verifikasiAkun(user, pass))
          {

               clear();
               refresh();
               printw("\t\t\t\t\t\t\t\t\t\t\t\tUsername atau Password salah!\n\t\t\t\t\t\t\t\t\t\t\t\tSilahkan coba lagi\n\t\t\t\t\t\t\t\t\t\t\t\t[Enter]\n");
               refresh();
               cin.get();
               refresh();
               goto login;
               break;
          }

     case 2:
          load();
          functionsignup();
          goto menuawal;
          break;
     case 3:
          break;

     default:
          load();
          printw("Pilihan tidak valid.\n");
          cin.get();
          refresh();
          goto menuawal;
          break;
     }

     return 0;

     endwin(); // Mengakhiri mode ncurses
}
