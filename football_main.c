#include <stdio.h>      // include standard input/output header
#include "football.h"   // include custom header for football functions

int main() {
    //variable to store user input score
    int score;  
    //loop until the user enters 0 or 1
    while (1) {
        printf("Enter 0 or 1 to STOP\n");                 
        printf("Enter the NFL score: ");                 
        scanf("%d", &score);                             
        
        //exit the loop if score is 0 or 1
        if (score <= 1) {                                
            break;                                       
        }

        //call function to count possible combinations
        int total_combinations = count_combinations(score);  

        //if no combos found
        if (total_combinations == 0) {                   
            printf("No combinations possible for score %d\n", score);
        } else {
            //print all combos
            print_combinations(score);                   
        }
        //newline for spacing
        printf("\n ");                                   
    }

    return 0;  // return success
}
