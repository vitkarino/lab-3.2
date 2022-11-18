#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double bisectionMethod(double a, double b, double c, double e, double f(double x), int steps, int method, int debugMode);
double secantMethod(double a, double b, double c, double e, double f(double x), int steps, int method, int debugMode);
double f(double x);

int main() {

    int method, debugMode, steps = 0;
    double a, b, e, c = 0, startTime, endTime, totalTime;

    printf("\nChoose a method: \n\t[1] - Bisection method \n\t[2] - Secant method");
    printf("\n\tOption: ");
    scanf_s("%d", &method);

    while (method != 2 && method != 1) {
        printf("\nInvalid option, try again.");
        printf("\n\tOption: ");
        scanf_s("%d", &method);
    }

    printf("\nChoose display mode: \n\t[1] - Default\n\t[2] - Show results on each iteration");
    printf("\n\tOption: ");
    scanf_s("%d", &debugMode);

    while (debugMode != 2 && debugMode != 1) {
        printf("\nInvalid option, try again.");
        printf("\n\tOption: ");
        scanf_s("%d", &debugMode);
    }

    if (debugMode == 2) {
        printf("\nEnter the number of iterations: ");
        scanf_s("%d", &steps);

        while (steps <= 0) {
            printf("\nInvalid option, try again.");
            printf("\nEnter the number of iterations: ");
            scanf_s("%d", &steps);
        }
    }

    printf("\nEnter a: ");
    scanf_s("%lf", &a);

    printf("\nEnter b: ");
    scanf_s("%lf", &b);

    while (a * b > 0) {
        printf("\nIncorrect values entered, try again.\n");

        printf("\n\tEnter a: ");
        scanf_s("%lf", &a);

        printf("\n\tEnter b: ");
        scanf_s("%lf", &b);
    }

    printf("\nEnter the accuracy (e): ");
    scanf_s("%lf", &e);

    startTime = clock();

    if (method == 1) {
    
       system("cls");

       printf("\nChosen method: Bisection\n");
       c = bisectionMethod(a, b, c, e, f, steps, method, debugMode);
       printf("\nRoot: %lf", c);
    } 
    else if (method == 2) {

        system("cls");
        
        printf("\nChosen method: Secant\n");
        c = secantMethod(a, b, c, e, f, steps, method, debugMode);
        printf("\nRoot: %lf", c);
    }

   
    
    endTime = clock();
    totalTime = (endTime - startTime) / 1000;

    printf("\nTime passed: %.2lf seconds\n", totalTime);

    return 0;
}


double bisectionMethod(double a, double b, double c, double e, double f(double x), int steps, int method, int debugMode) {

    int iter = 1, doNext = 1;

    if (debugMode == 2) {

        printf("----------------------------------------------------\n");
        printf("iter\ta\t\tb\t\tc\n");
        printf("----------------------------------------------------\n");

        do {

            c = (a + b) / 2;

            printf("\n%d.\t%lf\t%lf\t%lf\n", iter, a, b, c);

            if (f(a) * f(c) > 0) {
                a = c;
            }
            else if (f(a) * f(c) < 0) {
                b = c;
            }

            iter++;

            if (iter >= steps && doNext == 1) {

                printf("\nThe amount of iterations > chosen iteration steps.\nWhat to do next?\n");
                printf("\n\t[1] - Continue\n\t[2] - Continue until root were found\n\t[3] - Show current results and exit the program");
                printf("\n\tOption: ");
                scanf_s("%d", &doNext);

                if (doNext == 1) {
                    steps = iter + 5;
                }

                else if (doNext == 2) {
                    steps *= 0;
                }

                else if (doNext == 3) {
                    break;
                }

                while (doNext != 1 && doNext != 2 && doNext !=3) {
                    printf("\nInvalid option, try again.");
                    printf("\n\tOption: ");
                    scanf_s("%d", &doNext);
                }
            }

        } while (fabs(a - b) >= e);
    } 
    else {

        do {

            c = (a + b) / 2;

            if (f(a) * f(c) > 0) {
                a = c;
            }
            else if (f(a) * f(c) < 0) {
                b = c;
            }

            iter++;

        } while (fabs(a - b) >= e);
    }

    return c;
}

double secantMethod(double a, double b, double c, double e, double f(double x), int steps, int method, int debugMode) {

    int iter = 1, doNext = 1;

    if (debugMode == 2) {

        printf("----------------------------------------------------\n");
        printf("iter\ta\t\tb\t\tc\n");
        printf("----------------------------------------------------\n");
        
        do {

            c = (a * f(b) - b * f(a)) / (f(b) - f(a));

            a = b;
            b = c;

            printf("\n%d.\t%lf\t%lf\t%lf\n", iter, a, b, c);

            iter++;

            if (iter >= steps && doNext == 1) {

                printf("\nThe amount of iterations > chosen iteration steps.\nWhat to do next?\n");
                printf("\n\t[1] - Continue\n\t[2] - Continue until root were found\n\t[3] - Show current results and exit the program");
                printf("\n\tOption: ");
                scanf_s("%d", &doNext);

                if (doNext == 1) {
                    steps = iter + 5;
                }

                else if (doNext == 2) {
                    steps *= 0;
                }

                else if (doNext == 3) {
                    break;
                }

                while (doNext != 1 && doNext != 2 && doNext != 3) {
                    printf("\nInvalid option, try again.");
                    printf("\n\tOption: ");
                    scanf_s("%d", &doNext);
                }
            }

        } while (fabs(f(c)) > e);
    }

    else {
        do {

            c = (a * f(b) - b * f(a)) / (f(b) - f(a));

            a = b;
            b = c;

            iter++;

        } while (fabs(f(c)) > e);  
    }
      
        return c;
}


double f(double x) {
    return 0.25 * pow(x - 25, 2) + ((pow(x + 25, 3)) / 100) + 1;
}