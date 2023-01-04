#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

/* Quizz de calcul mental */

bool quizz();

int main() {

    quizz();
    return 0;
}

bool quizz() {

    srand(time (NULL));

    int nbTour = 0;
    int score = 0;

    scanf("%d", &nbTour);

    int i = 0;
    while (i < nbTour) {

        int reponseJoueur, reponse;
        int numberGenA = (rand() % (SHRT_MAX / 10));
        int numberGenB = (rand() % (SHRT_MAX / 12));

        printf("%d + %d = ", numberGenA, numberGenB);
        scanf("%d", &reponseJoueur);

        reponse = numberGenA + numberGenB;

        if (reponseJoueur == reponse) {

            score++;

            if (score == nbTour)
                printf("%d", score); /* YOLO PATE A L'EAU */
            continue;
            } else {
                printf("Dommage !");
                break;
            }
        i++;
    }
}
