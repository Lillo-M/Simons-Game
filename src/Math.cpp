#include "../include/Math/Math.h"


float absolute(float value)
{
    if(value >= 0)
        return value;
    else
        return -value;
}

int absolute(int value)
{
    if(value >= 0)
        return value;
    else
        return -value;
}
double absolute(double value)
{
    if(value >= 0)
        return value;
    else
        return -value;
}