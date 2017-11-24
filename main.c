#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 1000
#define MAX 10000


//STRUCTURE AVEC LES VARIABLES DU JOUEUR

struct Humain
{
    int nbJoueur;
    int nbEssaiRestantJoueur;
    int nbPartiesGagneesJoueur;
    int nbPartiesPerduesJoueur;

};

//STRUCTURE AVEC LES VARIABLES DU PC

struct Ordinateur
{
    int nbAleatoirePC;

};


//STRUCTURE QUI PERMET DE VERIFIER LE RESULTAT ENTRE LA COMBINAISON DU JOUEUR ET CELLE DE L'ORDINATEUR

struct resultat
{
    int nbBienPlace;
    int nbMalPlace;
};

//CETTE FONCTION PERMET DE GENERER LA COMBINAISON ALEATOIRE AVEC 4 CHIFFRES (CODE SECRET)



int main()
{
    struct Humain joueur;
    struct Ordinateur PC;
    srand(time(NULL));


//VARIABLE QUI DEFINI QUE LE JOUEUR JOUE, LE NOMBRE D'ESSAIS RESTANTS AU DEBUT DE LA PARTIE,

    int joueurJoue = 1;
    joueur.nbEssaiRestantJoueur = 10;
    joueur.nbJoueur = 0;
    joueur.nbPartiesGagneesJoueur = 0;
    joueur.nbPartiesPerduesJoueur = 0;



    //ITERATEUR POUR LE TABLEAU

    int i;


//ON INITIALISE LA COMBINAISON ALEATOIRE

    struct Ordinateur random;

    random.nbAleatoirePC = rand() %9+1;



    //ON LANCE LA PARTIE ET ON DEMANDE AU JOUEUR DE SAISIR UNE COMBINAISON.
    while (joueur.nbEssaiRestantJoueur >=1 || joueurJoue == 1)

    {


        printf("Trouvez la combinaison cachee.\nTapez un nombre entre 1000 et 9999:\n");
        scanf("%d", &joueur.nbJoueur);



        //ON CREER LA COMBINAISON ALEATOIRE QUE LE JOUEUR DOIT TROUVER
        PC.nbAleatoirePC = rand() % (MAX-MIN+1) +MIN;


        //ON COMPARE LES RESULTATS      (PAS LE TEMPS DE FINIR)
        if (joueur.nbJoueur == PC.nbAleatoirePC)
        {
            printf("BRAVO VOUS AVEZ TROUVE LA COMBINAISON\n\n");
        }
        else
        {
            joueur.nbEssaiRestantJoueur -= 1;

            printf("Vous ne l'avez pas trouve, il vous reste %d essai(s)\n\n\n", joueur.nbEssaiRestantJoueur);

        }




//QUAND LA PARTIE EST FINIE ON DEMANDE AU JOUEUR SI IL SOUHAITE REFAIRE UNE PARTIE OU NON

        if (joueur.nbEssaiRestantJoueur == 0)
        {
            joueur.nbPartiesPerduesJoueur ++;//ON INFORME LE JOUEUR DU NOMBRE DE PARTIES PERDUES


            printf("Vous avez perdu %d partie(s)\n", joueur.nbPartiesPerduesJoueur);
            printf("Vous avez perdu. Voulez-vous rejouer?\n");
            scanf("%d", &joueurJoue);
            if (joueurJoue == 1)
            {
                joueur.nbEssaiRestantJoueur = 10;
            }
        }
        if (joueur.nbJoueur == PC.nbAleatoirePC)
        {
            joueur.nbPartiesGagneesJoueur++; //ON INFORME LE JOUEUR DU NOMBRE DE PARTIES QU'IL A GAGNE

            printf("Vous avez gagne %d partie(s)\n", joueur.nbPartiesGagneesJoueur);
            printf("voulez-vous rejouer?\n");
            scanf("%d", &joueurJoue);
            if (joueurJoue == 1)
            {
                joueur.nbEssaiRestantJoueur = 10;
            }
        }


    }

    return 0;
}















