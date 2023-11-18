#ifndef DATAPASIEN_H
#define DATAPASIEN_H
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

void koorcek(int x, int y)
{
    move(y, x);
}
struct DataPasien
{
    std::string nama;
    std::string hari;
    std::string bulan;
    std::string tahun;
    std::string ALAMAT;
    std::string Nomor_kontak;
    std::string Pilihan_dokter;
    std::string day;
    std::string month;
    std::string year;
    std::string Waktu_pemeriksaan;
};

std::vector<DataPasien> databasePasien;

void tambahData(std::string nama, std::string hari, std::string bulan, std::string tahun, std::string ALAMAT, std::string Nomor_kontak, std::string Pilihan_dokter, std::string day, std::string month, std::string year, std::string Waktu_pemeriksaan)
{
    DataPasien pasien = {nama, hari, bulan, tahun, ALAMAT, Nomor_kontak, Pilihan_dokter, day, month, year, Waktu_pemeriksaan};
    databasePasien.push_back(pasien);
}

void simpanDataKeFile()
{
    std::ofstream file("coba.txt");

    if (file.is_open())
    {
        for (const DataPasien &pasien : databasePasien)
        {
            file << pasien.nama << " " << pasien.hari << " " << pasien.bulan << " " << pasien.tahun << " " << pasien.ALAMAT << " " << pasien.Nomor_kontak << " " << pasien.Pilihan_dokter << " " << pasien.day << " " << pasien.month << " " << pasien.year << " " << pasien.Waktu_pemeriksaan << std::endl;
        }
        file.close();
    }
    else
    {
        printw("Gagal membuka file.\n");
    }
}
void muatDataDariFile()
{
    std::ifstream file("coba.txt");

    if (file.is_open())
    {
        databasePasien.clear();

        std::string nama;
        std::string hari;
        std::string bulan;
        std::string tahun;
        std::string ALAMAT;
        std::string Nomor_kontak;
        std::string Pilihan_dokter;
        std::string day;
        std::string month;
        std::string year;
        std::string Waktu_pemeriksaan;
        while (file >> nama >> hari >> bulan >> tahun >> ALAMAT >> Nomor_kontak >> Pilihan_dokter >> day >> month >> year >> Waktu_pemeriksaan)
        {
            tambahData(nama, hari, bulan, tahun, ALAMAT, Nomor_kontak, Pilihan_dokter, day, month, year, Waktu_pemeriksaan);
        }

        file.close();
    }
    else
    {
        printw("Gagal membuka file.\n");
    }
}

void cetakData()
{
    int i = 1;

    for (const DataPasien &pasien : databasePasien)
    {

        printw("Data pasien %d \n", i);
        refresh();

        // Cetak nama
        printw("Nama                : %s\n", pasien.nama.c_str());

        // Cetak tanggal lahir
        printw("Tanggal lahir       : %s/%s/%s\n", pasien.hari.c_str(), pasien.bulan.c_str(), pasien.tahun.c_str());

        // Cetak alamat
        printw("Alamat              : %s\n", pasien.ALAMAT.c_str());

        // Cetak nomor kontak
        printw("Nomor kontak        : %s\n", pasien.Nomor_kontak.c_str());

        // Cetak dokter rawat
        printw("Dokter rawat        : %s\n", pasien.Pilihan_dokter.c_str());

        // Cetak tanggal pemeriksaan
        printw("Tanggal pemeriksaan : %s/%s/%s\n", pasien.day.c_str(), pasien.month.c_str(), pasien.year.c_str());

        // Cetak waktu pemeriksaan
        printw("Waktu pemeriksaan   : %s\n\n", pasien.Waktu_pemeriksaan.c_str());

        i++;
    }
}

void verifikasiAkun(void)
{

    char kataKunci[50];
    koorcek(96, 4);
    printw("Masukkan kata kunci pencarian (nama): ");
    refresh();
    getnstr(kataKunci, 99);
    refresh();
    string tes = kataKunci;
    int j = 1;
    for (const DataPasien &pasien : databasePasien)
    {
        if (pasien.nama == kataKunci)
        {

            koorcek(96, 5);
            printw("Nama                : %s\n", pasien.nama.c_str());
            koorcek(96, 6);
            printw("Tanggal lahir       : %s/%s/%s\n", pasien.hari.c_str(), pasien.bulan.c_str(), pasien.tahun.c_str());
            koorcek(96, 7);
            printw("Alamat              : %s\n", pasien.ALAMAT.c_str());
            koorcek(96, 8);
            printw("Nomor kontak        : %s\n", pasien.Nomor_kontak.c_str());
            koorcek(96, 9);
            printw("Dokter rawat        : %s\n", pasien.Pilihan_dokter.c_str());
            koorcek(96, 10);
            printw("Tanggal pemeriksaan :  %s/%s/%s\n", pasien.day.c_str(), pasien.month.c_str(), pasien.year.c_str());
            koorcek(96, 11);
            printw("Waktu pemeriksaan   : %s\n\n", pasien.Waktu_pemeriksaan.c_str());
            refresh();
        }
        j++;
    }
}

