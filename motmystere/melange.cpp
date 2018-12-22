#include "melange.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

string melange(string mystere)
{
    srand(time(0));
    int taille = mystere.size();
    string motMelange;

    for (int i = 0 ; i < taille ; i++)
    {
        int position = rand() % mystere.size();
        motMelange += mystere[position];
        mystere.erase(position, 1); // retire une lettre depuis la position position.
    }

    return motMelange;

}
