#include<bits/stdc++.h>
using namespace std;
#include "library.cxx"
vector<double> roots;
double f_(const vector<double>& A, double x) {
    double res = f(A, x);
    for (double root : roots) {
        res /= (x - root);
    }
    return res;
}
void secant(const vector<double> coefficients,int l)
{
    if (l==0)  return;
    double x2, x3;
    pair<int,int> p = find_bounds(coefficients);
    static double x1 = p.first;
    x2 = p.second;
    for (int i = 0; i < 100; i++)
    {
        x3 = x2 - (f_(coefficients, x2) * (x2 - x1)) / (f_(coefficients, x2) - f_(coefficients, x1));
        if (fabs(f_(coefficients, x3)) < 0.00001)
        {
            roots.push_back(x3);
            cout << x3 << " ";
            secant(coefficients,l-1);
        }
        else
        {
            x1 = x2;
            x2 = x3;
        }
    }
}

int main()
{
    vector<double> coefficients;
    double t;
    while (cin >> t) {
        coefficients.push_back(t);
    }
    secant(coefficients,coefficients.size()-1);
}
