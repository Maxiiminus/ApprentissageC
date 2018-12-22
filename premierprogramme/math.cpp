#include "math.h"

int ajouterDeux (int nombreRecu)
{
    int valeur(nombreRecu+2);

    return valeur;
}

double moyenne (double notes[], int nombreNotes)
{
    double moyenne(0);
    for (int i = 0 ; i < nombreNotes ; i++)
        {
            moyenne += notes[i];
        }
    moyenne /= nombreNotes;

    return moyenne;
}
