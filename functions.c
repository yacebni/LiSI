#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
/** Fichier contenant les definitions des differentes fonctions du programme du chargement a la modification.
 * \brief Fichier contenant les fonctions du programme
 */
/**\file functions.c */
#define LEN 200
#define LVIDE 2



int enter_n_file(char* f)
{
    char e[LEN];
    FILE* nfile;

    do{
        printf("Veuillez entrer le nom de votre fichier et son extension :");
        fgets(f,LEN,stdin);

        if (f[0]=='\n')
        {
            printf("Voulez-vous fermer l'application? Pour quitter entrez 1.\n");
            fgets(e,LEN,stdin);

            if (e[0]=='1')
            {
                printf("Fermeture de l'application. Veuillez patienter.\n");
                exit(0);
                return EXIT_SUCCESS;
            }
        }

        int l=(int)strlen(f);

        if (f[l-1]=='\n')
        {
            f[l-1]='\0';
        }

        nfile = fopen(f, "r");

        if (nfile==NULL)
        {
            perror("");
        }
    }
    while (nfile==NULL);
    fclose(nfile);

    return 0;
}


int cpt_lignes(char* nfichier)
{
    char d;
    int i=0;
    FILE* entree;
    entree = fopen(nfichier, "r");

    if(entree == NULL)
    {
        perror(nfichier);
        exit(EXIT_FAILURE);
    }

    while(! feof(entree))
    {
        d=fgetc(entree);

        if(d == '\n' || d == '\r')
        {
            i=i+1;
        }
    }
    fclose(entree);
    return i;
}


int charge_annuaire(char* nfichier,client *annuaire,int i)
{
    char d;
    int y;
    FILE* entree;
    entree = fopen(nfichier, "r");

    if(entree == NULL)
    {
        perror(nfichier);
        exit(EXIT_FAILURE);
    }

    rewind(entree);

    for(y=0;y<i;y++)
    {
        int z=0;
        d=fgetc(entree);

        while(d!=',' && d!='\r' && d!='\n')
        {
            annuaire[y].nom[z]=d;
            d=fgetc(entree);
            z++;
        }

        annuaire[y].nom[z]='\0';
        z=0;
        d=fgetc(entree);

        while(d!=',' && d!='\r' && d!='\n')
        {
            annuaire[y].prenom[z]=d;
            d=fgetc(entree);
            z++;
        }

        annuaire[y].prenom[z]='\0';
        z=0;
        d=fgetc(entree);

        while(d!=',' && d!='\r' && d!='\n')
        {
            annuaire[y].codepost[z]=d;
            d=fgetc(entree);
            z++;
        }

        annuaire[y].codepost[z]='\0';
        z=0;
        d=fgetc(entree);

        while(d!=',' && d!='\r' && d!='\n')
        {
            annuaire[y].ville[z]=d;
            d=fgetc(entree);
            z++;
        }

        annuaire[y].ville[z]='\0';
        z=0;
        d=fgetc(entree);

        while(d!=',' && d!='\r' && d!='\n')
        {
            annuaire[y].telephone[z]=d;
            d=fgetc(entree);
            z++;
        }

        annuaire[y].telephone[z]='\0';
        z=0;
        d=fgetc(entree);

        while(d!=',' && d!='\r' && d!='\n')
        {
            annuaire[y].mail[z]=d;
            d=fgetc(entree);
            z++;
        }

        annuaire[y].mail[z]='\0';
        z=0;
        d=fgetc(entree);

        while(d!=',' && d!='\r' && d!='\n')
        {
            annuaire[y].profession[z]=d;
            d=fgetc(entree);
            z++;
        }

        annuaire[y].profession[z]='\0';
    }
    fclose(entree);

    return 0;
}


int valider_annuaire(client *annuaire,int i)
{
    int a=0,xa=0,xb=0;
    char vide[LVIDE];
    vide[0]='\0';

    while (xa<i && a!=1)
    {
        if (strcmp(annuaire[xa].mail,vide)==0)
        {
            a=1;
            printf("Erreur ! Email vide detecte a la ligne %d de l'annuaire.\n",xa);
        }
        while (xb<i && a!=1)
        {
            if (xa==xb)
            {
                xb++;
            }

            if (strcmp(annuaire[xa].mail,annuaire[xb].mail)==0)
            {
                printf("Erreur ! Doublons detectes aux lignes %d et %d de l'annuaire.\n",xa,xb);
                printf("ligne %d:%s\nligne %d:%s\n",xa,annuaire[xa].mail,xb,annuaire[xb].mail);
                a=1;
            }
            xb++;
        }

        xa++;
        xb=xa;
    }

    return a;
}


