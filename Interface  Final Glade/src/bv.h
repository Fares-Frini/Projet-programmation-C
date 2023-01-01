#ifndef BUREAUVOTE_H_INCLUDED
#define BUREAUVOTE_H_INCLUDED
#include <stdio.h>
#include<gtk/gtk.h>

typedef struct
{
	int idbureau ;
	int idagent;
	char ville[30];
	char adresse[100];
	int capacitebureau ;
	int co ;
} bv;
typedef struct
{
    int jour;
    int mois; 
    int annee; 
}date;
typedef struct
{
	date d;
    int id;
    int num ;
	char nationalite[30];
	int nbrvote ;
} LE;
typedef struct observateur
{
	char nom[20];
	char prenom[20];
    
	int jour;
	int mois;
	int annee;
	char sexe[10];
	char nationalite[20];
	char cin[8];
	char passeport[10];
	char appartenance[20];
	
	
	
}ob;

int ajouterbv(char* filename, bv);
int modifier( char *filename, int,bv nouv);
int supprimerbv(char *filename, int);
bv chercherbv(char *filename, int); 
float TVB(char*filename);
void taux (char *filename ,float *tn,float *te);
void afficherbv (GtkWidget * liste);
#endif // BUREAUVOTE_H_INCLUDED 
