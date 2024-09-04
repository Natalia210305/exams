#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    putchar('D'); //we print out first answer which is D
    putchar ('\n');
    fflush(stdout);
    char opponents_answer; //variable that has our opponents answer of every round
    int rwpC = 500, rcount = 0; //rcount counts how many rounds we've had and rwpC calculates the round that we print C
    while ((opponents_answer=getchar())!=EOF) { //we keep reading our opponents answer until we get EOF
        //we check if our opponents answer is either character C or D, every other character isn't acceptable as a right answer so we skip it
        if (opponents_answer == 'D' || opponents_answer == 'C') {
            rcount++; //we increase rcount cause the round counts
            putchar(opponents_answer); //we print our opponents answer
            putchar('\n');
            fflush(stdout);
            //our strategy is that every 1000 we print only one C at rounds 500, 1500, 2500... and all the other answers are D
            if (rcount != rwpC) { //if rcount isn't equal to rwpC then we simply answer with a D
                putchar('D');
                fflush(stdout);
            }
            else { //if they're equal then we answer with a C and we increase rwpC by 1000
                rwpC+=1000;
                putchar('C');
                fflush(stdout);
            }
            putchar ('\n');\
            fflush(stdout);
        }
    }
    return 0;
}