#include <stdio.h>
#include "football.h"

// function to count the number of valid scoring combinations for a given score
int count_combinations(int points) {
    int td_2pt, td_fg, td, fg, safety;
    int count = 0;  // initialize combination counter

    // try every possible number of 2-point TDs
    for (td_2pt = 0; td_2pt * 8 <= points; td_2pt++) {
        // try every possible number of 1-point TDs (TD + FG)
        for (td_fg = 0; td_fg * 7 + td_2pt * 8 <= points; td_fg++) {
            // try every possible number of plain TDs (6 pts)
            for (td = 0; td * 6 + td_fg * 7 + td_2pt * 8 <= points; td++) {
                // try every possible number of field goals (3 pts)
                for (fg = 0; fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 <= points; fg++) {
                    // try every possible number of safeties (2 pts)
                    for (safety = 0; safety * 2 + fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 <= points; safety++) {
                        // calculate total score from current combination
                        int total = td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2;

                        // if total equals desired score, count this combination
                        if (total == points) {
                            count++;
                        }
                    }
                }
            }
        }
    }

    return count;  // return total number of combinations
}

// function to print all valid scoring combinations for a given score
void print_combinations(int points) {
    int td_2pt, td_fg, td, fg, safety;

    // print header
    printf("Possible combinations of scoring plays if a team’s score is %d:\n\n", points);

    // same logic as count_combinations, but print each valid combo
    for (td_2pt = 0; td_2pt * 8 <= points; td_2pt++) {
        for (td_fg = 0; td_fg * 7 + td_2pt * 8 <= points; td_fg++) {
            for (td = 0; td * 6 + td_fg * 7 + td_2pt * 8 <= points; td++) {
                for (fg = 0; fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 <= points; fg++) {
                    for (safety = 0; safety * 2 + fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 <= points; safety++) {
                        int total = td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2;

                        if (total == points) {
                            // print formatted combination
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td_2pt, td_fg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}
