#include <iostream>
#include <cmath>
#include<vector>
#include "library.hpp"
using namespace std;
/*
double f(double x)
{
    return x * x * x - 4 * x - 9;
}
*/
double bisection(vector<double> A,double a, double b, double tolerance)
{

    if (f(A,a) * f(A,b) >= 0)
    {
        //cout << "Incorrect interval. The function must have opposite signs at a and b." << endl;
        return;
    }

    double c;
    while ((b - a) >= tolerance)
    {
         c = (a*f(b)-b*f(a))/(f(b)-f(a));

        if (fabs(f(c)) < tolerance)
        {
            cout << "The root is approximately: " << c << endl;
            return;
        }

        if (f(c) * f(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    c = (a*f(b)-b*f(a))/(f(b)-f(a));
    cout << "The root is approximately: " << c << endl;
}

int main()
{
    double a, b, tolerance = 0.00001;

    cout << "Enter the values for a and b: ";
    cin >> a >> b;

    bisection(a, b, tolerance);

    return 0;
}


