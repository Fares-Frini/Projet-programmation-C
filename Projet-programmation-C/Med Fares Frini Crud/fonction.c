
#include "fonction.h"
#include<stdio.h>
int ajouter(Utilisateur p , char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %d %d %d %d",p.nom,p.prenom,p.cin,p.sexe,p.jour,p.mois,p.annee);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier(int cin, Utilisateur nouv, char * filename)
{
Utilisateur p;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %d %d %d %d %d",p.nom,p.prenom,&p.cin,&p.sexe,&p.jour,&p.mois,&p.annee)!=EOF)
{
if(p.cin!=cin)
        fprintf(f2,"%s %s %d %d %d %d %d",p.nom,p.prenom,p.cin,p.sexe,p.jour,p.mois,p.annee);
else

  fprintf(f2,"%s %s %d %d %d %d %d",nouv.nom,nouv.prenom,nouv.cin,nouv.sexe,nouv.jour,nouv.mois,nouv.annee);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
 
}

int supprimer(int cin, char * filename)
{
Utilisateur p;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %d %d %d %d %d",p.nom,p.prenom,&p.cin,&p.sexe,&p.jour,&p.mois,&p.annee)!=EOF)
{
if(p.cin!=cin)
        fprintf(f2,"%s %s %d %d %d %d %d",p.nom,p.prenom,p.cin,p.sexe,p.jour,p.mois,p.annee);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
}

Utilisateur chercher(int cin, char * filename)
{
Utilisateur p; int tr=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %d %d %d %d %d",p.nom,p.prenom,&p.cin,&p.sexe,&p.jour,&p.mois,&p.annee)!=EOF && tr==0)
{if(p.cin==cin)
tr=1;
}
}
if(tr==0)
p.cin=-1;
return p;

}
