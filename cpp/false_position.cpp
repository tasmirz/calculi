#include <iostream>
#include <cmath>
#include<vector>
#include "library.cxx"
using namespace std;
/*
double f(double x)
{
    return x * x * x - 4 * x - 9;
}
*/
void bisection(vector<double> A,double a, double b, double tolerance)
{

    if (f(A,a) * f(A,b) >= 0)
    {
        //cout << "Incorrect interval. The function must have opposite signs at a and b." << endl;
        return;
    }

    double c;
    while ((b - a) >= tolerance)
    {
         c = (a*f(A,b)-b*f(A,a))/(f(A,b)-f(A,a));

        if (fabs(f(A,c)) < tolerance)
        {
            cout << c <<" ";
            return;
        }

        if (f(A,c) * f(A,a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
}

int main()
{
    vector<double> coff;
    double t;
     while (cin>>t) {
        coff.push_back(t);
    }
    pair<int,int>p= find_bounds(coff) ;
    double tolerance = 0.00001;
    double a = p.first;
    double b = p.second;
    double magic_number = 0.1; 

    while (a < b) {
        if (f(coff, a) == 0.0) {
            cout<<a<<" ";
            a += magic_number;
            continue;
        }
        if (f(coff, a) * f(coff, a + magic_number) < 0) {
            bisection(coff, a, a + magic_number, tolerance);
        }
        a += magic_number;
    }

    return 0;
}


