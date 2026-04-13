#include "geo.h"

#define PI 3.14159

double circle_area(double radius){
    return PI * radius * radius;
}
double rectangle_area(double width, double height){
    return width * height;
}