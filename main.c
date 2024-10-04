#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char nom[50];
    char prenom[50];
    char telephone[15];
    int age;
    int statut;
    int reference;
    char date[11];
} Reservation;

Reservation RDV[100] = {

    {"najjari", "amine", "0655983456", 30, 1, 1, "2024-09-01"},
    {"houda", "lamal", "0752345489", 25, 3, 2, "2024-10-02"},
    {"imad", "halid", "0698742589", 45, 1, 3, "2024-12-03"},
    {"ilyass", "benchikh", "0662147954", 60, 4, 4, "2024-06-04"},
    {"bahia", "jaouhari", "0662181890", 22, 1, 5, "2024-02-05"},
    {"haitam", "aya", "0615479632", 16, 2, 6, "2024-11-06"},
    {"badr", "ilok", "0613467920", 27, 3, 7, "2024-12-07"},
    {"said", "finfi", "0601987461", 37, 4, 8, "2024-04-08"},
    {"layla", "ali", "061564845", 41, 2, 9, "2024-09-09"},
    {"amina", "minok", "0749325549", 17, 3, 10, "2024-08-10"}
};

int compteur = 10;

void afficher() {
   printf("\nListe des Reservations :\n\n");

    for (int i = 0; i < compteur; i++) {
        printf("Reservation %d: Nom: %s, Prenom: %s, Telephone: %s, Age: %d, Statut: %d, Date: %s\n",
               RDV[i].reference, RDV[i].nom, RDV[i].prenom, RDV[i].telephone,
               RDV[i].age, RDV[i].statut, RDV[i].date);
}
}
void ajouter() {
    if (compteur >= 100) {
        printf("La memoire est pleine, impossible d'ajouter une nouvelle reservation.\n");
        return;
    }

    Reservation r;
    getchar();
    printf("Nom : ");
    scanf ("%s",r.nom);
    printf("Prenom : ");
    scanf("%s", r.prenom);
    printf("Telephone : ");
    scanf("%s", r.telephone);
    printf("Age : ");
    scanf("%d", &r.age);
    printf("Statut (1-valide, 2-reporte, 3-annule, 4-traite) : ");
    scanf("%d", &r.statut);
    r.reference = compteur + 1;
    printf("Date de reservation (YYYY-MM-DD) : ");
    scanf("%s", r.date);

    RDV[compteur] = r;
    compteur++;
    printf("Reservation ajoutee avec succes.\n");
}

void modifier() {
    int ref;
    printf("Entrez la reference de la reservation a modifier : ");
    scanf("%d", &ref);
    bool found = false;

    for (int i = 0; i < compteur; i++) {
        if (RDV[i].reference == ref) {
            found = true;
            printf("Modifier le Nom (%s) : ", RDV[i].nom);
            scanf("%s", RDV[i].nom);
            printf("Modifier le Prenom (%s) : ", RDV[i].prenom);
            scanf("%s", RDV[i].prenom);
            printf("Modifier le Telephone (%s) : ", RDV[i].telephone);
            scanf("%s", RDV[i].telephone);
            printf("Modifier l'Age (%d) : ", RDV[i].age);
            scanf("%d", &RDV[i].age);
            printf("Modifier le Statut (%d) : ", RDV[i].statut);
            scanf("%d", &RDV[i].statut);
            printf("Modifier la Date (%s) : ", RDV[i].date);
            scanf("%s", RDV[i].date);
            printf("Reservation modifiee avec succes.\n");
            break;
        }
    }
    if (!found) {
        printf("Reservation non trouvee.\n");
    }
}

void supprimer() {
    int ref;
    printf("Entrez la reference de la reservation a supprimer : ");
    scanf("%d", &ref);
    bool found = false;

    for (int i = 0; i < compteur; i++) {
        if (RDV[i].reference == ref) {
            found = true;
            for (int j = i; j < compteur - 1; j++) {
                RDV[j] = RDV[j + 1];
            }
            compteur--;
            printf("Reservation supprimee avec succes.\n");
            break;
        }
    }
    if (!found) {
        printf("Reservation non trouvee.\n");
    }
}

void afficherDetail() {
    int ref;
    printf("Entrez la reference de la reservation a afficher : ");
    scanf("%d", &ref);
    bool found = false;

    for (int i = 0; i < compteur; i++) {
        if (RDV[i].reference == ref) {
            found = true;
            printf("Details de la reservation:\n");
            printf("Nom: %s\n", RDV[i].nom);
            printf("Prenom: %s\n", RDV[i].prenom);
            printf("Telephone: %s\n", RDV[i].telephone);
            printf("Age: %d\n", RDV[i].age);
            printf("Statut: %d\n", RDV[i].statut);
            printf("Reference: %d\n", RDV[i].reference);
            printf("Date: %s\n", RDV[i].date);
            break;
        }
    }
    if (!found) {
        printf("Reservation non trouvee.\n");
    }
}

void trier() {
    int choixTri;
    printf("Choisissez le crit�re de tri:\n");
    printf("1 - Trier par nom\n");
    printf("2 - Trier par statut\n");
    printf("Taper votre choix : ");
    scanf("%d", &choixTri);

    if (choixTri == 1) {

        for (int i = 0; i < compteur - 1; i++) {
            for (int j = 0; j < compteur - 1 - i; j++) {
                if (strcmp(RDV[j].nom, RDV[j + 1].nom) > 0) {

                    Reservation temp = RDV[j];
                    RDV[j] = RDV[j + 1];
                    RDV[j + 1] = temp;
                }
            }
        }
        printf("Reservations triees par nom.\n");
    } else if (choixTri == 2) {
        // Tri par statut (simple bubble sort)
        for (int i = 0; i < compteur - 1; i++) {
            for (int j = 0; j < compteur - 1 - i; j++) {
                if (RDV[j].statut > RDV[j + 1].statut) {

                    Reservation temp = RDV[j];
                    RDV[j] = RDV[j + 1];
                    RDV[j + 1] = temp;
                }
            }
        }
        printf("Reservations triees par statut.\n");
    } else {
        printf("Choix invalide !\n");
    }
}

