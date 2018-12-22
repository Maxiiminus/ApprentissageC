#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED
#include <string>
#include "Arme.h"


class Personnage
{
public:

    Personnage(std::string nom); // Constructeur
    Personnage(std::string nom, int vie, int mana, std::string nomArme, int degatsArme);
    ~Personnage(); // Destructeur (inutile ici).
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    int afficherVie() const; // Const car on ne modifie par l'object on se contente de lire ses attributs
    bool estVivant() const;
    void afficherEtat() const;

private:
    std::string m_nom;
    int m_vie;
    int m_mana;
    Arme m_arme;

};



#endif // PERSONNAGE_H_INCLUDED