char entree_menu_gene()
{
    char entree[LEN];
    printf("Que voulez-vous faire?\n");
    printf("1 - Affichages de l'annuaire\n");
    printf("2 - Modifications de l'annuaire\n");
    printf("3 - Sauvegardes de l'annuaire\n");
    printf("4 - Quitter\n");
    do
    {
        fgets(entree,LEN,stdin);
    }
    while(entree[0]=='\n'||entree[0]=='\r');
    return entree[0];
}


char entree_menu_affi()
{
    char entree[LEN];
    printf("Que voulez-vous afficher?\n");
    printf("1 - Annuaire complet\n");
    printf("2 - Annuaire filtre\n");
    printf("3 - Annuaire trie\n");
    printf("4 - Retourner au menu principal de l'application\n");
    do
    {
        fgets(entree,LEN,stdin);
    }
    while(entree[0]=='\n'||entree[0]=='\r');
    return entree[0];
}


char entree_menu_save()
{
    char entree[LEN];
    printf("Que voulez-vous faire?\n");
    printf("1 - Sauvegarde de l'annuaire dans le fichier d'origine.\n");
    printf("2 - Sauvegarde de l'annuaire dans un fichier existant.\n");
    printf("3 - Sauvegarde de l'annuaire dans un nouveau fichier.\n");
    printf("4 - Retourner au menu principal de l'application\n");
    do
    {
        fgets(entree,LEN,stdin);
    }
    while(entree[0]=='\n'||entree[0]=='\r');
    return entree[0];
}


char entree_menu_mod_ann()
{
    char entree[LEN];
    printf("Que voulez-vous faire?\n");
    printf("1 - Ajouter un client\n");
    printf("2 - Supprimer un client\n");
    printf("3 - Modifier les donnees d'un client\n");
    printf("4 - Retourner au menu principal de l'application\n");
    do
    {
        fgets(entree,LEN,stdin);
    }
    while(entree[0]=='\n'||entree[0]=='\r');
    return entree[0];
}


char entree_menu_mod_client()
{
    char entree[LEN];
    printf("Que voulez-vous faire?\n");
    printf("1 - Modifier le nom d'un client\n");
    printf("2 - Modifier le prenom d'un client\n");
    printf("3 - Modifier le code postal d'un client\n");
    printf("4 - Modifier la ville d'un client\n");
    printf("5 - Modifier le numero de telephone d'un client\n");
    printf("6 - Modifier le mail d'un client\n");
    printf("7 - Modifier la profession d'un client\n");
    printf("8 - Retourner au menu de modification d'annuaire\n");
    do
    {
        fgets(entree,LEN,stdin);
    }
    while(entree[0]=='\n'||entree[0]=='\r');
    return entree[0];
}


int entree_anmail(char* anmail)
{
    do{
        printf("Veuillez entrer un mail a remplacer :");
        fgets(anmail,LEN,stdin);
    }
    while(anmail[0]=='\n');

    int i=0;
    while (anmail[i]!='\0')
    {
        if (anmail[i]=='\n'||anmail[i]=='\r')
        {
            anmail[i]='\0';
        }
        i++;
    }
    return 0;
}


int entree_nmail(char* nmail)
{
    do{
        printf("Veuillez entrer un mail pour le remplacement:");
        fgets(nmail,LEN,stdin);
    }
    while(nmail[0]=='\n');

    int i=0;
    while (nmail[i]!='\0')
    {
        if (nmail[i]=='\n'||nmail[i]=='\r')
        {
            nmail[i]='\0';
        }
        i++;
    }
    return 0;
}


int entree_n_newfile(char* f_sauvegarde)
{
    do{
        printf("Veuillez entrer le nom du fichier csv a creer :");
        fgets(f_sauvegarde,LEN,stdin);
    }
    while(f_sauvegarde[0]=='\n');

    int i=0;
    while (f_sauvegarde[i]!='\0')
    {
        if (f_sauvegarde[i]=='\n'||f_sauvegarde[i]=='\r')
        {
            f_sauvegarde[i]='\0';
        }
        if (f_sauvegarde[i]=='.')
        {
            f_sauvegarde[i]='_';
        }
        i++;
    }
    strcat(f_sauvegarde,".csv");
    return 0;
}


