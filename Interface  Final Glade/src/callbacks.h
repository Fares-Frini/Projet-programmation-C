#include <gtk/gtk.h>


void
on_enregistrerslaj_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retourslaj_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_quitterslaj_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retourslmd_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_enregistrerslmd_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_quitterslmd_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supprimergs_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modifiergs_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajoutergs_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retourbv_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_quitterbv_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_admin_login_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_choix_button_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_electeur_login_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_observateur_login_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_agentbv_login_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_admin_auth_choix_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_electeur_auth_choix_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_agentbv_auth_choix_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_observateur_auth_choix_clicked      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_admin_deco_button_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_gestion_utilisateur_button_clicked  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_gestion_election_button_clicked     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_gestion_bv_button_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_liste_electorale_button_clicked     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_vote_button_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_electeur_deco_button_clicked        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_observateur_deco_button_clicked     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_gestion_reclamation_button_clicked  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_agentbv_deco_button_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_treeview_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_fares_frini_ajout_button_clicked    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_modifier_button_clicked (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_raffraichir_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_quitter_button_clicked  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_supprimer_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_stat_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_chercher_homme_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fares_frini_chercher_electeur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fares_frini_recherche_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_appliquer_bv_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_ajouter_homme_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fares_frini_ajouter_femme_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fares_frini_ajouter_role_agentbv_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fares_frini_ajouter_role_electeur_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fares_frini_ajouter_button_clicked  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_modifier_modifier_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_modif_etat_checkbox_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fares_frini_modif_sexe_checkbox_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_modif_Prenom_checkbox_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_modif_nom_check_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_modif_date_checkbox_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_confirmer_supp_supp_button_clicked  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_confirmer_annuler_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_confirmer_modifier_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_continuer_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_valider_modif_nom_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_modif_prenom_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_valider_modif_age_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_modif_sexe_homme_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fares_frini_modif_sexe_femme_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fares_frini_valider_modif_sexe_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_modif_etat_electeur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fares_frini_modif_etat_agentbv_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fares_frini_modif_etat_valider_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_confirmer_ajout_button_clicked      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_confirmer_annuler_button_clicked    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_fermer_button_clicked   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button12_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button13_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button14_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button17_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button18_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button15_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_btnsup_clicked                      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_refrech_btn_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button8_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button10_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button11_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button19_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button9_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button20_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_calculertph_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_calculertpe_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_calculertpf_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button21_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Annuler__clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonsupp_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_confirmer_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Retour__clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_recherche_valider_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fares_frini_treeview2_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
