#include <cmath>
#include "sigmoid.h"

double Sigmoid ::forward(double input)
{
    // TODO
    double e_x = exp(input);

    return (e_x / (1.0 + e_x)); // (e^x / (1+e^x))
}

double Sigmoid ::backprop()
{
    // TODO

    return 0;
}