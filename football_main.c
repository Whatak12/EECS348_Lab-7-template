#include <stdio.h>      // include standard input/output header
#include "football.h"   // include custom header for football functions

int main() {
    int score;  // variable to store user input score

    // loop until the user enters 0 or 1
    while (1) {
        printf("Enter 0 or 1 to STOP\n");                 // show stop message
        printf("Enter the NFL score: ");                 // ask for score input
        scanf("%d", &score);                             // read score from user

        if (score <= 1) {                                // if score is 0 or 1
            break;                                       // exit the loop
        }

        int total_combinations = count_combinations(score);  // call function to count possible combinations

        if (total_combinations == 0) {                   // if no combos found
            printf("No combinations possible for score %d\n", score);
        } else {
            print_combinations(score);                   // print all combinations
        }

        printf("\n ");                                    // print newline for spacing
    }

    return 0;  // return success
}
