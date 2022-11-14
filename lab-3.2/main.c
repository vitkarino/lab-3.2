#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double bisectionMethod(double a, double b, double c, double e, int steps, int method, int debugMode);
double secantMethod(double a, double b, double c, double e, int steps, int method, int debugMode);
double f(double x);

int main() {

    int method, debugMode, steps = 0;
    double a = 1, b = 1, c = 1, e = 1;
    float startTime = 0, endTime = 0, totalTime = 0;

    printf("\nChoose a method: \n\t[1] - Bisection method \n\t[2] - Secant method");
    printf("\n\tOption: ");

    while (scanf_s("%d", &method) && method > 2 || method < 1) {
        printf("\nInvalid option, try again.");
        printf("\n\tOption: ");
    };

    printf("\nChoose a debug mode: \n\t[1] - Standard mode\n\t[2] - Debug with parameters");
    printf("\n\tOption: ");

    while (scanf_s("%d", &debugMode) && debugMode > 2 || debugMode < 1) {
        printf("\nInvalid option, try again.");
        printf("\n\tOption: ");
    }

    if (debugMode == 2) {
        printf("\nEnter the number of iterations: ");
        scanf_s("%d", &steps);
    }

    printf("\nEnter a: ");
    scanf_s("%lf", &a);

    printf("\nEnter b: ");
    scanf_s("%lf", &b);

    printf("\nEnter the accuracy (e): ");
    scanf_s("%lf", &e);

    if (method == 1) {

        if (f(a) * f(b) <= 0) {
            
            startTime = clock();

            system("cls");
            
            printf("\nChosen method: Bisection\n");
            bisectionMethod(a, b, c, e, steps, method, debugMode);

            endTime = clock();
        }
        else {
            printf("\nThe root doesn't exist in the given interval");
        }
    }

    else if (method == 2) {

        startTime = clock();

        system("cls");

        printf("\nChosen method: Secant\n");
        secantMethod(a, b, c, e, steps, method, debugMode);

        endTime = clock();
    }
    
    totalTime = (endTime - startTime) / CLOCKS_PER_SEC;
    printf("\nTime passed: %lf seconds", totalTime);
}


double bisectionMethod(double a, double b, double c, double e, int steps, int method, int debugMode) {

    int iter = 1, doNext = 0;

    printf("----------------------------------------------------\n");
    printf("iter\ta\t\tb\t\tc\n");
    printf("----------------------------------------------------\n");

        do {
            
            c = (a + b) / 2;

            printf("\n%d.\t%lf\t%lf\t%lf\n", iter, a, b, c);

            iter++;
            
            if (f(a) * f(c) > 0) {
                a = c;
            }
            else if (f(a) * f(c) < 0) {
                b = c;
            }

            if (debugMode == 2 && iter >= steps) {
                printf("\nThe amount of iterations > chosen iteration steps.\nWhat to do next?\n");
                printf("\n\t[1] - Continue\n\t[2] - Continue until root were found\n\t[3] - Show results and exit the program");
                printf("\n\tOption: ");
                scanf_s("%d", &doNext);
            }

            switch (doNext) {
            case 2:
                debugMode = 0;
                continue;
            case 3:
                printf("\nRoot: %lf\n", c);
                return;
            }

        } while (fabs(a - b) > e && iter <= steps);

        printf("\nRoot: %lf", c);

        return c;
}

double secantMethod(double a, double b, double c, double e, int steps, int method, int debugMode) {

    int iter = 1, doNext = 0;

    printf("----------------------------------------------------\n");
    printf("iter\ta\t\tb\t\tc\n");
    printf("----------------------------------------------------\n");

        do {

            c = (a * f(b) - b * f(a)) / (f(b) - f(a));

            a = b;
            b = c;
           
            printf("\n%d.\t%lf\t%lf\t%lf\n", iter, a, b, c);

            iter++;

            if (debugMode == 2 && iter >= steps) {
                printf("\nThe amount of iterations > chosen iteration steps.\nWhat to do next?\n");
                printf("\n\t[1] - Continue\n\t[2] - Continue until root were found\n\t[3] - Show results and exit the program");
                printf("\n\tOption: ");
                scanf_s("%d", &doNext);
            }

            switch (doNext) {
            case 2:
                debugMode = 0;
                continue;
            case 3:
                printf("\nRoot: %lf\n", c);
                return;
            }
            
        } while (fabs(f(c)) > e && iter <= steps);
        
        printf("\nRoot: %lf", c);
        
        return c;
}


double f(double x) {
   return 0.25 * pow(x - 25, 2) + (pow(x + 25, 3) / 100) + 1;
}