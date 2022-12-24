#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
int sexe = 1, role = 1, modifsexe = 1, modifetat = 1;
int choixmodif[] = {0, 0, 0, 0, 0};
int choixchercher = 0, chercherrole = 2, cherchersexe = 0;
void on_admin_login_clicked(GtkWidget *objet_graphique,
                            gpointer user_data)
{
    Admin a;
    char admin[20] = "admin.txt", id[10];
    GtkWidget *input_log;
    GtkWidget *input_mdp;
    input_mdp = lookup_widget(objet_graphique, "admin_auth_mdp_entry");
    input_log = lookup_widget(objet_graphique, "admin_auth_login_entry");
    strcpy(a.login, gtk_entry_get_text(GTK_ENTRY(input_log)));
    strcpy(a.mdp, gtk_entry_get_text(GTK_ENTRY(input_mdp)));
    if (auth(a, admin, id) == 1)
    {
        char connected[20] = "ADMIN:", ID[20] = "ID:";
        GtkWidget *Affichage;
        GtkWidget *authentification;
        GtkWidget *treeview;
        convert();
        authentification = lookup_widget(objet_graphique, "authentification_admin");
        gtk_widget_hide(authentification);
        Affichage = lookup_widget(objet_graphique, "Admin");
        Affichage = create_Admin();
        gtk_widget_show(Affichage);
    }
    else
    {
        GtkWidget *refu;
        GtkWidget *label;
        refu = create_fares_frini_ajout_succ();
        gtk_widget_show(refu);
        label = lookup_widget(refu, "label287");
        gtk_label_set_text(GTK_LABEL(label), "Echec de l'Autehntifcation");
    }
}

void on_choix_button_clicked(GtkWidget *button,
                             gpointer user_data)
{
    GtkWidget *choix;
    GtkWidget *admin, *w1;
    GtkWidget *electeur, *electeurf;
    GtkWidget *agentbv;
    GtkWidget *observateur;
    choix = create_choix_auth();
    gtk_widget_show(choix);
    w1 = lookup_widget(button, "authentification_admin");
    gtk_widget_hide(w1);
    electeurf = create_authentification_utilisateur();
    electeur = lookup_widget(button, "authentification_utilisateur");
    gtk_widget_hide(electeur);
    agentbv = lookup_widget(button, "authentification_agenbv");
    gtk_widget_hide(agentbv);
    observateur = lookup_widget(button, "authentification_observateur");
    gtk_widget_hide(observateur);
}

void on_electeur_login_clicked(GtkButton *button,
                               gpointer user_data)
{
}

void on_observateur_login_clicked(GtkButton *button,
                                  gpointer user_data)
{
}

void on_agentbv_login_clicked(GtkButton *button,
                              gpointer user_data)
{
}

void on_admin_auth_choix_clicked(GtkWidget *button,
                                 gpointer user_data)
{
    GtkWidget *admin;
    GtkWidget *choix;
    admin = create_authentification_admin();
    gtk_widget_show(admin);
    choix = lookup_widget(button, "choix_auth");
    gtk_widget_hide(choix);
}

void on_electeur_auth_choix_clicked(GtkWidget *button,
                                    gpointer user_data)
{
    GtkWidget *admin;
    GtkWidget *choix;
    admin = create_authentification_utilisateur();
    gtk_widget_show(admin);
    choix = lookup_widget(button, "choix_auth");
    gtk_widget_hide(choix);
}

void on_agentbv_auth_choix_clicked(GtkButton *button,
                                   gpointer user_data)
{
    GtkWidget *admin;
    GtkWidget *choix;
    admin = create_authentification_agenbv();
    gtk_widget_show(admin);
    choix = lookup_widget(button, "choix_auth");
    gtk_widget_hide(choix);
}

void on_observateur_auth_choix_clicked(GtkButton *button,
                                       gpointer user_data)
{
    GtkWidget *admin;
    GtkWidget *choix;
    admin = create_authentification_observateur();
    gtk_widget_show(admin);
    choix = lookup_widget(button, "choix_auth");
    gtk_widget_hide(choix);
}

void on_admin_deco_button_clicked(GtkWidget *objet_graphique,
                                  gpointer user_data)
{
    GtkWidget *Affichage;
    GtkWidget *authentification;
    Affichage = lookup_widget(objet_graphique, "Admin");
    gtk_widget_hide(Affichage);
    authentification = create_authentification_admin();
    gtk_widget_show(authentification);
}

