#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include<stdio.h>
#include<gtk/gtk.h>
typedef struct
{
char nom[20] ;
char prenom[20];
int cin;
int sexe;
int jour ;
int mois; 
int annee;
int bv;
int etat;
int vote;
}Utilisateur;
typedef struct 
{
char nom[20] ;
char prenom[20];
char cin[20];
char sexe[20];
char jour[20] ;
char bv[20];
char etat[20];
char vote[20];
}affi;
typedef struct 
{
char id;
char login[20];
char mdp[20];
}Admin;
int recherche(affi p, char *filename, char *icin);
int modifierprenom( char *nouv, char *filename);
int modifiernom(char *nouv, char *filename);
int modifierage(int jour,int mois,int annee, char *filename);
int modifiersexe(int modifsexe, char *filename);
int modifieretat(int modifetat,char *filename);
int modifierbv(int bv,char *filename);
int cin(char filename[]);
void convert();
void vider(GtkWidget * liste);
void Ajouter_Personne (Utilisateur p);
void Afficher_Personne (GtkWidget * liste);
int Afficher_Personne_nom (GtkWidget * liste,char var[]);
int Afficher_Personne_prenom (GtkWidget * liste,char var[]);
int Afficher_Personne_cin (GtkWidget * liste,char var[]);
int Afficher_Personne_age (GtkWidget * liste,char var[]);
int Afficher_Personne_role (GtkWidget * liste,char var[]);
int Afficher_Personne_sexe (GtkWidget * liste,char var[]);
int ajouter(Utilisateur p , char filename []);
int modifier(int cin,Utilisateur nouv, char * filename);
int supprimer(int cin, char * filename);
Utilisateur chercher(int cin, char * filename);
int agemoy(char filename []);
int nbelecteur(Utilisateur p,char filename[],int nb);
int nbvotes(char bvfilename[]);
int nbe( char * filename, int id );
int verifierajout(Utilisateur p,char filename[]);
int auth(Admin a,char admin[], char id[]);
int ajoutertemp(Utilisateur p, char filename[]);
int length(char cin[]);
Utilisateur lire(Utilisateur p,char tempfilename);
int comboboxdyn(char tab[50][10]);
int bvconvert(char bv[]);
int agemoy(char filename []);

int nbe( char * filename, int id );
#endif // FONCTION_H_INCLUDED
