#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/** Fichier principal en charge d'ordonner l'execution des fonctions definies dans functions.c
 * \brief Fichier principal du programme
 */
/**\file main.c */
#include "functions.h"
#define LEN 200
#define MAIL 50
int main()
{
    char f[LEN],f_sauvegarde[LEN],donnee[MAIL],ancienmail[MAIL],newmail[MAIL],mail[MAIL],supmail[MAIL];
    char nom_p[MAIL],prenom_p[MAIL],codepost_p[MAIL],ville_p[MAIL],tel_p[MAIL],profession_p[MAIL],mel_p[MAIL],val_chaine[MAIL];
    char champ;
    char entree_gen,entree_mod_ann,entree_mod_client,entree_save,entree_affi;
    int va;
    int execution=0,modification_annuaire=0,modification_client=0,save_annuaire=0,affi_annuaire=0;

    /*entree du nom de fichier*/
    enter_n_file(f);
    printf("Ouverture du fichier reussite.\n");
    /*-------------*/

    printf("------------------------------------------------------------------------------------------------------------------------\n");

    /*chargement*/
    printf("Chargement des donnees en cours...\n");
    int n=cpt_lignes(f);
    client *annuaire=(client *) calloc(n,sizeof(client));

    charge_annuaire(f,annuaire,n);
    printf("Chargement des donnees effectue.\n");
    /*-------------*/

    printf("------------------------------------------------------------------------------------------------------------------------\n");

    /*validation*/
    printf("Validation de l'annuaire en cours...\n");
    va=valider_annuaire(annuaire,n);
    if (va==1)
    {
        printf("Fermeture de l'application. Veuillez patienter.\n");
        exit(0);
        return EXIT_SUCCESS;
    }
    else
    {
        printf("Fichier d'annuaire valide. Aucun doublon d'email detecte.\n");
    }
    /*-----------------*/

    printf("------------------------------------------------------------------------------------------------------------------------\n");

    /*boucle principale*/
    while(execution==0)
    {
        entree_gen=entree_menu_gene();
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        switch(entree_gen)
        {
            case '1':/*affichage d'annuaire*/
                affi_annuaire=0;
                while(affi_annuaire==0)
                {
                    entree_affi=entree_menu_affi();

                    switch(entree_affi)
                    {
                    case '1':
                        afficher_annuaire(annuaire,n);
                        break;

                    case '2':
                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                        champ=entree_champ_filtre();
                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                        entree_val_filtre(val_chaine);
                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                        filtrer_un_champ(annuaire,champ,val_chaine,n);
                        break;

                    case '3':
                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                        break;

                    case '4':
                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                        affi_annuaire=1;
                        break;

                    default :
                        printf("Erreur ! Entree non reconnue\n");
                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                    }
                }
                break;/*-----------*/

            case '2':/*modification d'annuaire*/
                modification_annuaire=0;
                while (modification_annuaire==0)
                {
                    entree_mod_ann=entree_menu_mod_ann();
                    printf("------------------------------------------------------------------------------------------------------------------------\n");
                    switch(entree_mod_ann)
                    {
                        case '1':
                            printf("Entrez le nom du client :");
                            fgets(nom_p,LEN,stdin);
                            printf("Entrez le prenom du client : ");
                            fgets(prenom_p,LEN,stdin);
                            printf("Entrez le code postal du client : ");
                            fgets(codepost_p,LEN,stdin);
                            printf("Entrez la ville du client : ");
                            fgets(ville_p,LEN,stdin);
                            printf("Entrez le telephone du client : ");
                            fgets(tel_p,LEN,stdin);
                            printf("Entrez le mail du client : ");
                            fgets(mel_p,LEN,stdin);
                            printf("Entrez la profession du client : ");
                            fgets(profession_p,LEN,stdin);

                            strtok(nom_p,"\n");
                            strtok(prenom_p,"\n");
                            strtok(codepost_p,"\n");
                            strtok(ville_p,"\n");
                            strtok(tel_p,"\n");
                            strtok(mel_p,"\n");
                            strtok(profession_p, "\n");
                            printf("------------------------------------------------------------------------------------------------------------------------\n");
                            ajouter_client(annuaire,nom_p,prenom_p,codepost_p,ville_p,tel_p,mel_p,profession_p,n);
                            printf("------------------------------------------------------------------------------------------------------------------------\n");
                            n++;
                            break;

                        case '2':
                                entree_supmail(supmail);
                                printf("------------------------------------------------------------------------------------------------------------------------\n");
                                supprimer_client(annuaire,n,supmail);
                                n--;
                                annuaire=(client*)realloc(annuaire,n*sizeof(client));
                                printf("------------------------------------------------------------------------------------------------------------------------\n");
                                break;

                        case '3':/*modification de champs du client*/
                            modification_client=0;
                            while(modification_client==0)
                            {
                                entree_mod_client=entree_menu_mod_client();
                                printf("------------------------------------------------------------------------------------------------------------------------\n");
                                switch(entree_mod_client)
                                {
                                    case '1':
                                        entree_mail(mail);
                                        entree_donnee(donnee);
                                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                                        modifier_autre_mail(annuaire,n,mail,donnee,1);
                                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                                        break;
                                    case '2':
                                        entree_mail(mail);
                                        entree_donnee(donnee);
                                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                                        modifier_autre_mail(annuaire,n,mail,donnee,2);
                                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                                        break;
                                    case '3':
                                        entree_mail(mail);
                                        entree_donnee(donnee);
                                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                                        modifier_autre_mail(annuaire,n,mail,donnee,3);
                                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                                        break;
                                    case '4':
                                        entree_mail(mail);
                                        entree_donnee(donnee);
                                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                                        modifier_autre_mail(annuaire,n,mail,donnee,4);
                                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                                        break;
                                    case '5':
                                        entree_mail(mail);
                                        entree_donnee(donnee);
                                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                                        modifier_autre_mail(annuaire,n,mail,donnee,5);
                                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                                        break;
                                    case '6':
                                        entree_anmail(ancienmail);
                                        entree_nmail(newmail);
                                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                                        modifier_mail(annuaire,n,ancienmail,newmail);
                                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                                        break;
                                    case '7':
                                        entree_mail(mail);
                                        entree_donnee(donnee);
                                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                                        modifier_autre_mail(annuaire,n,mail,donnee,6);
                                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                                        break;
                                    case '8':
                                        modification_client=1;
                                        break;
                                    default:
                                        printf("Erreur ! Entree non reconnue\n");
                                        printf("------------------------------------------------------------------------------------------------------------------------\n");
                                }
                            }
                            break;/*-------------------*/

                        case '4':
                            modification_annuaire=1;
                            break;

                        default:
                            printf("Erreur ! Entree non reconnue\n");
                            printf("------------------------------------------------------------------------------------------------------------------------\n");
                    }
                }
                break;/*----------------------*/

            case '3':
                save_annuaire=0;
                while(save_annuaire==0)
                {
                    entree_save=entree_menu_save();
                    printf("------------------------------------------------------------------------------------------------------------------------\n");
                    switch(entree_save)
                    {
                        case '1':
                            printf("Sauvegarde de l'annuaire en cours...\n");
                            sauvegarde_annuaire(f,annuaire,n);
                            printf("Sauvegarde de l'annuaire en effectue.\n");
                            printf("------------------------------------------------------------------------------------------------------------------------\n");
                            break;
                        case '2':
                            enter_n_file(f_sauvegarde);
                            printf("------------------------------------------------------------------------------------------------------------------------\n");
                            printf("Sauvegarde de l'annuaire en cours...\n");
                            sauvegarde_annuaire(f_sauvegarde,annuaire,n);
                            printf("Sauvegarde de l'annuaire en effectue.\n");
                            printf("------------------------------------------------------------------------------------------------------------------------\n");
                            break;
                        case '3':
                            entree_n_newfile(f_sauvegarde);
                            printf("------------------------------------------------------------------------------------------------------------------------\n");
                            printf("Sauvegarde de l'annuaire en cours...\n");
                            sauvegarde_annuaire(f_sauvegarde,annuaire,n);
                            printf("Sauvegarde de l'annuaire en effectue.\n");
                            printf("------------------------------------------------------------------------------------------------------------------------\n");
                            break;
                        case '4':
                            save_annuaire=1;
                            break;
                        default :
                            printf("Erreur ! Entree non reconnue\n");
                            printf("------------------------------------------------------------------------------------------------------------------------\n");
                    }
                }
                break;

            case '4':
                printf("Fermeture de l'application. Veuillez patienter.\n");
                exit(0);
                return EXIT_SUCCESS;

            default:
                printf("Erreur ! Entree non reconnue\n");
                printf("------------------------------------------------------------------------------------------------------------------------\n");
        }
    }
    /*----------*/

    return 0;
}
