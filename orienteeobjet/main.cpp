#include <iostream>
#include <string>
#include "Personnage.h"
#include "Arme.h" // Pas sur mais je crois que c'est inutile ici étant donné qu'on n'utilise pas directement de méthode de l'objet Arme ?

using namespace std;

int main()
{
    Personnage goliath("Goliath", 150, 100, "Epee pas mal", 20), david("David");
    Personnage hector(david); // Recupère les attributs de david.

    goliath.attaquer(david);
    david.boirePotionDeVie(20);
    goliath.attaquer(david);
    david.attaquer(goliath);
    goliath.changerArme("Double hache", 40);
    goliath.attaquer(david);

    cout << "Goliath : " << endl;
    goliath.afficherEtat();

    cout << "David : " << endl;
    david.afficherEtat();

    return 0;
}

