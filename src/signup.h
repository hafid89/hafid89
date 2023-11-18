#ifndef SIGNUP_H
#define SIGNUP_H
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <ncurses.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <fstream>
#include <sstream>
using namespace std;

struct Akun
{
    std::string user;
    std::string pass;
};
std::vector<Akun> databaseAkun;

void tambahAkun(std::string user, std::string pass)
{
    Akun akun = {user, pass};
    databaseAkun.push_back(akun);
}

void simpanAkunKeFile()
{
    std::ofstream file("hafidrs.txt");

    if (file.is_open())
    {
        for (const Akun &akun : databaseAkun)
        {
            file << akun.user << " " << akun.pass << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "Gagal membuka file." << std::endl;
    }
}

void muatAkunDariFile()
{
    std::ifstream file("hafidrs.txt");

    if (file.is_open())
    {
        std::string user, pass;

        while (file >> user >> pass)
        {
            tambahAkun(user, pass);
        }

        file.close();
    }
    else
    {
        std::cout << "Gagal membuka file." << std::endl;
    }
}

bool verifikasiAkun(std::string user, std::string pass)
{
    for (const Akun &akun : databaseAkun)
    {
        if (akun.user == user && akun.pass == pass)
        {
            return true;
        }
    }
    return false;
}

bool isValid(const std::string &input, int minLength, int maxLength)
{
    if (input.length() < minLength || input.length() > maxLength)
    {
        return false;
    }

    for (char c : input)
    {
        if (!isdigit(c))
        {
            return false; // Karakter bukan angka
        }
    }
    int angka = std::stoi(input);
    if (input.length() == 2)
    {
        if (angka >= 1 && angka <= 31)
        {
            return true; // Angka di antara 1 dan 31
        }
    }
    else if (input.length() == 4)
    {
        if (angka >= 1000 && angka <= 2023)
        {
            return true;
        }
    }
    return false; // Tidak memenuhi kondisi di atas
}

std::string generateRandomString(int length)
{
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::string randomString;

    for (int i = 0; i < length; ++i)
    {
        randomString.push_back(characters[rand() % characters.length()]);
    }

    return randomString;
}
void muat()
{
    muatAkunDariFile();
}

void goboxy(int x, int y)
{
    move(y, x);
}
void gocoxy(int x, int y)
{
    move(y, x);

    attron(COLOR_PAIR(1));
    printw("||");
    attroff(COLOR_PAIR(1));
    refresh();
}

void datar2(int x, int y, int batas)
{
    if (x >= 1 && x <= 250 && y >= 1 && y <= 55)
    {
        for (x >= 1; x <= batas; x++)
        {
            refresh();
            gocoxy(x, y);
        }
    }
}
void turun2(int x, int y, int batas)
{
    if (x >= 1 && x <= 250 && y >= 1 && y <= 54)
    {
        for (y >= 2; y <= batas; y++)
        {
            refresh();
            gocoxy(x, y);
        }
    }
}
void functionsignup()
{

    char fn[100], ln[100];
    int gp;
createakun:
    clear();
    refresh();
    goboxy(96, 4);
    printw("       Create a Rs.Hafid Account\n");
    refresh();
    goboxy(96, 5);
    printw("           Enter your name!!\n\n");
    refresh();
    goboxy(96, 6);
    printw("[]--Frist Name (Max 5 char)----------------[]\n");
    refresh();
    goboxy(96, 7);
    printw("[]                                         []\n");
    refresh();
    goboxy(96, 9);
    printw("[]                                         []\n");
    refresh();
    goboxy(96, 10);
    printw("[]-----------------------------------------[]\n\n\n");
    refresh();
    goboxy(96, 8);
    printw("[]");
    refresh();
    goboxy(139, 8);
    printw("[]\n");

    datar2(1, 1, 245);
    datar2(1, 54, 245);
    turun2(1, 1, 54);
    turun2(245, 2, 54);
    refresh();
    goboxy(110, 8);
    scanw("%99[^\n]", fn);
    string Fn = fn;
    refresh();
    goboxy(96, 11);
    printw("[]--Last Name (Max 5 char)-----------------[]\n");
    refresh();
    goboxy(96, 12);
    printw("[]                                         []\n");
    refresh();
    goboxy(96, 14);
    printw("[]                                         []\n");
    refresh();
    goboxy(96, 15);
    printw("[]-----------------------------------------[]\n");
    refresh();
    goboxy(96, 13);
    printw("[]");
    refresh();
    goboxy(139, 13);
    printw("[]\n");
    refresh();
    datar2(1, 1, 245);
    datar2(1, 54, 245);
    turun2(1, 1, 54);
    turun2(245, 2, 54);
    goboxy(110, 13);
    scanw("%99[^\n]", ln);
    string Ln = ln;
    refresh();
    goboxy(96, 16);
    printw("tekan [enter]");

    for (char &fn : Fn)
    {
        fn = tolower(fn);
    }
    refresh();
    cin.get(); // pause sementara!!
    if (Fn >= "a" && Fn <= "z")
    {
        clear();
        refresh();
    isitanggal:
        noecho();             // Tidak menampilkan input
        cbreak();             // Mengaktifkan mode karakter-by-karakter
        keypad(stdscr, TRUE); // Mengaktifkan tombol fungsi dan panah

        goboxy(100, 4);
        printw("       Informasi dasar\n");
        refresh();
        goboxy(100, 5);
        printw("Masukkan tanggal lahir hingga gender!!\n\n");
        refresh();
        goboxy(92, 6);
        printw("Masukkan Tanggal: ");
        refresh();
        goboxy(89, 7);
        printw("[]=====================[]\n");
        refresh();
        goboxy(89, 8);
        printw("[]                     []\n");
        refresh();
        goboxy(89, 9);
        printw("[]");
        refresh();
        goboxy(112, 9);
        printw("[]\n");
        refresh();
        goboxy(89, 10);
        printw("[]                     []\n");
        refresh();
        goboxy(89, 11);
        printw("[]=====================[]\n");
        refresh();
        goboxy(122, 6);
        printw("Masukkan Bulan: ");
        refresh();
        goboxy(119, 7);
        printw("[]=====================[]\n");
        refresh();
        goboxy(119, 8);
        printw("[]                     []\n");
        refresh();
        goboxy(119, 9);
        printw("[]");
        refresh();
        goboxy(142, 9);
        printw("[]\n");
        refresh();
        goboxy(119, 10);
        printw("[]                     []\n");
        refresh();
        goboxy(119, 11);
        printw("[]=====================[]\n");
        refresh();

        goboxy(92, 15);
        printw("Masukkan Tahun: ");
        refresh();
        goboxy(89, 16);
        printw("[]=====================[]\n");
        refresh();
        goboxy(89, 17);
        printw("[]                     []\n");
        refresh();
        goboxy(89, 18);
        printw("[]");
        refresh();
        goboxy(112, 18);
        printw("[]\n");
        refresh();
        goboxy(89, 19);
        printw("[]                     []\n");
        refresh();
        goboxy(89, 20);
        printw("[]=====================[]\n");
        refresh();
        goboxy(122, 15);
        printw("Masukkan Gender: ");
        refresh();
        goboxy(119, 16);
        printw("[]=====================[]\n");
        refresh();
        goboxy(119, 17);
        printw("[]                     []\n");
        refresh();
        goboxy(119, 18);
        printw("[]");
        refresh();
        goboxy(142, 18);
        printw("[]\n");
        refresh();
        goboxy(119, 19);
        printw("[]                     []\n");
        refresh();
        goboxy(119, 20);
        printw("[]=====================[]\n");
        refresh();
        if (true)
        {

            goboxy(109, 6);
            char tgl[100]; // Menyiapkan array untuk menyimpan string
            getstr(tgl);   // Membaca string dari pengguna
            refresh();
            goboxy(100, 9);
            printw("%s", tgl);
            refresh();
            if (isValid(tgl, 1, 2))
            {
                goto next1;
            }
            else
            {
                goboxy(89, 13);
                printw("Input tidak valid. Harap masukkan dua angka antara 1 dan 31.\n");
                refresh();
                goboxy(89, 14);
                printw("tekan enter untuk isi ulang");
                refresh();
                cin.get(); // pause sementara!!
                clear();
                goto isitanggal;
            }
        }
    next1:
        if (true)
        {

            goboxy(138, 6);
            char bln[100]; // Menyiapkan array untuk menyimpan string
            getstr(bln);   // Membaca string dari pengguna
            refresh();
            goboxy(128, 9);
            printw("%s", bln);
            refresh();
            if (true)
            {

                goboxy(111, 13);
                printw("Input valid.\n");
                refresh();
            }
        }
        if (true)
        {
        iftahun:
            goboxy(107, 15);
            char thn1[100]; // Menyiapkan array untuk menyimpan string
            getstr(thn1);   // Membaca string dari pengguna
            refresh();
            goboxy(100, 18);
            printw("%s", thn1);
            refresh();

            if (isValid(thn1, 4, 4))
            {
                goto next2;
            }
            else
            {

                goboxy(89, 22);
                printw("Input tidak valid. Harap masukkan empat angka antara 1000 dan 2100.\n");
                refresh();

                goboxy(89, 23);
                printw("tekan enter untuk isi ulang");
                refresh();
                cin.get(); // pause sementara!!
                clear();
                goto isitahun;

            isitahun:
                goboxy(89, 15);
                printw("Masukkan Tahun: ");
                refresh();
                goboxy(89, 16);
                printw("[]=====================[]\n");
                refresh();
                goboxy(89, 17);
                printw("[]                     []\n");
                refresh();
                goboxy(89, 18);
                printw("[]");
                refresh();
                goboxy(112, 18);
                printw("[]\n");
                refresh();
                goboxy(89, 19);
                printw("[]                     []\n");
                refresh();
                goboxy(89, 20);
                printw("[]=====================[]\n");
                refresh();

                goboxy(119, 15);
                printw("Masukkan Gender: ");
                refresh();
                goboxy(119, 16);
                printw("[]=====================[]\n");
                refresh();
                goboxy(119, 17);
                printw("[]                     []\n");
                refresh();
                goboxy(119, 18);
                printw("[]");
                refresh();
                goboxy(142, 18);
                printw("[]\n");
                refresh();
                goboxy(119, 19);
                printw("[]                     []\n");
                refresh();
                goboxy(119, 20);
                printw("[]=====================[]\n");
                refresh();
                goto iftahun;
            }
        }
    next2:
        if (true)
        {
        ifjk:
            goboxy(138, 15);
            char gnd[100]; // Menyiapkan array untuk menyimpan string
            getstr(gnd);   // Membaca string dari pengguna
            refresh();
            if (tolower(gnd[0]) == 'w')
            {

                goboxy(128, 18);
                printw("%s", gnd);
                refresh();

                goboxy(111, 13);
                printw("Input valid.\n");
                refresh();
            }
            else if (tolower(gnd[0]) == 'p')
            {

                goboxy(128, 18);
                printw("%s", gnd);
                refresh();

                goboxy(111, 13);
                printw("Input valid.\n");
                refresh();
            }
        }

        goboxy(111, 24);
        printw("tekan [enter]");
        refresh();
        if (true)
        {
        creategmail:
            cin.get(); // pause sementara!!
            clear();
            srand(time(0));
            echo();
            goboxy(100, 4);
            printw("             Pilih alamat Gmail Anda\n");
            refresh();

            goboxy(90, 5);
            printw("Pilih alamat Gmail atau buat alamat Gmail Anda sendiri!!\n");
            refresh();
            string randomString1 = generateRandomString(2);       // Generate string acak sepanjang 2 karakter
            string randomString2 = generateRandomString(3);       // Generate string acak sepanjang 2 karakter
            string emai = fn + randomString1 + ln + "@gmail.com"; // Menyiapkan array untuk menyimpan string
            char email1[100];
            strcpy(email1, emai.c_str());
            refresh();
            goboxy(100, 6);
            printw("1. %s\n", email1);
            refresh();
            goboxy(100, 7);
            printw("2. Buat alamat Gmail Anda sendiri\n");
            refresh();
            goboxy(95, 8);
            printw("tentukan pilihan :");
            refresh();

            goboxy(113, 8);
            scanw("%d \n", &gp);
            if (gp == 1)
            {
            gmail1:
                clear();
                echo();
                goboxy(100, 4);
                printw("             Buat sandi yang rumit!!\n");
                refresh();
                goboxy(87, 5);
                printw("Buat sandi yang rumit dengan campuran huruf,\n");
                refresh();
                goboxy(102, 6);
                printw("               angka, dan simbol\n");
                refresh();
                goboxy(98, 7);
                printw("Masukkan Sandi yang kuat: \n");
                refresh();
                char na1[100];
                goboxy(124, 7);
                getstr(na1); // Membaca string dari pengguna
                refresh();
                string sand1 = na1;
                goboxy(95, 8);
                printw("[]=====================[]\n");
                refresh();
                goboxy(95, 9);
                printw("[]                     []\n");
                refresh();
                goboxy(95, 10);
                printw("[]");
                refresh();
                goboxy(116, 10);
                printw("[]\n");
                refresh();
                goboxy(95, 11);
                printw("[]                     []\n");
                refresh();
                goboxy(95, 12);
                printw("[]=====================[]\n");
                refresh();
                goboxy(128, 7);
                printw("Masukkan Sandi yang sama : ");
                refresh();
                goboxy(154, 7);
                char kf1[100];
                getstr(kf1); // Membaca string dari pengguna
                refresh();
                string sand2 = kf1;
                goboxy(123, 8);
                printw("[]=====================[]\n");
                refresh();
                goboxy(123, 9);
                printw("[]                     []\n");
                refresh();
                goboxy(123, 10);
                printw("[]");
                refresh();
                goboxy(144, 10);
                printw("[]\n");
                refresh();
                goboxy(123, 11);
                printw("[]                     []\n");
                refresh();
                goboxy(123, 12);
                printw("[]=====================[]\n");
                refresh();
                goboxy(113, 13);
                printw("tekan [enter]");
                refresh();
                goboxy(100, 10);
                printw("%s", na1);
                refresh();
                goboxy(130, 10);
                printw("%s", kf1);
                refresh();
                cin.get();
                if (sand1 == sand2)
                {
                captcha:

                    clear();
                    int num1 = rand() % 10;
                    int num2 = rand() % 10;
                    int result = num1 + num2;
                    int captcha;

                    goboxy(100, 4);
                    printw("      Konfirmasi bahwa Anda bukan\n");
                    refresh();
                    goboxy(111, 5);
                    printw("                 robot!!\n");
                    refresh();
                    goboxy(100, 6);
                    printw("[]=====================[]\n");
                    refresh();
                    goboxy(100, 7);
                    printw("[]                     []\n");
                    refresh();
                    goboxy(100, 8);
                    printw("[]       %d  + %d        []\n", num1, num2);
                    refresh();
                    goboxy(100, 9);
                    printw("[]                     []\n");
                    refresh();
                    goboxy(100, 10);
                    printw("[]=====================[]\n");
                    refresh();
                    goboxy(100, 11);
                    printw("Berapa hasil dari penjumlahan diatas? :");
                    refresh();
                    goboxy(141, 11);
                    scanw("%d", &captcha);
                    refresh();
                    if (captcha != result)
                    {
                        goboxy(100, 12);
                        printw("Captcha salah ulangi!\n");
                        refresh();
                        goboxy(100, 13);
                        printw("tekan [enter]");
                        refresh();
                        cin.get();
                        clear();
                        goto captcha;
                    }
                    goboxy(100, 12);
                    printw("ingin kembali ke menu login(y/n):");
                    refresh();
                    char yn;
                    scanw("%c", &yn);
                    int coba = gp;
                    if (yn == 'y')
                    {
                        cin.ignore();
                        tambahAkun(email1, na1);
                        clear();
                    }
                }
            }
            else if (gp == 2)
            {
            bikingmail:
                clear();
                refresh();
                goboxy(92, 4);
                printw("Masukkan email buatan sendiri (tanpa @gmail.com): ");
                refresh();
                goboxy(100, 5);
                printw("[]=====================[]\n");
                refresh();
                goboxy(100, 6);
                printw("[]                     []\n");
                refresh();
                goboxy(100, 7);
                printw("[]");
                refresh();
                goboxy(123, 7);
                printw("[]");
                refresh();
                goboxy(100, 8);
                printw("[]                     []\n");
                refresh();
                goboxy(100, 9);
                printw("[]=====================[]\n");
                refresh();

                char bg1[100];
                goboxy(142, 4);
                getstr(bg1); // Membaca string dari pengguna
                refresh();
                goboxy(104, 7);
                printw("%s@gmail.com", bg1);
                refresh();
                goboxy(106, 10);
                printw("tekan [enter]");
                refresh();
                cin.get();
                string bp = bg1;
                string Bp = bp + "@gmail.com";
                if (true)
                {
                    clear();
                    noecho();
                    refresh();
                    goboxy(100, 4);
                    printw("             Buat sandi yang rumit!!\n");
                    refresh();
                    goboxy(96, 5);
                    printw("Buat sandi yang rumit dengan campuran huruf,\n");
                    refresh();
                    goboxy(102, 6);
                    printw("               angka, dan simbol\n");
                    refresh();
                    goboxy(100, 7);
                    printw("Masukkan Sandi yang kuat: \n");
                    refresh();
                    char na3[100];
                    goboxy(126, 7);
                    getstr(na3); // Membaca string dari pengguna
                    refresh();
                    string sand3 = na3;
                    goboxy(95, 8);
                    printw("[]=====================[]\n");
                    refresh();
                    goboxy(95, 9);
                    printw("[]                     []\n");
                    refresh();
                    goboxy(95, 10);
                    printw("[]");
                    refresh();
                    goboxy(116, 10);
                    printw("[]\n");
                    refresh();
                    goboxy(95, 11);
                    printw("[]                     []\n");
                    refresh();
                    goboxy(95, 12);
                    printw("[]=====================[]\n");
                    refresh();
                    goboxy(124, 7);
                    printw("Masukkan Sandi yang sama : ");
                    refresh();
                    char kf3[100];
                    goboxy(152, 7);
                    getstr(kf3); // Membaca string dari pengguna
                    refresh();
                    string sand4 = kf3;
                    goboxy(124, 8);
                    printw("[]=====================[]\n");
                    refresh();
                    goboxy(124, 9);
                    printw("[]                     []\n");
                    refresh();
                    goboxy(124, 10);
                    printw("[]");
                    refresh();
                    goboxy(150, 10);
                    printw("[]\n");
                    refresh();
                    goboxy(124, 11);
                    printw("[]                     []\n");
                    refresh();
                    goboxy(124, 12);
                    printw("[]=====================[]\n");
                    refresh();
                    goboxy(114, 13);
                    printw("tekan [enter]");
                    refresh();
                    echo();
                    goboxy(110, 10);
                    getstr(na3); // Membaca string dari pengguna
                    refresh();
                    goboxy(136, 10);
                    getstr(kf3); // Membaca string dari pengguna
                    refresh();
                    cin.ignore();
                    clear();
                    if (sand3 == sand4)
                    {
                    captcha1:

                        clear();
                        int num1 = rand() % 10;
                        int num2 = rand() % 10;
                        int result = num1 + num2;
                        int captcha;
                        echo();
                        refresh();
                        goboxy(100, 4);
                        printw("      Konfirmasi bahwa Anda bukan\n");
                        refresh();
                        goboxy(111, 5);
                        printw("                 robot!!\n");
                        refresh();
                        goboxy(100, 6);
                        printw("[]=====================[]\n");
                        refresh();
                        goboxy(100, 7);
                        printw("[]                     []\n");
                        refresh();
                        goboxy(100, 8);
                        printw("[]       %d  + %d        []\n", num1, num2);
                        refresh();
                        goboxy(100, 9);
                        printw("[]                     []\n");
                        refresh();
                        goboxy(100, 10);
                        printw("[]=====================[]\n");
                        refresh();
                        goboxy(90, 11);
                        printw("Berapa hasil dari penjumlahan diatas? :");
                        refresh();
                        goboxy(141, 11);
                        scanw("%d", &captcha);
                        if (captcha != result)
                        {

                            goboxy(100, 13);
                            printw("Captcha salah ulangi!\n");
                            refresh();
                            goboxy(100, 14);
                            printw("tekan [enter]");
                            refresh();
                            cin.get();
                            clear();
                            goto captcha1;
                        }
                        goboxy(100, 12);
                        printw("ingin kembali ke menu login(y/n):");
                        refresh();
                        char yn;
                        scanw("%c", &yn);
                        if (yn == 'y')
                        {
                            tambahAkun(Bp, na3);
                            cin.ignore();
                            clear();
                        }
                    }
                }
            }
        }
    }
    simpanAkunKeFile();
}

#endif

/* 3.h
#ifndef AB_H
#define AB_H

#include <iostream>
#include <string>
#include <vector>

struct Akun
{
    std::string user;
    std::string pass;
};

extern std::vector<Akun> databaseAkun;
void tambahAkun(std::string user, std::string pass);
void simpanAkunKeFile();
void muatAkunDariFile();
bool verifikasiAkun(std::string user, std::string pass);
bool isValid(const std::string &input, int minLength, int maxLength);
std::string generateRandomString(int length);
void functionsignup();

#endif*/