void on_gestion_utilisateur_button_clicked(GtkWidget *objet_graphique,
                                           gpointer user_data)
{
    GtkWidget *Affichage;
    GtkWidget *show;
    GtkWidget *treeview;
    GtkWidget *jour, *mois, *annee;
    GtkWidget *entry, *radio1, *radio2, *radio3, *radio4;
    Affichage = lookup_widget(objet_graphique, "Admin");
    gtk_widget_hide(Affichage);
    show = create_fares_frini_Affichage();
    gtk_widget_show(show);
    treeview = lookup_widget(show, "fares_frini_treeview");
    Afficher_Personne(treeview);
    jour = lookup_widget(show, "fares_frini_chercher_jour_spin");
    gtk_widget_hide(jour);
    mois = lookup_widget(show, "fares_frini_chercher_mois_spin");
    gtk_widget_hide(mois);
    annee = lookup_widget(show, "fares_frini_chercher_annee_spin");
    gtk_widget_hide(annee);
    radio1 = lookup_widget(show, "fares_frini_chercher_electeur");
    gtk_widget_hide(radio1);
    radio2 = lookup_widget(show, "fares_frini_chercher_agentbv");
    gtk_widget_hide(radio2);
    radio3 = lookup_widget(show, "fares_frini_chercher_homme");
    gtk_widget_hide(radio3);
    radio4 = lookup_widget(show, "fares_frini_chercher_femme");
    gtk_widget_hide(radio4);
    GtkWidget *combobox;
    int n;
    combobox = lookup_widget(show, "combobox2");
    char tab[50][10];
    n = comboboxdyn(tab);
    for (int i = 0; i < n; i++)
    {
        gtk_combo_box_append_text(combobox, (tab[i]));
    }

    GtkWidget *outputname;
    outputname = lookup_widget(show, "label_admin");
    gtk_label_set_text(GTK_LABEL(outputname), "Nom: Fares Frini");
    GtkWidget *outputid;
    outputid = lookup_widget(show, "id_admin");
    gtk_label_set_text(GTK_LABEL(outputid), "ID:14362491");
}

void on_gestion_election_button_clicked(GtkButton *button,
                                        gpointer user_data)
{
}

void on_gestion_bv_button_clicked(GtkButton *button,
                                  gpointer user_data)
{
}

void on_liste_electorale_button_clicked(GtkButton *button,
                                        gpointer user_data)
{
}

void on_vote_button_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_electeur_deco_button_clicked(GtkButton *button,
                                     gpointer user_data)
{
}

void on_observateur_deco_button_clicked(GtkButton *button,
                                        gpointer user_data)
{
}

void on_gestion_reclamation_button_clicked(GtkButton *button,
                                           gpointer user_data)
{
}

void on_agentbv_deco_button_clicked(GtkButton *button,
                                    gpointer user_data)
{
}

void on_fares_frini_treeview_row_activated(GtkTreeView *treeview,
                                           GtkTreePath *path,
                                           GtkTreeViewColumn *column,
                                           gpointer user_data)
{
    GtkTreeIter iter;
    gchar *nom;
    gchar *prenom;
    gchar *date;
    gchar *sexe;
    gchar *cin;
    gchar *bv;
    gchar *etat;
    gchar *vote;
    int Cin;
    char id[10];
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);
    if (gtk_tree_model_get_iter(model, &iter, path))
    {
        FILE *f;
        f = fopen("selection.txt", "w");
        if (f != NULL)
        {
            gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &cin, 1, &nom, 2, &prenom, 3, &date, 4, &sexe, 5, &etat, 6, &bv, 7, &vote, -1);
            fprintf(f, "%s", prenom);
            fclose(f);
        }
    }
}

void on_fares_frini_ajout_button_clicked(GtkWidget *objet_graphique,
                                         gpointer user_data)
{
    GtkWidget *ajout;
    ajout = create_fares_frini_ajouter();
    gtk_widget_show(ajout);
}

void on_fares_frini_modifier_button_clicked(GtkButton *button,
                                            gpointer user_data)
{
    {
        for (int i = 0; i < 6; i++)
        {
            choixmodif[i] = 0;
        }

        GtkWidget *conf;
        conf = create_fares_frini_modifier();
        gtk_widget_show(conf);
    }
}

void on_fares_frini_raffraichir_button_clicked(GtkWidget *objet_graphique,
                                               gpointer user_data)
{
    GtkWidget *afficher, *w1;
    GtkWidget *treeview;
    w1 = lookup_widget(objet_graphique, "fares_frini_Affichage");
    afficher = create_fares_frini_Affichage();
    gtk_widget_show(afficher);
    gtk_widget_hide(w1);
    treeview = lookup_widget(afficher, "fares_frini_treeview");
    /*  vider(treeview);*/
    convert();
    Afficher_Personne(treeview);
    GtkWidget *jour, *mois, *annee;
    GtkWidget *entry, *radio1, *radio2, *radio3, *radio4;

    jour = lookup_widget(afficher, "fares_frini_chercher_jour_spin");
    gtk_widget_hide(jour);
    mois = lookup_widget(afficher, "fares_frini_chercher_mois_spin");
    gtk_widget_hide(mois);
    annee = lookup_widget(afficher, "fares_frini_chercher_annee_spin");
    gtk_widget_hide(annee);
    radio1 = lookup_widget(afficher, "fares_frini_chercher_electeur");
    gtk_widget_hide(radio1);
    radio2 = lookup_widget(afficher, "fares_frini_chercher_agentbv");
    gtk_widget_hide(radio2);
    radio3 = lookup_widget(afficher, "fares_frini_chercher_homme");
    gtk_widget_hide(radio3);
    radio4 = lookup_widget(afficher, "fares_frini_chercher_femme");
    gtk_widget_hide(radio4);
    GtkWidget *combobox;
    int n;
    combobox = lookup_widget(afficher, "combobox2");
    char tab[50][10];
    n = comboboxdyn(tab);
    for (int i = 0; i < n; i++)
    {
        gtk_combo_box_append_text(combobox, (tab[i]));
    }
    GtkWidget *outputname;
    outputname = lookup_widget(afficher, "label_admin");
    gtk_label_set_text(GTK_LABEL(outputname), "Nom: Fares Frini");
    GtkWidget *outputid;
    outputid = lookup_widget(afficher, "id_admin");
    gtk_label_set_text(GTK_LABEL(outputid), "ID:14362491");
}

