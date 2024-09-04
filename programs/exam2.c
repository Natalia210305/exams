#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//we define the defines of the program
#define TOLERANCE 1e-6
#define MAX_ITERATIONS 1000

//we determine the polynomial
double f(double x, double a_0, double a_1, double a_2, double a_3, double a_4, double a_5) {
    return a_5*pow(x,5) + a_4*pow(x,4) + a_3*pow(x,3) + a_2*pow(x,2) + a_1*x + a_0;
}

//we determine the product of the polynomial
double df(double x, double a_1, double a_2, double a_3, double a_4, double a_5) {
        return  5 * a_5*pow(x,4) + 4 * a_4*pow(x,3) + 3 * a_3*pow(x,2) + 2 * a_2*x + a_1;
}

double newton(double x0, double a_0, double a_1, double a_2, double a_3, double a_4, double a_5 ) {
        double x = x0 , x1=1 , x2=2;
        int i=0;
        //we check how many iterations the program does 
        while (i <= MAX_ITERATIONS) {
                if (fabs (x2-x1)<TOLERANCE) {
                        return x;
                }
                //we check the case where the algorithm deviates
                else if (fabs(df(x,a_1,a_2,a_3,a_4,a_5))==0){
                         printf("nan\n");
                        return 0;
                }
                x = x - (f(x,a_0,a_1,a_2,a_3,a_4,a_5) / df(x,a_1,a_2,a_3,a_4,a_5));
                x1=x2;
                x2=x;
                i++;
        }
        //we check if the program did more than 1000 iterations
        if (i>MAX_ITERATIONS) {
                printf("incomplete\n");
        }
        return 0;
}


int main(int argc,char ** argv) {
    if (argc !=8) {
        return 1;
    }
    //the user enters the coefficients of the polynomial
    double a_0=atof(argv[1]);
    double a_1=atof(argv[2]);
    double a_2=atof(argv[3]);
    double a_3=atof(argv[4]);
    double a_4=atof(argv[5]);
    double a_5=atof(argv[6]);
    double x_0=atof(argv[7]);
    double root = newton(x_0,a_0,a_1,a_2,a_3,a_4,a_5);
    //if the root is different from 0 we print the root
    if (root != 0.0) {
        printf("%.2f\n", root);
    }
    return 0;
}