void registrasi(void)
{
    initscr();
    keypad(stdscr, TRUE);
    int pilihan;

    muatDataDariFile();
    koorcek(96, 4);
    printw("1. Isi Data Pasien                   :\n");
    koorcek(96, 5);
    printw("2. Cetak Data Pasien yang diinginkan :\n");
    koorcek(96, 6);
    printw("Input Pilihan :");
    koorcek(112, 6);
    scanw("%d", &pilihan);
    printw("\n");

    if (pilihan == 1)
    {
        char Nama[50], Hari[50], Bulan[50], Tahun[50], Alamat[50], kontak[50], dokter[50], Day[50], Month[50], Year[50], Waktupemeriksaan[50];
        std::string nama, hari, bulan, tahun, ALAMAT, Nomor_kontak, Pilihan_dokter, day, month, year, Waktu_pemeriksaan;

        clear();
        refresh();
        koorcek(96, 4);
        printw("[]===========================================[]\n");
        refresh();
        koorcek(96, 5);
        printw("[]          FORMULIR REGISTRASI PASIEN       []\n");
        refresh();
        koorcek(96, 6);
        printw("[]===========================================[]\n");
        refresh();
        koorcek(96, 7);
        printw("[] Isi Biodata pasien!                       []\n");
        refresh();
        koorcek(96, 8);
        printw("[] Nama Lengkap        : (                 ) []\n");
        refresh();
        koorcek(96, 9);
        printw("[] Tanggal Lahir       : (     /     /     ) []\n");
        refresh();
        koorcek(96, 10);
        printw("[] Alamat              : (                 ) []\n");
        refresh();
        koorcek(96, 11);
        printw("[] Nomor Kontak        : (                 ) []\n");
        refresh();
        koorcek(96, 12);
        printw("[] Pilihan Dokter      : (                 ) []\n");
        refresh();
        koorcek(96, 13);
        printw("[] Tanggal Pemeriksaan : (     /     /     ) []\n");
        refresh();
        koorcek(96, 14);
        printw("[] Waktu Pemeriksaan   : (                 ) []\n");
        refresh();

        koorcek(123, 8);
        getstr(Nama);
        nama = Nama;
        refresh();
        koorcek(123, 9);
        getstr(Hari);
        hari = Hari;
        refresh();
        koorcek(129, 9);
        getstr(Bulan);
        bulan = Bulan;
        refresh();
        koorcek(135, 9);
        getstr(Tahun);
        tahun = Tahun;
        refresh();
        koorcek(123, 10);
        getstr(Alamat);
        ALAMAT = Alamat;
        refresh();
        koorcek(123, 11);
        getstr(kontak);
        Nomor_kontak = kontak;
        refresh();
        koorcek(123, 12);
        getstr(dokter);
        Pilihan_dokter = dokter;
        refresh();
        koorcek(123, 13);
        getstr(Day);
        day = Day;
        refresh();
        koorcek(129, 13);
        getstr(Month);
        month = Month;
        refresh();
        koorcek(135, 13);
        getstr(Year);
        year = Year;
        refresh();
        koorcek(123, 14);
        getstr(Waktupemeriksaan);
        Waktu_pemeriksaan = Waktupemeriksaan;
        refresh();

        tambahData(nama, hari, bulan, tahun, ALAMAT, Nomor_kontak, Pilihan_dokter, day, month, year, Waktu_pemeriksaan);
        simpanDataKeFile();
        refresh();
    }
    else if (pilihan == 2)
    {
        clear();
        refresh();
        verifikasiAkun();
    }

    refresh();
    getch(); // Tunggu input dari pengguna

    endwin();
}

#endif
/*
printw("2. Tampilkan semua Data pasien :\n");
else if (pilihan == 2)
{
    clear();
    refresh();
    cetakData();
    refresh();
    cin.get();
    refresh();
}*/
