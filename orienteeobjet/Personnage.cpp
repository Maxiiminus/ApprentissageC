#include "Personnage.h"
#include <string>

using namespace std;

Personnage::Personnage(string nom) : m_nom(nom), m_vie(100), m_mana(100)
{

}

Personnage::Personnage(string nom, int vie, int mana, string nomArme, int degatsArme) : m_nom(nom), m_vie(vie), m_mana(mana), m_arme(nomArme, degatsArme)
{

}

Personnage::~Personnage()
{
    /*
    Rien à mettre ici car on ne fait pas d'allocation dynamique dans la classe Personnage. Le destructeur est donc inutile mais je le mets pour montre à quoi cela ressemble.
    En temps normal, un destructeur fait souvent des delete et quelques autres vérifications si nécessaire avant la destruction de l'objet.
    */
}

void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats;

    if (m_vie < 0)
    {
        m_vie = 0;
    }
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme.getDegats());
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100)
    {
        m_vie = 100;
    }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant() const
{
    return m_vie > 0;
}

int Personnage::afficherVie() const // Const car on ne modifie par l'object on se contente de lire ses attributs
{
    return m_vie;
}

void Personnage::afficherEtat() const
{
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme.afficher();
}