void on_fares_frini_quitter_button_clicked(GtkWidget *objet_graphique,
                                           gpointer user_data)
{
    GtkWidget *Affichage;
    GtkWidget *show;
    Affichage = lookup_widget(objet_graphique, "fares_frini_Affichage");
    gtk_widget_hide(Affichage);
    show = create_Admin();
    gtk_widget_show(show);
}

void on_fares_frini_supprimer_button_clicked(GtkButton *button,
                                             gpointer user_data)
{
    GtkWidget *conf;
    conf = create_fares_frini_confirmer_supp();
    gtk_widget_show(conf);
}

void on_fares_frini_stat_clicked(GtkWidget *objet_graphique,
                                 gpointer user_data)
{
    GtkWidget *conf;
    GtkWidget *output, *output1;
    char filename[20] = "utilisateur.txt";
    char c[20], c1[20];
    int i, i1;
    conf = create_fares_frini_statistique();
    gtk_widget_show(conf);
    output = lookup_widget(conf, "fares_frini_stat1");
    i = agemoy(filename);
    sprintf(c, "%d", i);
    gtk_entry_set_text(output, c);
    output1 = lookup_widget(conf, "fares_frini_stat2");
    i1 = nbe(filename, 0);
    sprintf(c1, "%d", i1);
    gtk_entry_set_text(output1, c1);
}

void on_fares_frini_chercher_homme_toggled(GtkToggleButton *togglebutton,
                                           gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        cherchersexe = 1;
    }
}

void on_fares_frini_chercher_electeur_toggled(GtkToggleButton *togglebutton,
                                              gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        chercherrole = 1;
    }
}