int entree_mail(char* mail)
{
    do{
        printf("Veuillez entrer un mail pour le remplacement:");
        fgets(mail,LEN,stdin);
    }
    while(mail[0]=='\n');

    int i=0;
    while (mail[i]!='\0')
    {
        if (mail[i]=='\n'||mail[i]=='\r')
        {
            mail[i]='\0';
        }
        i++;
    }
    return 0;
}


int entree_donnee(char* donnee)
{
    do{
        printf("Veuillez entrer la donnee a inserer :");
        fgets(donnee,LEN,stdin);
    }
    while(donnee[0]=='\n');

    int i=0;
    while (donnee[i]!='\0')
    {
        if (donnee[i]=='\n'||donnee[i]=='\r')
        {
            donnee[i]='\0';
        }
        i++;
    }
    return 0;
}


int entree_val_filtre(char* val_chaine)
{
    do{
        printf("Veuillez entrer la valeur de la chaine recherchee :");
        fgets(val_chaine,LEN,stdin);
    }
    while(val_chaine[0]=='\n');

    int i=0;
    while (val_chaine[i]!='\0')
    {
        if (val_chaine[i]=='\n'||val_chaine[i]=='\r')
        {
            val_chaine[i]='\0';
        }
        i++;
    }
    return 0;
}


int entree_supmail(char* supmail)
{
    do{
        printf("Veuillez entrer un mail pour le client a supprimer :");
        fgets(supmail,LEN,stdin);
    }
    while(supmail[0]=='\n');

    int i=0;
    while (supmail[i]!='\0')
    {
        if (supmail[i]=='\n'||supmail[i]=='\r')
        {
            supmail[i]='\0';
        }
        i++;
    }
    return 0;
}


char entree_champ_filtre()
{
    char entree[LEN];
    printf("Veuillez entrer le champ a filtrer.\n");
    printf("1 - Nom\n");
    printf("2 - Prenom\n");
    printf("3 - Code postal\n");
    printf("4 - Ville\n");
    printf("5 - Numero\n");
    printf("6 - Mail\n");
    printf("7 - Profession\n");
    do
    {
        fgets(entree,LEN,stdin);
    }
    while(entree[0]=='\n'||entree[0]=='\r');

    return entree[0];
}


int modifier_mail(client *annuaire,int i,char* anmail,char* nmail)
{
    char f_save[LEN]="resultat_modifier_mel.txt";
    int ligne=-1,j,vr=0;
    for(j=0;j<i;j++)
    {

        if (strcmp(annuaire[j].mail, anmail) == 0)
        {
            printf("Mail a remplacer trouve.\n");
            ligne=j;
        }
    }
    if (ligne==-1)
    {
        printf("Erreur ! Mail non present dans l'annuaire, impossible de remplacer.\n");
    }
    else
    {
        j=0;
        while (j<i && vr==0)
        {
            if (strcmp(annuaire[j].mail, nmail) == 0)
            {
                printf("Nouveau mail deja present a la ligne %d insertion impossible.\n",j);
                vr=1;
            }
            j++;
        }
        if (vr==0)
        {
            printf("Remplacement en cours...\n");
            strcpy(annuaire[ligne].mail,nmail);
            printf("Remplacement effectue.\n");
            sauvegarde_annuaire(f_save,annuaire,i);
        }


    }
    return 0;
}


int modifier_autre_mail(client *annuaire,int i,char* mail,char* ndonnee,int champ)
{
    char f_save[LEN]="resultat_modifier_autres_que_mel.txt";
    int ligne=-1,j;
    for(j=0;j<i;j++)
    {

        if (strcmp(annuaire[j].mail, mail) == 0)
        {
            printf("Mail trouve.\n");
            ligne=j;
        }
    }
    if (ligne==-1)
    {
        printf("Erreur ! Mail non present dans l'annuaire, impossible de modifier.\n");
    }
    else
    {
        printf("Modification en cours...\n");
        switch(champ)
        {
            case 1:
                strcpy(annuaire[ligne].nom,ndonnee);
                break;
            case 2:
                strcpy(annuaire[ligne].prenom,ndonnee);
                break;
            case 3:
                strcpy(annuaire[ligne].codepost,ndonnee);
                break;
            case 4:
                strcpy(annuaire[ligne].ville,ndonnee);
                break;
            case 5:
                strcpy(annuaire[ligne].telephone,ndonnee);
                break;
            case 6:
                strcpy(annuaire[ligne].profession,ndonnee);
                break;
        }
        printf("Modification effectuee.\n");
        sauvegarde_annuaire(f_save,annuaire,i);
    }
    return 0;
}