void rechercher() {
    int choixRecherche;
    printf("Choisissez le crit�re de recherche:\n");
    printf("1 - Recherche par r�f�rence\n");
    printf("2 - Recherche par nom\n");
    printf("3 - Recherche par date\n");
    printf("Taper votre choix : ");
    scanf("%d", &choixRecherche);

    switch (choixRecherche) {
        case 1: {
            int ref;
            printf("Entrez la r�f�rence � rechercher : ");
            scanf("%d", &ref);
            bool found = false;

            for (int i = 0; i < compteur; i++) {
                if (RDV[i].reference == ref) {
                    found = true;
                    printf("R�servation trouv�e:\n");
                    printf("Nom: %s\n", RDV[i].nom);
                    printf("Prenom: %s\n", RDV[i].prenom);
                    printf("Telephone: %s\n", RDV[i].telephone);
                    printf("Age: %d\n", RDV[i].age);
                    printf("Statut: %d\n", RDV[i].statut);
                    printf("Date: %s\n", RDV[i].date);
                    break;
                }
            }
            if (!found) {
                printf("R�servation non trouv�e.\n");
            }
            break;
        }
        case 2: {
            char nom[50];
            printf("Entrez le nom � rechercher : ");
            scanf("%s", nom);
            bool found = false;

            for (int i = 0; i < compteur; i++) {
                if (strcmp(RDV[i].nom, nom) == 0) {
                    found = true;
                    printf("R�servation trouv�e:\n");
                    printf("Nom: %s\n", RDV[i].nom);
                    printf("Prenom: %s\n", RDV[i].prenom);
                    printf("Telephone: %s\n", RDV[i].telephone);
                    printf("Age: %d\n", RDV[i].age);
                    printf("Statut: %d\n", RDV[i].statut);
                    printf("Reference: %d\n", RDV[i].reference);
                    printf("Date: %s\n", RDV[i].date);
                }
            }
            if (!found) {
                printf("Aucune r�servation trouv�e pour le nom %s.\n", nom);
            }
            break;
        }
        case 3: {
            char date[11];
            printf("Entrez la date � rechercher (YYYY-MM-DD) : ");
            scanf("%s", date);
            bool found = false;

            for (int i = 0; i < compteur; i++) {
                if (strcmp(RDV[i].date, date) == 0) {
                    found = true;
                    printf("R�servation trouv�e:\n");
                    printf("Nom: %s\n", RDV[i].nom);
                    printf("Prenom: %s\n", RDV[i].prenom);
                    printf("Telephone: %s\n", RDV[i].telephone);
                    printf("Age: %d\n", RDV[i].age);
                    printf("Statut: %d\n", RDV[i].statut);
                    printf("Reference: %d\n", RDV[i].reference);
                    printf("Date: %s\n", RDV[i].date);
                }
            }
            if (!found) {
                printf("Aucune r�servation trouv�e pour la date %s.\n", date);
            }
            break;
        }
        default:
            printf("Choix invalide !\n");
            break;
    }
}

void Statistiques() {
    int totalAge = 0;
    int compteurAge = 0;
    int ageCount[3] = {0, 0, 0}; // Tranches d'�ge : 0-18, 19-35, 36+

    for (int i = 0; i < compteur; i++) {
        totalAge += RDV[i].age;
        compteurAge++;

        if (RDV[i].age <= 18) {
            ageCount[0]++;
        } else if (RDV[i].age <= 35) {
            ageCount[1]++;
        } else {
            ageCount[2]++;
        }
    }

    printf("Statistiques:\n");
    if (compteurAge > 0) {
        printf("Age moyen: %.2f\n", (float)totalAge / compteurAge);
    } else {
        printf("Aucune reservation pour calculer l'age moyen.\n");
    }

    printf("Nombre de patients par tranche d'�ge :\n");
    printf("0-18 ans: %d\n", ageCount[0]);
    printf("19-35 ans: %d\n", ageCount[1]);
    printf("36+ ans: %d\n", ageCount[2]);
}

int main() {
    int choix, choix1;

    do {
        printf("\n     Menu Principal\n");
        printf("1- Ajouter une reservation\n");
        printf("2- Modifier ou Supprimer une reservation\n");
        printf("3- Afficher les details d'une reservation\n");
        printf("4- Afficher toutes les reservations\n");
        printf("5- Trier les reservations\n");
        printf("6- Rechercher une reservation\n");
        printf("7- Statistiques\n");
        printf("8- Quitter\n");
        printf("Taper votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter();
                break;
            case 2:
                printf("1 - Modifier \n2 - Supprimer \n3 - Retourner\n");
                printf("Taper votre choix : ");
                scanf("%d", &choix1);
                switch (choix1) {
                    case 1:
                        modifier();
                        break;
                    case 2:
                        supprimer();
                        break;
                    case 3:
                        printf("Retourner...\n");
                        break;
                    default:
                        printf("Choix invalide !\n");
                        break;
                }
                break;
            case 3:
                afficherDetail();
                break;
            case 4:
                afficher();
                break;
            case 5:
                trier();
                afficher();
                break;
            case 6:
                rechercher();
                break;
            case 7:
                Statistiques();
                break;
            case 8:
                printf("Au revoir!\n");
                choix = 0;
                break;
            default:
                printf("Choix invalide !\n");
                break;
        }
    } while (choix != 0);

    return 0;
}