void on_fares_frini_recherche_button_clicked(GtkWidget *objet_graphique,
                                             gpointer user_data)
{
    char cin[10], date[20];
    char nom[10];
    char prenom[10], slash[5] = "/";
    int jour, mois, annee, R;
    char cjour[10], cmois[10], csexe[30], cannee[10], chaine[10], chaine1[100] = "Le nombre d'Utilisateur concernant ce critére est :";
    GtkWidget *entry1;
    GtkWidget *affichage, *treeview;
    GtkWidget *entry2;
    GtkWidget *entry3;
    GtkWidget *pjour, *pmois, *pannee;
    GtkWidget *output;
    switch (choixchercher)
    {
    case 0:

        entry1 = lookup_widget(objet_graphique, "fares_frini_entry_recherche");
        strcpy(cin, gtk_entry_get_text(GTK_ENTRY(entry1)));
        affichage = create_fares_frini_recherche_afficher();
        gtk_widget_show(affichage);
        treeview = lookup_widget(affichage, "fares_frini_treeview2");
        R = Afficher_Personne_cin(treeview, cin);
        output = lookup_widget(affichage, "fares_frini_recherche_label_affiche");
        sprintf(chaine, "%d", R);
        strcat(chaine1, chaine);
        gtk_label_set_text(GTK_LABEL(output), chaine1);
        break;
    case 1:
        entry2 = lookup_widget(objet_graphique, "fares_frini_entry_recherche");
        strcpy(nom, gtk_entry_get_text(GTK_ENTRY(entry2)));
        affichage = create_fares_frini_recherche_afficher();
        gtk_widget_show(affichage);
        treeview = lookup_widget(affichage, "fares_frini_treeview2");
        R = Afficher_Personne_nom(treeview, nom);
        output = lookup_widget(affichage, "fares_frini_recherche_label_affiche");
        sprintf(chaine, "%d", R);
        strcat(chaine1, chaine);
        gtk_label_set_text(GTK_LABEL(output), chaine1);
        break;
    case 2:
        entry3 = lookup_widget(objet_graphique, "fares_frini_entry_recherche");
        strcpy(prenom, gtk_entry_get_text(GTK_ENTRY(entry3)));
        affichage = create_fares_frini_recherche_afficher();
        gtk_widget_show(affichage);
        treeview = lookup_widget(affichage, "fares_frini_treeview2");
        R = Afficher_Personne_prenom(treeview, prenom);
        output = lookup_widget(affichage, "fares_frini_recherche_label_affiche");
        sprintf(chaine, "%d", R);
        strcat(chaine1, chaine);
        gtk_label_set_text(GTK_LABEL(output), chaine1);
        break;
    case 3:
        affichage = create_fares_frini_recherche_afficher();
        gtk_widget_show(affichage);
        if (cherchersexe == 1)
        {
            strcpy(csexe, "Homme");
        }
        else
        {
            strcpy(csexe, "Femme");
        }
        treeview = lookup_widget(affichage, "fares_frini_treeview2");
        R = Afficher_Personne_sexe(treeview, csexe);
        output = lookup_widget(affichage, "fares_frini_recherche_label_affiche");
        sprintf(chaine, "%d", R);
        strcat(chaine1, chaine);
        gtk_label_set_text(GTK_LABEL(output), chaine1);
        break;
    case 4:
        affichage = create_fares_frini_recherche_afficher();
        gtk_widget_show(affichage);
        if (chercherrole == 2)
        {
            strcpy(csexe, "Agent_de_Bureau_de_Vote");
        }
        else
        {
            strcpy(csexe, "Electeur");
        }
        treeview = lookup_widget(affichage, "fares_frini_treeview2");
        R = Afficher_Personne_role(treeview, csexe);
        output = lookup_widget(affichage, "fares_frini_recherche_label_affiche");
        sprintf(chaine, "%d", R);
        strcat(chaine1, chaine);
        gtk_label_set_text(GTK_LABEL(output), chaine1);
        break;
    case 5:
        pjour = lookup_widget(objet_graphique, "fares_frini_chercher_jour_spin");
        pmois = lookup_widget(objet_graphique, "fares_frini_chercher_mois_spin");
        pannee = lookup_widget(objet_graphique, "fares_frini_chercher_annee_spin");
        jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(pjour));
        mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(pmois));
        annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(pannee));
        affichage = create_fares_frini_recherche_afficher();
        gtk_widget_show(affichage);
        treeview = lookup_widget(affichage, "fares_frini_treeview2");
        sprintf(cjour, "%d", jour);
        sprintf(cmois, "%d", mois);
        sprintf(cannee, "%d", annee);
        strcat(cjour, slash);
        strcat(cjour, cmois);
        strcat(cjour, slash);
        strcat(cjour, cannee);
        R = Afficher_Personne_age(treeview, cjour);
        output = lookup_widget(affichage, "fares_frini_recherche_label_affiche");
        sprintf(chaine, "%d", R);
        strcat(chaine1, chaine);
        gtk_label_set_text(GTK_LABEL(output), chaine1);
        break;
    }
}
void on_fares_frini_appliquer_bv_button_clicked(GtkWidget *objet_graphique,
                                                gpointer user_data)
{
    char bv[10];
    int ibv, R;
    GtkWidget *combobox;
    combobox = lookup_widget(objet_graphique, "combobox2");
    strcpy(bv, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
    ibv = bvconvert(bv);
    R = modifierbv(ibv, "utilisateur.txt");
}

void on_fares_frini_ajouter_homme_radiobutton_toggled(GtkToggleButton *togglebutton,
                                                      gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        sexe = 1;
    }
}

void on_fares_frini_ajouter_femme_radiobutton_toggled(GtkToggleButton *togglebutton,
                                                      gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
        sexe = 2;
}

void on_fares_frini_ajouter_role_agentbv_radiobutton_toggled(GtkToggleButton *togglebutton,
                                                             gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        role = 2;
    }
}

void on_fares_frini_ajouter_role_electeur_radiobutton_toggled(GtkToggleButton *togglebutton,
                                                              gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        role = 1;
    }
}

