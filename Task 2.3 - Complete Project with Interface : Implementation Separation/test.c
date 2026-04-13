#include <stdio.h>
#include "geo.h"

int main(void){
    int selection = 0;

    printf("Select a Operation: \n");
    printf("1. Circle Area\n");
    printf("2. Rectangle Area\n");
    printf("Enter your selection: ");
    scanf("%d", &selection);

    if (selection == 1){
        double radius;
        printf("Enter the radius of the circle: ");
        scanf("%lf", &radius);
        double area = circle_area(radius);
        printf("The area of the circle is: %.2lf\n", area);
    } else if (selection == 2){
        double width, height;
        printf("Enter the width of the rectangle: ");
        scanf("%lf", &width);
        printf("Enter the height of the rectangle: ");
        scanf("%lf", &height);
        double area = rectangle_area(width, height);
        printf("The area of the rectangle is: %.2lf\n", area);
    } else {
        printf("Invalid selection. Please select either 1 or 2.\n");
    }

    return 0;
}