int sauvegarde_annuaire(char* nfichier,client *annuaire,int i)
{
    FILE* sortie;
    sortie=fopen(nfichier,"w");
    if(sortie == NULL)
    {
        perror(nfichier);
        exit(EXIT_FAILURE);
    }
    int y;
    for(y=0;y<i;y++)
    {
        fprintf(sortie,"%s,%s,%s,%s,%s,%s,%s\n",annuaire[y].nom,annuaire[y].prenom,annuaire[y].codepost,annuaire[y].ville,annuaire[y].telephone,annuaire[y].mail,annuaire[y].profession);
        fflush(sortie);
    }
    fclose(sortie);
    return 0;
}


int supprimer_client(client *annuaire,int i,char* supmail)
{
    int ligne=-1, j;
    char f_save[LEN]="resultat_supprimer.txt";
    for(j=0;j<i;j++)
    {
        if (strcmp(annuaire[j].mail, supmail) == 0)
        {
            printf("Mail du client a supprimer trouve.\n");
            ligne=j;
        }
    }
    if (ligne==-1)
    {
        printf("Le client avec le mail %s n'a pas ete trouve dans l'annuaire.\n", supmail);
        return 0;
    }

  // Suppression du client
    else {
        printf("Suppression en cours...\n");
        int j;
        for (j = ligne; j < i-1; j++)
        {
            strcpy(annuaire[j].nom,annuaire[j+1].nom);
            strcpy(annuaire[j].prenom,annuaire[j+1].prenom);
            strcpy(annuaire[j].codepost,annuaire[j+1].codepost);
            strcpy(annuaire[j].ville,annuaire[j+1].ville);
            strcpy(annuaire[j].telephone,annuaire[j+1].telephone);
            strcpy(annuaire[j].mail,annuaire[j+1].mail);
            strcpy(annuaire[j].profession,annuaire[j+1].profession);
        }
        annuaire[j].nom[0]='\0';
        annuaire[j].prenom[0]='\0';
        annuaire[j].codepost[0]='\0';
        annuaire[j].ville[0]='\0';
        annuaire[j].telephone[0]='\0';
        annuaire[j].mail[0]='\0';
        annuaire[j].profession[0]='\0';
        printf("Suppression effectuee.\n");
        sauvegarde_annuaire(f_save,annuaire,i-1);
        }
    return 0;
}


void ajouter_client(client *annuaire, char *nom_p, char *prenom_p, char *code_postal_p, char *ville_p, char *telephone_p, char *mel_p, char *profession_p, int i)
{
    char f_save[LEN]="resultat_ajouter.txt";

    int j=0,vr=0;
    while (j<i && vr==0)
    {
        if (strcmp(annuaire[j].mail, mel_p) == 0)
        {
            printf("Client deja present a la ligne %d insertion impossible.\n",j);
            vr=1;
        }
        j++;
    }
    if (vr==0)
    {
        i++;
        annuaire=(client*)realloc(annuaire,i*sizeof(client));
        strcpy(annuaire[i-1].nom,nom_p);
        strcpy(annuaire[i-1].prenom,prenom_p);
        strcpy(annuaire[i-1].codepost,code_postal_p);
        strcpy(annuaire[i-1].ville,ville_p);
        strcpy(annuaire[i-1].telephone,telephone_p);
        strcpy(annuaire[i-1].mail,mel_p);
        strcpy(annuaire[i-1].profession,profession_p);
        printf("Client ajoute.\n");

        sauvegarde_annuaire(f_save,annuaire,i);
    }
    return;

}


