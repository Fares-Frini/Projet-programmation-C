#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include<stdio.h>
typedef struct
{
char nom[20] ;
char prenom[20];
int cin;
int sexe;
int jour ;
int mois; 
int annee;
}Utilisateur;


int ajouter(Utilisateur p , char filename []);
int modifier(int cin,Utilisateur nouv, char * filename);
int supprimer(int cin, char * filename);
Utilisateur chercher(int cin, char * filename);

#endif // FONCTION_H_INCLUDED