void on_fares_frini_ajouter_button_clicked(GtkWidget *objet_graphique,
                                           gpointer user_data)
{
    char filename[20] = "utilisateur.txt", cin[12], filenametemp[20] = "utilisateurtemp.txt";
    Utilisateur p;
    GtkWidget *input_nom;
    GtkWidget *input_prenom;
    GtkWidget *input_cin;
    GtkWidget *jour;
    GtkWidget *mois;
    GtkWidget *annee;
    jour = lookup_widget(objet_graphique, "fares_frini_jour_spin");
    mois = lookup_widget(objet_graphique, "fares_frini_mois_spin");
    annee = lookup_widget(objet_graphique, "fares_frini_annee_spin");
    input_nom = lookup_widget(objet_graphique, "fares_frini_ajouter_nom_entry");
    input_prenom = lookup_widget(objet_graphique, "fares_frini_prenom_entry");
    input_cin = lookup_widget(objet_graphique, "fares_frini_ajouter_cin_entry");
    p.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
    p.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
    p.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
    strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(input_nom)));
    strcpy(p.prenom, gtk_entry_get_text(GTK_ENTRY(input_prenom)));
    strcpy(cin, gtk_entry_get_text(GTK_ENTRY(input_cin)));
    p.sexe = sexe;
    p.etat = role;
    p.vote = -1;
    p.bv = 0;
    p.cin = atoi(cin);
    if (verifierajout(p, filename) == 1)
    {
        GtkWidget *conf;
        GtkWidget *ajout;
        conf = create_fares_frini_confirmer_ajout();
        gtk_widget_show(conf);
        ajout = lookup_widget(objet_graphique, "fares_frini_ajouter");
        gtk_widget_hide(ajout);
        ajoutertemp(p, filenametemp);
    }
    else if (verifierajout(p, filename) == 0)
    {
        GtkWidget *output;
        output = lookup_widget(objet_graphique, "fares_frini_ajouter_erreur_label");
        gtk_label_set_text(GTK_LABEL(output), "Veillez verifiez votre CIN");
    }
    else if (verifierajout(p, filename) == 2)
    {
        GtkWidget *output;
        output = lookup_widget(objet_graphique, "fares_frini_ajouter_erreur_label");
        gtk_label_set_text(GTK_LABEL(output), "Date de Naissance Invalide");
    }
    else if (verifierajout(p, filename) == 3)
    {
        GtkWidget *output;
        output = lookup_widget(objet_graphique, "fares_frini_ajouter_erreur_label");
        gtk_label_set_text(GTK_LABEL(output), "L'utilisateur existe deja");
    }
    else if (verifierajout(p, filename) == 4)
    {
        GtkWidget *output;
        output = lookup_widget(objet_graphique, "fares_frini_ajouter_erreur_label");
        gtk_label_set_text(GTK_LABEL(output), "L'utilisateur doit avoir 18 Ans");
    }
}

void on_fares_frini_modifier_modifier_button_clicked(GtkWidget *objet_graphique,
                                                     gpointer user_data)
{
    if (choixmodif[1] == 1)
    {
        GtkWidget *nom;
        nom = create_fares_frini_modif_nom();
        gtk_widget_show(nom);
    }
    if (choixmodif[2] == 1)
    {
        GtkWidget *prenom;
        prenom = create_fares_frini_modif_prenom();
        gtk_widget_show(prenom);
    }
    if (choixmodif[3] == 1)
    {
        GtkWidget *date;
        date = create_fares_frini_modif_age();
        gtk_widget_show(date);
    }
    if (choixmodif[4] == 1)
    {
        GtkWidget *sexe;
        sexe = create_fares_frini_modif_sexe();
        gtk_widget_show(sexe);
    }
    if (choixmodif[5] == 1)
    {
        GtkWidget *etat;
        etat = create_fares_frini_modif_etat();
        gtk_widget_show(etat);
    }
    GtkWidget *cont4;
    cont4 = lookup_widget(objet_graphique, "fares_frini_modifier");
    gtk_widget_hide(cont4);
}

void on_fares_frini_modif_etat_checkbox_toggled(GtkToggleButton *togglebutton,
                                                gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        choixmodif[5] = 1;
    }
}

void on_fares_frini_modif_sexe_checkbox_toggled(GtkToggleButton *togglebutton,
                                                gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        choixmodif[4] = 1;
    }
}

void on_modif_Prenom_checkbox_toggled(GtkToggleButton *togglebutton,
                                      gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        choixmodif[2] = 1;
    }
}

void on_modif_nom_check_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        choixmodif[1] = 1;
    }
}

void on_modif_date_checkbox_toggled(GtkToggleButton *togglebutton,
                                    gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        choixmodif[3] = 1;
    }
}

void on_confirmer_supp_supp_button_clicked(GtkWidget *objet_graphique,
                                           gpointer user_data)
{
    char filename[20] = "selection.txt";
    int R, E;
    R = cin(filename);
    E = supprimer(R, "utilisateur.txt");
    if (E == 1)
    {
        GtkWidget *ajout;
        ajout = create_fares_frini_resultat_supp_succ();
        gtk_widget_show(ajout);
    }
    else
    {
        GtkWidget *ajout;
        ajout = create_fares_frini_resultat_supp_echec();
        gtk_widget_show(ajout);
    }
    GtkWidget *treeview;
    GtkWidget *afficher;
    afficher = create_fares_frini_Affichage();
    treeview = lookup_widget(afficher, "fares_frini_treeview");
    Afficher_Personne(treeview);
    GtkWidget *cont4;
    cont4 = lookup_widget(objet_graphique, "fares_frini_confirmer_supp");
    gtk_widget_hide(cont4);
}

void on_fares_frini_confirmer_annuler_button_clicked(GtkButton *button,
                                                     gpointer user_data)
{
}

void on_fares_frini_confirmer_modifier_button_clicked(GtkButton *button,
                                                      gpointer user_data)
{
}

