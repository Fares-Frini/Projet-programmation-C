#include "bv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

enum
{
    eidbureau,
    eidagent,
    eville,
    eadresse,
    ecapacitebureau,
    eco,
    COLUMNS
};

int ajouterbv(char *filename, bv bv1)
{
    FILE *f = fopen(filename, "a");
    if (f != NULL)
    {
        fprintf(f, "%d %d %s %s %d %d\n", bv1.idbureau, bv1.idagent, bv1.ville, bv1.adresse, bv1.capacitebureau, bv1.co);
        fclose(f);
        return 1;
    }
    else
        return 0;
}

int modifier(char *filename, int idbureau, bv nouv)
{
    int tr = 0;
    bv bv1;
    FILE *f = fopen("bv.txt", "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%d %d %s %s %d %d\n", &bv1.idbureau, &bv1.idagent, bv1.ville, bv1.adresse, &bv1.capacitebureau, &bv1.co) != EOF)
        {
            if (bv1.idbureau == idbureau)

            {
                fprintf(f2, "%d %d %s %s %d %d\n", nouv.idbureau, nouv.idagent, nouv.ville, nouv.adresse, nouv.capacitebureau, nouv.co);
                tr = 1;
            }

            else
                fprintf(f2, "%d %d %s %s %d %d\n", bv1.idbureau, bv1.idagent, bv1.ville, bv1.adresse, bv1.capacitebureau, bv1.co);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

int supprimerbv(char *filename, int idbureau)
{
    int tr = 0;
    bv bv1;
    FILE *f = fopen("bv.txt", "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%d %d %s %s %d %d\n", &bv1.idbureau, &bv1.idagent, bv1.ville, bv1.adresse, &bv1.capacitebureau, &bv1.co) != EOF)
        {
            if (bv1.idbureau == idbureau)
                tr = 1;
            else
                fprintf(f2, "%d %d %s %s %d %d\n", bv1.idbureau, bv1.idagent, bv1.ville, bv1.adresse, bv1.capacitebureau, bv1.co);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

bv chercherbv(char *filename, int idbureau)
{
    bv bv1;
    int tr;
    FILE *f = fopen(filename, "r");
    if (f != NULL)
    {
        while (tr == 0 && fscanf(f, "%d %d %s %s %d %d  \n", &bv1.idbureau, &bv1.idagent, bv1.ville, bv1.adresse, &bv1.capacitebureau, &bv1.co) != EOF)
        {
            if (bv1.idbureau == idbureau)
                tr = 1;
            {
            }
            fclose(f);
            if (tr == 0)
                bv1.idbureau = -1;
            return bv1;
        }
    }
}

float TVB(char *filename)
{
    int VB = 0;
    int Nbt = 0;
    float t = 0;
    FILE *f = fopen("LE.txt", "r");
    LE L;
    if (f != NULL)
    {
        while (fscanf(f, "%d %d %d %s %d %d\n", &L.d.jour, &L.d.mois, &L.num, L.nationalite, &L.id, &L.nbrvote) != EOF)
        {
            if (L.nbrvote != -1)
            {
                if (L.nbrvote == 0)
                    VB++;
                Nbt++;
                t = (VB * 1.0) / Nbt;
            }
        }
    }
    return t;
}

void taux(char *filename, float *tn, float *te)
{
    int tun = 0;
    int etr = 0;
    FILE *f = fopen("observateur.txt", "r");
    ob o;
    if (f != NULL)
    {
        while (fscanf(f, "%s %s %d %d %d %s %s %s %s %s  ", o.nom, o.prenom, &o.jour, &o.mois, &o.annee, o.sexe, o.nationalite, o.cin, o.passeport, o.appartenance) != EOF)
        {
            if (strcmp("tunisien", o.nationalite) == 0)
            {
                tun++;
            }
            else
            {
                etr++;
            }
        }
    }

    *tn = (1.0 * tun) / (tun + etr);
    *te = (1.0 * etr) / (tun + etr);
    fclose(f);
}

void afficherbv(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

    char idbureau[30];
    char idagent[30];
    char ville[30];
    char adresse[100];
    char capacitebureau[30];
    char co[30];

    store = NULL;

    FILE *f;

    store = gtk_tree_view_get_model(liste);
    f = fopen("bv.txt", "a+");
    if (store == NULL)
    {

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID Bureau", renderer, "text", eidbureau, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID Agent", renderer, "text", eidagent, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Ville", renderer, "text", eville, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Adresse", renderer, "text", eadresse, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Capacité du Bureau", renderer, "text", ecapacitebureau, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("co", renderer, "text", eco, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

        f = fopen("bv.txt", "r");

        if (f == NULL)
        {
            return;
        }
        else
        {

            char idbureau[30];
            char idagent[30];
            char ville[30];
            char adresse[100];
            char capacitebureau[30];
            char co[30];
            f = fopen("bv.txt", "a+");
            while (fscanf(f, "%s %s %s %s %s %s  \n", idbureau, idagent, ville, adresse, capacitebureau, co) != EOF)
            {

                gtk_list_store_append(store, &iter);
                gtk_list_store_set(store, &iter, eidbureau, idbureau, eidagent, idagent,eville, ville, eadresse, adresse, ecapacitebureau, capacitebureau, eco, co, -1);
            }
            fclose(f);
            gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
            g_object_unref(store);
        }
    }
}

/*
int idbureau ;
    int idagent;
    char ville[30];
    char adresse[100];
    int capacitebureau ;
    int co ;
*/

int SupprimerBV(char *filename, char *ID)
{
    int tr = 0;
    bv bv1;
    char idbureau[30];
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL)
    {

        while ((fscanf(f, "%d %d %s %s %d %d \n", &bv1.idbureau, &bv1.idagent, bv1.ville, bv1.adresse, &bv1.capacitebureau, &bv1.co)) != (EOF))

        {
            sprintf(idbureau, "%d", bv1.idbureau);
            if (strcmp(idbureau, ID) == 0)
                tr = 1;
            else
                fprintf(f2, "%d %d %s %s %d %d \n", bv1.idbureau, bv1.idagent, bv1.ville, bv1.adresse, bv1.capacitebureau, bv1.co);
        }
    }

    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);

    return tr;
}
