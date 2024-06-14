#pragma once
/** Fichier contenant les documentations des fonctions du programme definies dans functions.c
 * \brief Fichier de documentation
 */
/**\file functions.h */


#define NOM 25
#define VILLE 50
#define TEL 15


/** \brief Structure accueillant l'ensemble des donnees de l'annuaire.
 */
typedef struct client_structure
    {
        char nom[NOM];
        char prenom[NOM];
        char codepost[TEL];
        char ville[VILLE];
        char telephone[TEL];
        char mail[VILLE];
        char profession[NOM];
    } client;


 /** \brief Fonction d'entree du fichier.
  * \author MAYRAND Hugo
  * \param f char* champs d'entree du nom de fichier
  * \return int
  *
  * Fonction executee au lancement de l'application. Elle permet a l'utilisateur d'entrer le nom de son fichier et verifie si ce dernier existe.
  */
int enter_n_file(char* f);


/** \brief Fonction comptant le nombre de lignes du fichier.
 * \author MAYRAND Hugo
 * \param nfichier char* nom du fichier dont il faut compter les lignes
 * \return int nombre de lignes du fichier
 */
int cpt_lignes(char* nfichier);


/** \brief Fonction de chargement de l'annuaire.
 * \author MAYRAND Hugo
 * \param nfichier char* nom du fichier a charger
 * \param annuaire client* structure dans laquelle les donnees vont etre inserees
 * \param i int nombre de lignes du fichier
 * \return int
 *
 * Fonction qui charge l'annuaire passe en entree en entrant ses donnees dans la structure prevue a cet effet.
 */
int charge_annuaire(char* nfichier,client *annuaire,int i);


/** \brief Fonction de validation de l'annuaire.
 * \author MAYRAND Hugo
 * \param annuaire client* structure contenant les donnees de l'annuaire
 * \param i int longueur de la structure
 * \return int
 *
 * Fonction qui s'assure que l'annuaire est valide. C'est a dire qu'aucun champ email de l'annuaire n'est vide et qu'aucun doublon n'est present.
 */
int valider_annuaire(client *annuaire,int i);


/** \brief Fonction d'entree
 * \author MAYRAND Hugo
 * \return char valeur de l'entree
 *
 * Fonction d'entree du menu principal de l'application.
 */
char entree_menu_gene();


/** \brief Fonction d'entree
 * \author MAYRAND Hugo
 * \return char valeur de l'entree
 *
 * Fonction d'entree du menu d'affichage
 */
char entree_menu_affi();


/** \brief Fonction d'entree
 * \author MAYRAND Hugo
 * \return char valeur de l'entree
 *
 * Fonction d'entree du menu de sauvegarde d'annuaire.
 */
char entree_menu_save();


/** \brief Fonction d'entree
 * \author MAYRAND Hugo
 * \return char valeur de l'entree
 *
 * Fonction d'entree du menu de modification d'annuaire.
 */
char entree_menu_mod_ann();


/** \brief Fonction d'entree
 * \author MAYRAND Hugo
 * \return char valeur de l'entree
 *
 * Fonction d'entree du menu de modification des donnees d'un client en particulier.
 */
char entree_menu_mod_client();


/** \brief Fonction d'entree
 * \author MAYRAND Hugo
 * \param anmail char* mail a remplacer
 * \return int
 *
 * Fonction d'entree du mail a remplacer
 */
int entree_anmail(char* anmail);


/** \brief Fonction d'entree
 * \author MAYRAND Hugo
 * \param f_sauvegarde char* nom du nouveau fichier csv
 * \return int
 *
 * Fonction d'entree du nom du fichier de sauvegarde a creer
 */
int entree_n_newfile(char* f_sauvegarde);


/** \brief Fonction d'entree
 * \author MAYRAND Hugo
 * \param nmail char* nouveau mail de la personne
 * \return int
 *
 * Fonction d'entree du mail remplacant
 */
int entree_nmail(char* nmail);


/** \brief Fonction d'entree
 * \author MAYRAND Hugo
 * \param mail char* mail de la personne
 * \return int
 *
 * Fonction d'entree du mail de la personne dont il faut modifier un champ
 */
int entree_mail(char* mail);


/** \brief Fonction d'entree
 * \author MAYRAND Hugo
 * \param donnee char* donnee a inserer
 * \return int
 *
 * Fonction d'entree de la donnee a inserer
 */
