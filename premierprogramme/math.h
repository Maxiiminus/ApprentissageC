#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

/*
* \brief Fonction qui ajoute deux au nombre en argument
* \param nombreRecu : le nombre auquel la fonction ajoute 2
* \return nombreRecu + 2
*/
int ajouterDeux(int nombreRecu);

/*
* \brief Fonction qui calcul la moyenne des valeurs d'un tableau
* \param notes : tableau statique de taille nombreNotes comprenant les valeurs, nombresNotes : taille du tableau notes
* \return moyenne des valeurs de notes.
*/
double moyenne(double notes[], int nombreNotes);

#endif // MATH_H_INCLUDED
