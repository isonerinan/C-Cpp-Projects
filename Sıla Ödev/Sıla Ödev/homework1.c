#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// SEREN SILA UYSAL 040210011 EEF110E HOMEWORK 

int main() {
    int choice, a, b, c, r, h;
    float surface_area, volume;

    // Display menu choices and ask for a choice
    printf("SHAPES MENU\n  1.CUBOID\n  2.CYLINDER\n  3.CONE\n  4.SPHERE\n  0.EXIT\n\nEnter choice: ");
    scanf("%d", &choice);

    // Control if the choice is valid  
    if (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4) {
        printf("Error: Invalid choice");
        exit(0);
    }

    if (choice == 0) {
        exit(0);
    }
    if (choice == 1) {
        //cuboid
        printf("\nEnter a, b and c: ");
        scanf("%d %d %d", &a, &b, &c);

        surface_area = 2 * (a * b + a * c + b * c);
        volume = a * b * c;

        printf("CUBOID\nSURFACE AREA= %f \nVOLUME= %f", surface_area, volume);
    }

    if (choice == 2) {
        //cylinder
        printf("\nEnter r and h: ");
        scanf("%d %d", &r, &h);

        surface_area = 2 * r * M_PI * (r + h);
        volume = pow(r, 2) * M_PI * h;

        printf("CYLINDER\nSURFACE AREA= %f \nVOLUME= %f", surface_area, volume);
    }

    if (choice == 3) {
        //cone
        printf("\nEnter r and h: ");
        scanf("%d %d", &r, &h);

        surface_area = M_PI * r * (r + sqrt(pow(r, 2) + pow(h, 2)));
        volume = pow(r, 2) * M_PI * h;

        printf("CONE\nSURFACE AREA= %f \nVOLUME= %f", surface_area, volume);
    }

    if (choice == 4) {
        //sphere
        printf("\nEnter r: ");
        scanf("%d", &r);

        surface_area = 4 * M_PI * pow(r, 2);
        volume = pow(r, 3) * M_PI * 4 / 3;

        printf("SPHERE\nSURFACE AREA= %f \nVOLUME= %f", surface_area, volume);
    }
}
