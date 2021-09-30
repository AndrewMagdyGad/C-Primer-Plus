#ifndef EXERCISE16_03_H_
#define EXERCISE16_03_H_

typedef struct polar
{
    double magnitude;
    double angle;
} Polar;

typedef struct cartesian
{
    double x;
    double y;
} Cartesian;

Cartesian cartesianFromPolar(Polar coordinates);

#endif