void filtrer_un_champ(client *annuaire, char champ, char* val_chaine, int i)
{
    char f_save[LEN]="resultat_filtrer_un_champ.txt";
    client filtre[i];
    int compteur=0,j;

    for(j=0;j<i;j++)
    {
        switch(champ)
        {
            case '1':
                if (strcmp(annuaire[j].nom, val_chaine) == 0)
                {
                    filtre[compteur]=annuaire[j];
                    compteur++;
                }
                break;

            case '2':
                if (strcmp(annuaire[j].prenom, val_chaine) == 0)
                {
                    filtre[compteur]=annuaire[j];
                    compteur++;
                }
                break;

            case '3':
                if (strcmp(annuaire[j].codepost, val_chaine) == 0)
                {
                    filtre[compteur]=annuaire[j];
                    compteur++;
                }
                break;

            case '4':
                if (strcmp(annuaire[j].ville, val_chaine) == 0)
                {
                    filtre[compteur]=annuaire[j];
                    compteur++;
                }
                break;

            case '5':
                if (strcmp(annuaire[j].telephone, val_chaine) == 0)
                {
                    filtre[compteur]=annuaire[j];
                    compteur++;
                }
                break;

            case '6':
                if (strcmp(annuaire[j].mail, val_chaine) == 0)
                {
                    filtre[compteur]=annuaire[j];
                    compteur++;
                }
                break;

            case '7':
                if (strcmp(annuaire[j].profession, val_chaine) == 0)
                {
                    filtre[compteur]=annuaire[j];
                    compteur++;
                }
                break;

            default:
                printf("Erreur ! Champ specifie non valide.\n");
                return;
        }
    }
    if (compteur == 0) {
            printf("Aucun client ne correspond au critere de recherche.\n");
            return;
    }
    else {
        printf("Client correspondant au filtre trouve.\n");
        afficher_annuaire(filtre,compteur);
        sauvegarde_annuaire(f_save,filtre,compteur);
    }
    return;
}


int afficher_annuaire(client* annuaire,int i)
{
    int j=0;
    while (j<i-1)
    {
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("|Nom : %-25s                            |Nom : %-25s                           |\n",annuaire[j].nom,annuaire[j+1].nom);
        printf("|Prenom : %-25s                         |Prenom : %-25s                        |\n",annuaire[j].prenom,annuaire[j+1].prenom);
        printf("|Codepost : %-25s                       |Codepost : %-25s                      |\n",annuaire[j].codepost,annuaire[j+1].codepost);
        printf("|Ville : %-25s                          |Ville : %-25s                         |\n",annuaire[j].ville,annuaire[j+1].ville);
        printf("|Telephone : %-25s                      |Telephone : %-25s                     |\n",annuaire[j].telephone,annuaire[j+1].telephone);
        printf("|Mail : %-50s  |Mail : %-50s |\n",annuaire[j].mail,annuaire[j+1].mail);
        printf("|Profession : %-25s                     |Profession : %-25s                    |\n",annuaire[j].profession,annuaire[j+1].profession);
        j=j+2;
    }
    if (i%2==0&&i-j>=2)
    {
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("|Nom : %-25s                            |Nom : %-25s                           |\n",annuaire[j].nom,annuaire[j+1].nom);
        printf("|Prenom : %-25s                         |Prenom : %-25s                        |\n",annuaire[j].prenom,annuaire[j+1].prenom);
        printf("|Codepost : %-25s                       |Codepost : %-25s                      |\n",annuaire[j].codepost,annuaire[j+1].codepost);
        printf("|Ville : %-25s                          |Ville : %-25s                         |\n",annuaire[j].ville,annuaire[j+1].ville);
        printf("|Telephone : %-25s                      |Telephone : %-25s                     |\n",annuaire[j].telephone,annuaire[j+1].telephone);
        printf("|Mail : %-50s  |Mail : %-50s |\n",annuaire[j].mail,annuaire[j+1].mail);
        printf("|Profession : %-25s                     |Profession : %-25s                    |\n",annuaire[j].profession,annuaire[j+1].profession);
        j=j+2;
    }
    else if(i-j>0)
    {
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("|Nom : %-25s                            |\n",annuaire[j].nom);
        printf("|Prenom : %-25s                         |\n",annuaire[j].prenom);
        printf("|Codepost : %-25s                       |\n",annuaire[j].codepost);
        printf("|Ville : %-25s                          |\n",annuaire[j].ville);
        printf("|Telephone : %-25s                      |\n",annuaire[j].telephone);
        printf("|Mail : %-50s  |\n",annuaire[j].mail);
        printf("|Profession : %-25s                     |\n",annuaire[j].profession);
        j++;
    }
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    return 0;
}
