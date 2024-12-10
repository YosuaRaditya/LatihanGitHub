#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//1.
void generatekartu()
{
    string warna[] = {"Sekop", "Hati", "Wajik", "Keriting"};
    string kartu[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    string deck[52];
    int index = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            deck[index] = kartu[j] + " " + warna[i];
            index++;
        }
    }

    srand(time(0));
    for (int i = 0; i < 52; i++)
    {
        int randomindex = rand() % 52;
        swap(deck[i], deck[randomindex]);
    }

    for (int i = 0; i < 52; i++)
    {
        cout << deck[i] << endl;
    }
}

int main()
{
    generatekartu();
    return 0;
}