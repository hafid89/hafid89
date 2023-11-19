#include <iostream>
#include <string>
using namespace std;

void clearScreen()
{
#ifdef _WIN32 // for windows
    system("cls");
#else // for linux
    system("clear");
#endif
}

void colorCharacteristics(int colorChoice)
{
    if (colorChoice >= 1 && colorChoice <= 6)
    {
        cout << "Color Characteristics: Warm\n";
    }
    else if (colorChoice >= 7 && colorChoice <= 12)
    {
        cout << "Color Characteristics: Cool\n";
    }
}

void analogousColors(int colorChoice)
{
    int frontChoice1 = (colorChoice + 1) > 12 ? (colorChoice + 1) - 12 : colorChoice + 1;
    int frontChoice2 = (colorChoice + 2) > 12 ? (colorChoice + 2) - 12 : colorChoice + 2;
    int backChoice2 = (colorChoice - 1) < 1 ? (colorChoice - 1) + 12 : colorChoice - 1;
    int backChoice1 = (colorChoice - 2) < 1 ? (colorChoice - 2) + 12 : colorChoice - 2;

    cout << "\nAnalogous Color Combination with color number " << colorChoice << " is color number:\n";
    cout << frontChoice1 << "," << frontChoice2 << " or " << backChoice1 << "," << backChoice2 << " or " << frontChoice1 << "," << backChoice2 << endl;
}

void complementaryColors(int colorChoice)
{
    int a;
    cout << "\nComplementary Color Combination with color number " << colorChoice << " is color number:\n";
    a = colorChoice + 6;
    if (a > 12)
    {
        a -= 12;
    }
    cout << a << endl;
}

void splitComplementaryColors(int colorChoice)
{
    int a, b;
    cout << "\nSplit Complementary Color Combination with color number " << colorChoice << " is color number:\n";
    a = colorChoice + 5;
    b = colorChoice + 7;
    if (a > 12)
    {
        a -= 12;
    }
    if (b > 12)
    {
        b -= 12;
    }
    cout << a << "," << b << endl;
}

void triadicComplementaryColors(int colorChoice)
{
    int temp, a, b;
    cout << "\nTriadic Complementary Color Combination with color number " << colorChoice << " is color number:\n";
    a = colorChoice + 4;
    b = colorChoice + 8;
    if (a > 12)
    {
        a -= 12;
    }
    if (b > 12)
    {
        b -= 12;
    }
    cout << a << "," << b << endl;
}

void tetradComplementaryColors(int colorChoice)
{
    int temp, a, b, c;
    cout << "\nTetrad Complementary Color Combination with color number " << colorChoice << " is color number:\n";
    a = colorChoice + 3;
    b = colorChoice + 6;
    c = colorChoice + 9;
    if (a > 12)
    {
        a -= 12;
    }
    if (b > 12)
    {
        b -= 12;
    }
    if (c > 12)
    {
        c -= 12;
    }
    cout << a << "," << b << "," << c << endl;
}

int main()
{
    string name, studentID;
    int colorChoice;
    char colorCombination, repeat1, repeat2;
    bool check;

    do
    {
        cout << "|================================|" << endl;
        cout << " Name: ";
        getline(cin, name);
        cout << "|--------------------------------|" << endl;
        cout << " Student ID: ";
        getline(cin, studentID);
        cout << "|================================|\n"
             << endl;
        cout << "Program to determine Notation, color characteristics, and harmonious color combinations:\n\n";
        cout << "1. orange 2. red-orange 3. red\n"
             << "4. red-violet 5.violet 6. blue-violet\n"
             << "7.blue 8. blue-green 9.green\n"
             << "10.yellow-green 11.yellow 12. yellow-orange \n\n";
        cout << "Color number choice: ";
        cin >> colorChoice;

        if (colorChoice < 1 || colorChoice > 12)
        {
            cout << "Invalid color choice. Program terminates." << endl;
        }
        else
        {
            if (colorChoice == 3 || colorChoice == 7 || colorChoice == 11)
            {
                cout << "Color Notation: Primary\n";
                colorCharacteristics(colorChoice);
            }
            else if (colorChoice == 1 || colorChoice == 5 || colorChoice == 9)
            {
                cout << "Color Notation: Secondary\n";
                colorCharacteristics(colorChoice);
            }
            else if (colorChoice == 2 || colorChoice == 4 || colorChoice == 6 || colorChoice == 8 || colorChoice == 10 || colorChoice == 12)
            {
                cout << "Color Notation: Tertiary\n";
                colorCharacteristics(colorChoice);
            }
        }

        do
        { // Input color combination
            cout << "\nHarmonious Color Combinations: \n"
                 << "a.Analogous Color Combination\n"
                 << "b.Complementary Color Combination\n"
                 << "c.Split Complementary Color Combination\n"
                 << "d.Triadic Complementary Color Combination\n"
                 << "e.Tetrad Complementary Color Combination\n"
                 << "Choice: ";
            cin >> colorCombination;

            switch (colorCombination)
            {
            case 'a':
                analogousColors(colorChoice);
                break;
            case 'b':
                complementaryColors(colorChoice);
                break;
            case 'c':
                splitComplementaryColors(colorChoice);
                break;
            case 'd':
                triadicComplementaryColors(colorChoice);
                break;
            case 'e':
                tetradComplementaryColors(colorChoice);
                break;
            default:
                break;
            }

            cout << "Do you want to go back to the Color Combination selection? [Y] or [N]\n";
            cin >> repeat2;

            if (repeat2 == 'y')
            {
                check = true;
            }
            else
            {
                check = false;
            }
        } while (check);

        cout << "Do you want to go back to the Color Number selection? [Y] or [N]\n";
        cin >> repeat1;

        if (repeat1 == 'y')
        {
            check = true;
        }
        else
        {
            check = false;
        }

        cin.ignore();
        clearScreen();
    } while (check);

    return 0;
}