#include <math.h>

double doubleFactorial(int initial_value)
{
    double res = 1;
    for (int k = initial_value; k > 0; k -= 2) {
        res *= k;
    }
    return res;
}


double getT(double x)
{
    double s1 = 0;
    double s2 = 0;

    for(int k = 0; k <= 10; k++)
    {
        s1 += pow(x, 2*k+1) / doubleFactorial(2*k+1);
        s2 += pow(x, 2*k) / doubleFactorial(2*k);
    }
    return s1 / s2;
}


double getResult(int y)
{
    return (7 * getT(0.25) + 2 * getT(1 + y)) / (6 - getT(pow(y, 2) - 1));
}
