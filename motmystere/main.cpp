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
    srand(time(0));

    // 1 saisie et stockage du mot à trouver

    cout << endl;
    int coupsMax(0);

    cout << "Saisissez le nombre de coups maximum : ";
    cin >> coupsMax;

    string motMystere;
    string ligne;

    string dictionnaire = "fichiers/dico.txt";

    ifstream monDico(dictionnaire.c_str());

    if (monDico)
    {
        long positionLigne(0);

        while (getline(monDico, ligne)) { // On recupere le nombre de lignes dans le fichier.
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

    int nbCoups(0);
    do {
        nbCoups++;
        cout << "Quel est ce mot ? " << motMelange << " (essai numero " << nbCoups << ")" << endl;
        cin >> motSaisi;

        if (motSaisi != motMystere)
        {
            cout << "Ce n'est pas le mot !" << endl;
            cout << endl;
        }


    } while (motSaisi != motMystere && nbCoups != coupsMax);
    if (motSaisi == motMystere) cout << "Bravo !" << endl;
    if (motSaisi != motMystere) cout << "Nombre de coups maximums atteints ! " << endl;
    cout << "Voulez vous recommencer ? (o/n) " << endl;
    string restart;
    cin >> restart;
    if (restart == "o" || restart == "O") recommencer = true;
    else recommencer = false;

    } while (recommencer);
    return 0;
}
