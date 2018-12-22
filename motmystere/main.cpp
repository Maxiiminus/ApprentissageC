#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <string>
#include "melange.h"
#include "time.h"

using namespace std;

int main()
{
    bool recommencer;
    do {
    srand(time(NULL));

    // 1 saisie et stockage du mot à trouver
    cout << endl;


    string motMystere;
    string ligne;

    string dictionnaire = "C:/Users/Maxime/Desktop/ProjetsC/motmystere/fichiers/dico.txt";

    ifstream monDico(dictionnaire.c_str());

    if (monDico)
    {
        long positionLigne(0);

        while (getline(monDico, ligne)) {
            positionLigne++;
        }

        monDico.close();
        monDico.open(dictionnaire.c_str());

        positionLigne = rand() % positionLigne;

        for (int i = 0 ; i < positionLigne ; i++)
        {
            getline(monDico, ligne);
        }
        motMystere = ligne;



    } else
    {
        cout << "Saisissez le mot mystere : ";
        cin >> motMystere;
    }

    // 2 mélange des lettres

    string motMelange = melange(motMystere);

    // 3 Trouver le mot mystere

    string motSaisi;

    do {
        cout << "Quel est ce mot ? " << motMelange << endl;
        cin >> motSaisi;

        if (motSaisi != motMystere)
        {
            cout << "Ce n'est pas le mot !" << endl;
            cout << endl;
        }

    } while (motSaisi != motMystere);
    cout << "Bravo !" << endl;
    cout << "Voulez vous recommencer ? (o/n) " << endl;
    string restart;
    cin >> restart;
    if (restart == "o") recommencer = true;
    else recommencer = false;

    } while (recommencer);
    return 0;
}