void on_fares_frini_continuer_button_clicked(GtkWidget *objet_graphique,
                                             gpointer user_data)
{
    GtkWidget *cont;
    cont = lookup_widget(objet_graphique, "fares_frini_resultat_ajout_echec");
    gtk_widget_hide(cont);
    GtkWidget *cont2;
    cont2 = lookup_widget(objet_graphique, "fares_frini_ajout_succ");
    gtk_widget_hide(cont2);
    GtkWidget *cont3;
    cont3 = lookup_widget(objet_graphique, "fares_frini_auth_echec");
    gtk_widget_hide(cont3);
    GtkWidget *cont5;
    cont5 = lookup_widget(objet_graphique, "fares_frini_resultat_supp_succ");
    gtk_widget_hide(cont5);
    GtkWidget *cont6;
    cont6 = lookup_widget(objet_graphique, "fares_frini_resultat_supp_echec");
    gtk_widget_hide(cont6);
}

void on_fares_frini_valider_modif_nom_clicked(GtkWidget *objet_graphique,
                                              gpointer user_data)
{
    char nom[20], filename[20] = "utilisateur.txt";
    int R;
    GtkWidget *input_nom;
    GtkWidget *cont4;
    input_nom = lookup_widget(objet_graphique, "fares_frini_nom_modif_entry");
    strcpy(nom, gtk_entry_get_text(GTK_ENTRY(input_nom)));
    R = modifierprenom(nom, filename);
    cont4 = lookup_widget(objet_graphique, "fares_frini_modif_nom");
    gtk_widget_hide(cont4);
}

void on_fares_frini_modif_prenom_button_clicked(GtkWidget *objet_graphique,
                                                gpointer user_data)
{
    char nom[20], filename[20] = "utilisateur.txt";
    int R;
    GtkWidget *input_nom;
    GtkWidget *cont4;
    input_nom = lookup_widget(objet_graphique, "fares_frini_prenom_modif_entry");
    strcpy(nom, gtk_entry_get_text(GTK_ENTRY(input_nom)));
    R = modifierprenom(nom, filename);
    cont4 = lookup_widget(objet_graphique, "fares_frini_modif_prenom");
    gtk_widget_hide(cont4);
}

void on_fares_frini_valider_modif_age_button_clicked(GtkWidget *objet_graphique,
                                                     gpointer user_data)
{
    char filename[20] = "utilisateur.txt";
    int R, ijour, imois, iannee;
    GtkWidget *jour;
    GtkWidget *mois;
    GtkWidget *annee;
    jour = lookup_widget(objet_graphique, "fares_frini_modif_jour_spin");
    mois = lookup_widget(objet_graphique, "fares_frini_modif_mois_spin");
    annee = lookup_widget(objet_graphique, "fares_frini_modif_annee_spin");
    ijour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
    imois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
    iannee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
    R = modifierage(ijour, imois, iannee, filename);
    GtkWidget *cont4;
    cont4 = lookup_widget(objet_graphique, "fares_frini_modif_age");
    gtk_widget_hide(cont4);
}

void on_fares_frini_modif_sexe_homme_toggled(GtkToggleButton *togglebutton,
                                             gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        modifsexe = 1;
    }
}

void on_fares_frini_modif_sexe_femme_toggled(GtkToggleButton *togglebutton,
                                             gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        modifsexe = 2;
    }
}

void on_fares_frini_valider_modif_sexe_clicked(GtkWidget *objet_graphique,
                                               gpointer user_data)
{
    char filename[20] = "utilisateur.txt";
    int R;
    R = modifiersexe(modifsexe, filename);
    GtkWidget *cont4;
    cont4 = lookup_widget(objet_graphique, "fares_frini_modif_sexe");
    gtk_widget_hide(cont4);
}

void on_fares_frini_modif_etat_electeur_toggled(GtkToggleButton *togglebutton,
                                                gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        modifetat = 1;
    }
}

void on_fares_frini_modif_etat_agentbv_toggled(GtkToggleButton *togglebutton,
                                               gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        modifetat = 2;
    }
}

void on_fares_frini_modif_etat_valider_clicked(GtkWidget *objet_graphique,
                                               gpointer user_data)
{
    char filename[20] = "utilisateur.txt";
    int R;
    R = modifieretat(modifetat, filename);
    GtkWidget *cont4;
    cont4 = lookup_widget(objet_graphique, "fares_frini_modif_etat");
    gtk_widget_hide(cont4);
}

void on_confirmer_ajout_button_clicked(GtkWidget *objet_graphique,
                                       gpointer user_data)
{
    Utilisateur p;
    int R = 0;
    char filename[20] = "utilisateur.txt", tempfilename[20] = "utilisateurtemp.txt";
    R = ajouter(p, filename);
    if (R)
    {
        GtkWidget *ajout;
        ajout = create_fares_frini_ajout_succ();
        gtk_widget_show(ajout);
        GtkWidget *conf;
        conf = lookup_widget(objet_graphique, "fares_frini_confirmer_ajout");
        gtk_widget_hide(conf);
    }
    else
    {
        GtkWidget *ajout;
        ajout = create_fares_frini_resultat_ajout_echec();
        gtk_widget_show(ajout);
    }
    GtkWidget *conf;
    conf = lookup_widget(objet_graphique, "confirmer_ajout");
    gtk_widget_hide(conf);
}

