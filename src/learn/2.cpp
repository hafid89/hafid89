#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <fstream>
#include <sstream>
#include <ncurses.h>
#include "signup.h"
#include "animasiload.h"
using namespace std;

void printAt(int x, int y, const char *str)
{
    move(y, x);
    printf("%s", str);
}
int main()
{

menuawal:
    load();
    srand(time(0));
    string user, pass;
    int pilihan, awal;
    initscr(); // Memulai mode ncurses
    muat();
    printAt(80, 22, "   ++==================================++\n ");
    printAt(80, 22, "(+)                                    (+)\n");
    printf(" ||   SELAMAT DATANG DI RUMAH SAKIT      ||\n");
    printf(" ||       Dr.Hafid Dwi Saputra           ||\n");
    printf(" ||                                      ||\n");
    printf(" ||++++++++++++++++++++++++++++++++++++++||\n");
    printf(" ||                                      ||\n");
    printf(" ||        Pengunjung di harap           ||\n");
    printf(" ||    untuk login terlebih dahulu       ||\n");
    printf(" ||     demi kenyamanan pelayanan        ||\n");
    printf(" ||                                      ||\n");
    printf(" ||++++++++++++++++++++++++++++++++++++++||\n");
    printf(" (+)                                    (+)\n");
    printf("   ++==================================++\n ");
    printf("\n\n");
    printf("########################################\n");
    printf("Silahkan memilih terlebih dahulu!!\n");
    printf("1. Login\n");
    printf("2. Sign up\n");
    printf("3. Exit\n");
    cout << "Masukkan pilihan anda :";
    scanf("%d", &awal);
    cin.ignore(256, '\n'); // bersihkan buffer hingga 256 char batas \n!
    printf("########################################\n");
    cout << "tekan [enter]";
    cin.get(); // pause sementara!!
    switch (awal)
    {
    case 1:

    login:
        system("clear");
        cout << "      Please Login Rs.Hafid Account First!\n\n";
        cout << "[]--Silahkan isi username akun anda :"
             << "-----------------[]\n"
             << "[]                                                    []\n"
             << "               ";
        getline(cin, user);
        cout << "[]                                                    []\n"
             << "[]----------------------------------------------------[]\n";
        cout << "\n"
             << "\n"
             << "[]--Silahkan isi password akun anda :"
             << "-----------------[]\n"
             << "[]                                                    []\n"
             << "               ";
        getline(cin, pass);
        cout << "[]                                                    []\n"
             << "[]----------------------------------------------------[]\n";
        cout << "tekan [enter]";
        cin.get(); // pause sementara!!

        if (verifikasiAkun(user, pass))
        {
        utama:
            system("clear");
            printf("   ++==================================++\n ");
            printf("(+)                                    (+)\n ");
            printf("||   SELAMAT DATANG DI RUMAH SAKIT      ||\n");
            printf(" ||       Dr.Hafid Dwi Saputra           ||\n");
            printf(" ||                                      ||\n");
            printf(" ||++++++++++++++++++++++++++++++++++++++||\n");
            printf(" ||                                      ||\n");
            cout << "            " << user << "          \n";
            printf(" ||   Selamat Datang di Menu Informasi   ||\n");
            printf(" ||   Silahkan tentukan pilihan anda!!   ||\n");
            printf(" ||                                      ||\n");
            printf(" ||++++++++++++++++++++++++++++++++++++++||\n");
            printf(" (+)                                    (+)\n");
            printf("   ++==================================++\n ");
            printf("\n\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("1. Registrasi pemeriksaan\n");
            printf("2. Registrasi jenguk pasien\n");
            printf("3. Cek data pasien\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Isi pilihan anda :");
            cin >> pilihan;
            if (pilihan == 1)
            {
                char *nama = getpass("Nama Lengkap: ");
                string Nama = nama;
                char *Tanggal_lahir = getpass("Tanggal Lahir dalam Format dd/mm/yy  : ");
                stringstream ss1(Tanggal_lahir);
                string hari, bulan, tahun;
                getline(ss1, hari, '/');
                getline(ss1, bulan, '/');
                getline(ss1, tahun, '/');
                char *ALAMAT = getpass("Alamat          : ");
                string alamat = ALAMAT;
                char *Nomor_kontak = getpass("Nomor Kontak    : ");
                string no = Nomor_kontak;
                char *Pilihan_dokter = getpass("Pilihan Dokter  : ");
                string pildok = Pilihan_dokter;
                char *Tanggal_pemeriksaan = getpass("Tanggal Pemeriksaan dalam Format dd/mm/yy : ");
                stringstream ss2(Tanggal_pemeriksaan);
                string day, month, year;
                getline(ss2, day, '/');
                getline(ss2, month, '/');
                getline(ss2, year, '/');
                char *Waktu_pemeriksaan = getpass("Waktu Pemeriksaan dalam Format [ _ : _  AM/PM]  :");
                stringstream ss3(Waktu_pemeriksaan);
                string jam, detik;
                getline(ss3, jam, ':');
                getline(ss3, detik, ' ');
                system("clear");
                string a;
                a = "=====================================\n"
                    "     FORMULIR PENDAFTARAN PASIEN\n"
                    "=====================================\n"
                    "Nama Lengkap        : [" +
                    Nama + "]\n" + "Tanggal Lahir       : [" +
                    hari + " /" +
                    bulan + " /" +
                    tahun + "]\n" + "Alamat              : [" +
                    alamat + "]\n" + "Nomor Kontak        : [" +
                    no + "]\n" + "Pilihan Dokter      : [" +
                    pildok + "]\n" + "Tanggal Pemeriksaan : [" +
                    day + " /" + month + " /" + year + "]\n" + "Waktu Pemeriksaan   : [" + jam + ":" + detik + " AM/PM]\n";
                cout << a;
                char *Enter = getpass("[ENTER]");
                break;
            }
            else
            {
                break;
            }
        }
        else if (!verifikasiAkun(user, pass))
        {
            cout << "Username atau Password salah!\nSilahkan coba lagi\n[Enter]\n";
            cin.get();
            goto login;
            break;
        }

    case 2:
        functionsignup();
        goto menuawal;
        break;
    case 3:
        break;

    default:
        cout << "Pilihan tidak valid." << endl;
        break;
    }

    return 0;

    endwin(); // Mengakhiri mode ncurses
}
