#include <stdio.h>
#include "football.h"

int count_combinations(int points) {
    int td_2pt, td_fg, td, fg, safety;
    int count = 0;

    for (td_2pt = 0; td_2pt * 8 <= points; td_2pt++) {
        for (td_fg = 0; td_fg * 7 + td_2pt * 8 <= points; td_fg++) {
            for (td = 0; td * 6 + td_fg * 7 + td_2pt * 8 <= points; td++) {
                for (fg = 0; fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 <= points; fg++) {
                    for (safety = 0; safety * 2 + fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 <= points; safety++) {
                        int total = td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2;
                        if (total == points) {
                            count++;
                        }
                    }
                }
            }
        }
    }

    return count;
}

void print_combinations(int points) {
    int td_2pt, td_fg, td, fg, safety;

    printf("Possible combinations of scoring plays if a team’s score is %d:\n\n", points);

    for (td_2pt = 0; td_2pt * 8 <= points; td_2pt++) {
        for (td_fg = 0; td_fg * 7 + td_2pt * 8 <= points; td_fg++) {
            for (td = 0; td * 6 + td_fg * 7 + td_2pt * 8 <= points; td++) {
                for (fg = 0; fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 <= points; fg++) {
                    for (safety = 0; safety * 2 + fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 <= points; safety++) {
                        int total = td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2;
                        if (total == points) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td_2pt, td_fg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}