void on_confirmer_annuler_button_clicked(GtkButton *button,
                                         gpointer user_data)
{
}

void on_fares_frini_fermer_button_clicked(GtkWidget *button,
                                          gpointer user_data)
{
}

void on_fares_frini_recherche_valider_clicked(GtkWidget *objet_graphique,
                                              gpointer user_data)
{
    GtkWidget *combobox;
    combobox = lookup_widget(objet_graphique, "critere_recherche");

    if (strcmp("Date De Naissance", gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox))) == 0)
    {
        choixchercher = 5;
        GtkWidget *Affichage;
        GtkWidget *show;
        GtkWidget *treeview;
        GtkWidget *jour, *mois, *annee;
        GtkWidget *entry, *radio1, *radio2, *radio3, *radio4;
        jour = lookup_widget(objet_graphique, "fares_frini_chercher_jour_spin");
        gtk_widget_show(jour);
        mois = lookup_widget(objet_graphique, "fares_frini_chercher_mois_spin");
        gtk_widget_show(mois);
        annee = lookup_widget(objet_graphique, "fares_frini_chercher_annee_spin");
        gtk_widget_show(annee);
        entry = lookup_widget(objet_graphique, "fares_frini_entry_recherche");
        gtk_widget_hide(entry);
        radio1 = lookup_widget(objet_graphique, "fares_frini_chercher_electeur");
        gtk_widget_hide(radio1);
        radio2 = lookup_widget(objet_graphique, "fares_frini_chercher_agentbv");
        gtk_widget_hide(radio2);
        radio3 = lookup_widget(objet_graphique, "fares_frini_chercher_homme");
        gtk_widget_hide(radio3);
        radio4 = lookup_widget(objet_graphique, "fares_frini_chercher_femme");
        gtk_widget_hide(radio4);
    }
    else
    {
        if (strcmp("Role", gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox))) == 0)
        {
            choixchercher = 4;
            GtkWidget *Affichage;
            GtkWidget *show;
            GtkWidget *treeview;
            GtkWidget *jour, *mois, *annee;
            GtkWidget *entry, *radio1, *radio2, *radio3, *radio4;
            jour = lookup_widget(objet_graphique, "fares_frini_chercher_jour_spin");
            gtk_widget_hide(jour);
            mois = lookup_widget(objet_graphique, "fares_frini_chercher_mois_spin");
            gtk_widget_hide(mois);
            annee = lookup_widget(objet_graphique, "fares_frini_chercher_annee_spin");
            gtk_widget_hide(annee);
            entry = lookup_widget(objet_graphique, "fares_frini_entry_recherche");
            gtk_widget_hide(entry);
            radio1 = lookup_widget(objet_graphique, "fares_frini_chercher_electeur");
            gtk_widget_show(radio1);
            radio2 = lookup_widget(objet_graphique, "fares_frini_chercher_agentbv");
            gtk_widget_show(radio2);
            radio3 = lookup_widget(objet_graphique, "fares_frini_chercher_homme");
            gtk_widget_hide(radio3);
            radio4 = lookup_widget(objet_graphique, "fares_frini_chercher_femme");
            gtk_widget_hide(radio4);
        }
        else
        {
            if (strcmp("SEXE", gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox))) == 0)
            {
                choixchercher = 3;
                GtkWidget *Affichage;
                GtkWidget *show;
                GtkWidget *treeview;
                GtkWidget *jour, *mois, *annee;
                GtkWidget *entry, *radio1, *radio2, *radio3, *radio4;
                jour = lookup_widget(objet_graphique, "fares_frini_chercher_jour_spin");
                gtk_widget_hide(jour);
                mois = lookup_widget(objet_graphique, "fares_frini_chercher_mois_spin");
                gtk_widget_hide(mois);
                annee = lookup_widget(objet_graphique, "fares_frini_chercher_annee_spin");
                gtk_widget_hide(annee);
                entry = lookup_widget(objet_graphique, "fares_frini_entry_recherche");
                gtk_widget_hide(entry);
                radio1 = lookup_widget(objet_graphique, "fares_frini_chercher_electeur");
                gtk_widget_hide(radio1);
                radio2 = lookup_widget(objet_graphique, "fares_frini_chercher_agentbv");
                gtk_widget_hide(radio2);
                radio3 = lookup_widget(objet_graphique, "fares_frini_chercher_homme");
                gtk_widget_show(radio3);
                radio4 = lookup_widget(objet_graphique, "fares_frini_chercher_femme");
                gtk_widget_show(radio4);
            }
            else
            {
                if (strcmp("CIN", gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox))) == 0)
                {
                    choixchercher = 0;
                    GtkWidget *Affichage;
                    GtkWidget *show;
                    GtkWidget *treeview;
                    GtkWidget *jour, *mois, *annee;
                    GtkWidget *entry, *radio1, *radio2, *radio3, *radio4;
                    jour = lookup_widget(objet_graphique, "fares_frini_chercher_jour_spin");
                    gtk_widget_hide(jour);
                    mois = lookup_widget(objet_graphique, "fares_frini_chercher_mois_spin");
                    gtk_widget_hide(mois);
                    annee = lookup_widget(objet_graphique, "fares_frini_chercher_annee_spin");
                    gtk_widget_hide(annee);
                    entry = lookup_widget(objet_graphique, "fares_frini_entry_recherche");
                    gtk_widget_show(entry);
                    radio1 = lookup_widget(objet_graphique, "fares_frini_chercher_electeur");
                    gtk_widget_hide(radio1);
                    radio2 = lookup_widget(objet_graphique, "fares_frini_chercher_agentbv");
                    gtk_widget_hide(radio2);
                    radio3 = lookup_widget(objet_graphique, "fares_frini_chercher_homme");
                    gtk_widget_hide(radio3);
                    radio4 = lookup_widget(objet_graphique, "fares_frini_chercher_femme");
                    gtk_widget_hide(radio4);
                }
                else
                {
                    if (strcmp("Nom", gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox))) == 0)
                    {
                        choixchercher = 1;
                        GtkWidget *Affichage;
                        GtkWidget *show;
                        GtkWidget *treeview;
                        GtkWidget *jour, *mois, *annee;
                        GtkWidget *entry, *radio1, *radio2, *radio3, *radio4;
                        jour = lookup_widget(objet_graphique, "fares_frini_chercher_jour_spin");
                        gtk_widget_hide(jour);
                        mois = lookup_widget(objet_graphique, "fares_frini_chercher_mois_spin");
                        gtk_widget_hide(mois);
                        annee = lookup_widget(objet_graphique, "fares_frini_chercher_annee_spin");
                        gtk_widget_hide(annee);
                        entry = lookup_widget(objet_graphique, "fares_frini_entry_recherche");
                        gtk_widget_show(entry);
                        radio1 = lookup_widget(objet_graphique, "fares_frini_chercher_electeur");
                        gtk_widget_hide(radio1);
                        radio2 = lookup_widget(objet_graphique, "fares_frini_chercher_agentbv");
                        gtk_widget_hide(radio2);
                        radio3 = lookup_widget(objet_graphique, "fares_frini_chercher_homme");
                        gtk_widget_hide(radio3);
                        radio4 = lookup_widget(objet_graphique, "fares_frini_chercher_femme");
                        gtk_widget_hide(radio4);
                    }
                    else
                    {
                        if (strcmp("PreNom", gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox))) == 0)
                        {
                            choixchercher = 2;
                            GtkWidget *Affichage;
                            GtkWidget *show;
                            GtkWidget *treeview;
                            GtkWidget *jour, *mois, *annee;
                            GtkWidget *entry, *radio1, *radio2, *radio3, *radio4;
                            jour = lookup_widget(objet_graphique, "fares_frini_chercher_jour_spin");
                            gtk_widget_hide(jour);
                            mois = lookup_widget(objet_graphique, "fares_frini_chercher_mois_spin");
                            gtk_widget_hide(mois);
                            annee = lookup_widget(objet_graphique, "fares_frini_chercher_annee_spin");
                            gtk_widget_hide(annee);
                            entry = lookup_widget(objet_graphique, "fares_frini_entry_recherche");
                            gtk_widget_show(entry);
                            radio1 = lookup_widget(objet_graphique, "fares_frini_chercher_electeur");
                            gtk_widget_hide(radio1);
                            radio2 = lookup_widget(objet_graphique, "fares_frini_chercher_agentbv");
                            gtk_widget_hide(radio2);
                            radio3 = lookup_widget(objet_graphique, "fares_frini_chercher_homme");
                            gtk_widget_hide(radio3);
                            radio4 = lookup_widget(objet_graphique, "fares_frini_chercher_femme");
                            gtk_widget_hide(radio4);
                        }
                    }
                }
            }
        }
    }
}

void on_fares_frini_chercher_femme_toggled(GtkToggleButton *togglebutton,
                                           gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        cherchersexe = 2;
    }
}

void on_fares_frini_chercher_agentbv_toggled(GtkToggleButton *togglebutton,
                                             gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        chercherrole = 2;
    }
}

void on_fares_frini_treeview2_row_activated(GtkTreeView *treeview,
                                            GtkTreePath *path,
                                            GtkTreeViewColumn *column,
                                            gpointer user_data)
{
    GtkTreeIter iter;
    gchar *nom;
    gchar *prenom;
    gchar *date;
    gchar *sexe;
    gchar *cin;
    gchar *bv;
    gchar *etat;
    gchar *vote;
    int Cin;
    char id[10];
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);
    if (gtk_tree_model_get_iter(model, &iter, path))
    {
        FILE *f;
        f = fopen("selection.txt", "w");
        if (f != NULL)
        {
            gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &cin, 1, &nom, 2, &prenom, 3, &date, 4, &sexe, 5, &etat, 6, &bv, 7, &vote, -1);
            fprintf(f, "%s", prenom);
            fclose(f);
        }
    }
}