int entree_donnee(char* donnee);


/** \brief Fonction d'entree
 * \author BOUANANI Yacine
 * \param val_chaine char* chaine contenant la chaine recherchee
 * \return int
 *
 * Fonction d'entree de la chaine recherchee dans le filtre
 */
int entree_val_filtre(char* val_chaine);


/** \brief Fonction de remplacement d'un email de client.
 * \author MAYRAND Hugo
 * \param annuaire client* structure contenant les donnees de l'annuaire
 * \param i int longueur de la structure
 * \param anmail char* mail a remplacer
 * \param nmail char* mail remplacant
 * \return int
 *
 * Fonction remplacant un email en entree present dans l'annuaire par un second email en entree non present dans l'annuaire.
 */
int modifier_mail(client *annuaire,int i,char* anmail,char* nmail);


/** \brief Fonction de remplacement de donnee
 * \author MAYRAND Hugo
 * \param annuaire client* structure contenant les donnees de l'annuaire
 * \param i int longueur de la structure
 * \param mail char* mail de la personne dont il faut modifier une information
 * \param ndonnee char* donnee a inserer en remplacement
 * \param champ int champ a modifier
 * \return int
 *
 * Fonction modifiant les informations d'un champ d'un  client de l'annuaire
 */
int modifier_autre_mail(client *annuaire,int i,char* mail,char* ndonnee,int champ);


/** \brief Fonction de sauvegarde
 * \author MAYRAND Hugo
 * \param nfichier char* nom du fichier dans lequel sauvegarder
 * \param annuaire client* structure contenant les donnees de l'annuaire
 * \param i int longueur de la structure
 * \return int
 *
 */
int sauvegarde_annuaire(char* nfichier,client *annuaire,int i);


/** \brief Fonction de suppresion
 * \author BOUANANI Yacine
 * \param annuaire client* structure contenant les donnees de l'annuaire
 * \param i int longueur de la structure
 * \param supmail char* mail de la personne dont il faut supprimer les informations
 * \return int
 *
 * Fonction supprimant les donnees d'un client en fonction de son adresse mail
 */
int supprimer_client(client *annuaire,int i,char* supmail);


/** \brief Fonction d'entree
 * \author BOUANANI Yacine
 * \param supmail char* mail de la personne dont il faut supprimer les informations
 * \return int
 *
 * Fonction premettant de trouver le mail du client a supprimer
 */
int entree_supmail(char* supmail);


/** \brief Fonction d'ajout
 * \author BOUANANI Yacine
 * \param annuaire client* structure contenant les donnees de l'annuaire
 * \param i int longueur de la structure
 * \param nom_p char* Nouveau nom a ajouter
 * \param prenom_p char* Nouveau prenom a ajouter
 * \param cod_postal_p char* Nouveau code postal a ajouter
 * \param ville_p char* Nouvelle ville a ajouter
 * \param mel_p char* Nouveau mail a ajouter
 * \param profession_p char* Nouvelle profession a ajouter
 * \return int
 *
 * Fonction permettant l'ajout d'un nouveau client a l'annuaire
 */
void ajouter_client(client *annuaire, char *nom_p, char *prenom_p, char *code_postal_p, char *ville_p, char *telephone_p, char *mel_p, char *profession_p, int i);


/** \brief Fonction de filtre
 * \author BOUANANI Yacine
 * \param annuaire client* structure contenant les donnees de l'annuaire
 * \param i int longueur de la structure
 * \param champ char* Champ que l'on souhaite filtrer
 * \param val_chaine char* Valeur de la chaine pour le champ
 * \return int
 *
 * Fonction permettant de filtrer l'annuaire en fonction d'un filtre
 */
void filtrer_un_champ(client *annuaire, char champ, char* val_chaine, int i);


/** \brief Fonction d'entree
 * \author BOUANANI Yacine
 * \return int
 *
 * Fonction permettant de trouver le champ � filtrer
 */
char entree_champ_filtre();


/** \brief Fonction d'affichage
 * \author DIAS ARANTES Ricardo
 * \param annuaire client* structure contenant les donnees de l'annuaire
 * \param i int longueur de la structure
 * \return int
 *
 * Fontion affichant l'annuaire complet
 */
int afficher_annuaire(client* annuaire,int i);
