#include <iostream> // In and out stream (recuperation de saisie claiver et affichage console)
#include <string>
#include <vector> // Tableau dynamique
#include <fstream> // Flux vers les fichiers
#include "math.h"
using namespace std;



int main()
{



    // Fonctions classiques

    int a(0), b(0);
    cout << "Valeur de a ? " << endl;
    cin >> a;
    b = ajouterDeux(a);
    cout << "a : " << a << ", b : " << b << endl;

    // Tableaux statiques

    int nombreNotes(5);
    double notes[nombreNotes];

    for(int i = 0 ; i < nombreNotes ; i++)
    {
        cout << "Entrez la note numéro " << i << " : ";
        cin >> notes[i];
    }

    double moyenneEleve(moyenne(notes, nombreNotes));

    cout << "Moyenne : " << moyenneEleve << endl;

    // Tableaux dynamiques

    vector<int> tableau(5, 3); // Crée un tableau de 5 entiers valant tous 3
    vector<string> listeNoms(12, "Sans nom"); // Crée un tableau de 12 chaines de caractères valant tous "Sans nom".

    cout << listeNoms.size() << endl; // Retourne 12.

    vector<double> tableauDouble; // Crée un tableau de 0 cases (lorsque l'on ne connait pas la taille).

    tableau.push_back(8); // Rajoute une case à la fin du tableau contenant la valeur 8.
    tableau.pop_back(); // Supprime la dernière case du tableau.

    // Tableaux multidimensionnels

    int tableau2D[2][2]; // Créé un tableau de 2 cases par 2.

    vector<vector<int> > grille;
    grille.push_back(vector<int>(5,4)); // Rajoute une ligne de 5 cases contenant toute le nombre 4.
    grille[0].push_back(8); // Ajoute une case contenant la valeur 8 à la première ilgne du tableau.

    // Chaînes de caractères (fonctionne tel un tableau, chaque caractère correspond à une case d'un tableau contenant la chaîne de caractères.

    string texte("Portez ce whisky au vieux juge blond qui fume.");
    cout << texte.size() << endl; // Retourne la longueur de la chaine de caractères
    texte[1] = 'm' ; // Remplace le "P" par un "m". ATTENTION A BIEN METTRE DES APOSTROPHES ET PAS DES GUILLEMENTS POUR UN CARACTERE !!!!!!!!!!!!!

    // Edition de fichiers

    string const monFichier("C:/Users/Maxime/Desktop/ProjetsC/premierprogramme/fichiers/scores.txt");

    ofstream monFlux(monFichier.c_str(), ios::app); // ios::app sert à écrire à la fin du fichier, sinon le programme le supprime et en crée un autre du même nom

    if (monFlux)
    {
        cout << "OUI" << endl;

        monFlux << "Cette phrase sera écrite dans le fichier" << endl; // Remplacer simplement cout par monFlux.
        monFlux.close(); // Pour refermer le fichier, il se referme automatique une fois sorti de sa boucle de traitement, mais il peut parfois être utile de le fermer prématurément.
    }
    else
    {
        cout << "NON" << endl;
    }

    // Lecture de fichiers

    ifstream maData(monFichier.c_str());

    if (maData)
    {
        cout << "OUI" << endl;

        string ligne; // Une variable pour stocker la ligne lue

        while (getline(maData, ligne)) // Tant qu'il reste des lignes à lire.
        {
            cout << ligne << endl; // On affiche la ligne dans la console. On peut également la traiter pour récuper de l'information par exemple.
        }
    }
    else
    {
        cout << "NON" << endl;
    }

    // Autres traitements de fichiers

    ofstream unFlux;

    unFlux.open(monFichier.c_str()); // Pour retarder l'ouverture d'un fichier.

    int position = unFlux.tellp(); // Recupère la position du curseur, tellg() pour un ifstream.

    monFlux.seekp(12, ios::cur); // Se déplace 12 caractères après la position entrée en second paramètres (ios::cur pour la position actuelle ; ios::beg pour le début ; ios::end pour la fin). seekg() pour un ifstream

    // Astuce, pour trouver le nombre de caractères dans un fichier, on déplace le caratère à seekp(0, ios::end) et on récupère sa position actuelle.

    // Pointeurs : TOUJOURS LUI DONNER UNE VALEUR A L'INITIALISATION

    double *pointeurA(0); //Un pointeur qui peut contenir l'adresse d'un nombre à virgule

    unsigned int *pointeurB(0); //Un pointeur qui peut contenir l'adresse d'un nombre entier positif

    string *pointeurC(0); //Un pointeur qui peut contenir l'adresse d'une chaîne de caractères

    vector<int> *pointeurD(0); //Un pointeur qui peut contenir l'adresse d'un tableau dynamique de nombres entiers

    int const *pointeurE(0); //Un pointeur qui peut contenir l'adresse d'un nombre entier constant

    unsigned int valeur(16);
    cout << valeur << endl; // Retourne 16
    cout << &valeur << endl; // Retourne l'adresse de la variable (base 16).
    pointeurB = &valeur; // Pointeur B prends la valeur de l'adresse de la variable valeur.
    cout << *pointeurB << endl; // Accède à la valeur pointée par le pointeur.

    int *pointeurF(0); // Création d'un pointeur qui pointe vers rien (case 0).
    pointeurF = new int; // Allocation d'une case pour une valeur int sur laquelle pointe le pointeur.

    *pointeurF = 2; // On accède à la case pointée et on en modifie la valeur.
    delete pointeurF; // On libère la case mémoire
    pointeurF = 0; // On refait pointer le pointeur vers rien.

    return 0;
}
