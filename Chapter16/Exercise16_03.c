/*
 * Exercise16_03.c
 *
 *  Created on: Aug 09, 2021
 *      Author: andrew
 */
#include "Exercise16_01.h"
#include "Exercise16_03.h"
#include <math.h>
#define TO_RADIAN(X) (((4 * atan(1)) * (X)) / 180.0)

int main(void)
{
    Polar coordinates;
    Cartesian result;

    printf("Enter magnitude and angle in degrees (q to quit): ");
    while (scanf("%lf %lf", &coordinates.magnitude, &coordinates.angle) == 2)
    {
        CLEARINPUT;
        result = cartesianFromPolar(coordinates);
        printf("Polar coordinates: %g %g\n", coordinates.magnitude, coordinates.angle);
        printf("Rectangular coordinates: %g %g\n", result.x, result.y);
        printf("Enter magnitude and angle in degrees (q to quit): ");
    }
    puts("Bye.");

    return 0;
}

Cartesian cartesianFromPolar(Polar coordinates)
{
    Cartesian result;
    double angle_in_radian = TO_RADIAN(coordinates.angle);
    printf("Angle in radian is %g\n", angle_in_radian);
    result.x = coordinates.magnitude * cos(angle_in_radian);
    result.y = coordinates.magnitude * sin(angle_in_radian);
    return result;
}
