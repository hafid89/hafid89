#include <iostream>
#include <string>
using namespace std;

string teksKeMorse(char huruf)
{
    switch (tolower(huruf))
    {
    case 'a':
        return ".-";
    case 'b':
        return "-...";
    case 'c':
        return "-.-.";
    case 'd':
        return "-..";
    case 'e':
        return ".";
    case 'f':
        return "..-.";
    case 'g':
        return "--.";
    case 'h':
        return "....";
    case 'i':
        return "..";
    case 'j':
        return ".---";
    case 'k':
        return "-.-";
    case 'l':
        return ".-..";
    case 'm':
        return "--";
    case 'n':
        return "-.";
    case 'o':
        return "---";
    case 'p':
        return ".--.";
    case 'q':
        return "--.-";
    case 'r':
        return ".-.";
    case 's':
        return "...";
    case 't':
        return "-";
    case 'u':
        return "..-";
    case 'v':
        return "...-";
    case 'w':
        return ".--";
    case 'x':
        return "-..-";
    case 'y':
        return "-.--";
    case 'z':
        return "--..";
    default:
        return "";
    }
}

string teksKeMorse(string teks)
{
    string hasil = "";
    for (char &huruf : teks)
    {
        if (isalpha(huruf))
        {
            hasil += teksKeMorse(huruf) + " ";
        }
        else if (isspace(huruf))
        {
            hasil += " ";
        }
    }
    return hasil;
}

string morseKeTeks(string morse)
{
    // Implementasi konversi Morse ke teks di sini
}

int main()
{
    string teks, morse;

    // Meminta pengguna memasukkan teks atau Morse
    cout << "Masukkan teks atau Morse: ";
    getline(cin, teks);

    // Memeriksa apakah yang dimasukkan adalah teks atau Morse
    if (teks.find('.') != string::npos || teks.find('-') != string::npos)
    {
        morse = teks;
        teks = morseKeTeks(morse);
        cout << "Hasil konversi Morse ke teks: " << teks << endl;
    }
    else
    {
        morse = teksKeMorse(teks);
        cout << "Hasil konversi teks ke Morse: " << morse << endl;
    }

    return 0;
}
