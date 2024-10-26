#include<bits/stdc++.h>
#include "library.cxx"
using namespace std;
/*void secant()
{
    {
    double x1,x2,x3;
    cout<< " give x1, x2\n" ;
    cin>>x1>>x2;
    for(int i=0;i<10;i++)
    {


    x3=x2-(f_(x2)*(x2-x1))/(f_(x2)-f_(x1));
    if_(f_(x3)==0)
    {
        cout<< "in secant method ans is = "<< x3<<endl;
        return ;
    }
    else
{
    x1=x2;
    x2=x3;
}
    }
cout<<"in secant method ans is = "<< x3<<endl;

    }
}*/
vector <double> roots;
double f_ (vector<double>A,double x) {
    double res= f(A,x);
    for (int i=0;i<roots.size();i++) {
        res/=x-roots[i];
    }
    return res;
} 
double fp_ (vector<double>A,double x,double h=0.00001) {
     return (f_(A,x+h)-f_(A,x))/h;
}
void newton_raphson(const vector<double>& coefficients, double tolerance,int l)
{   
    if (l==0) {
        return;
    }
    pair<double, double> bounds = find_bounds(coefficients);
    static double x0 = bounds.first;
    double x1;
    for (int i = 0; i < 10; i++) {
        x1 = x0 - (f_(coefficients, x0) / fp_(coefficients, x0));
        if (fabs(f_(coefficients, x1)) < tolerance) {
            cout << x1 << " ";
            roots.push_back(x1);
            return newton_raphson(coefficients, tolerance,l-1);
        }
        x0 = x1;
    }

}

int main()
{
    vector<double> coefficients;
    double t;
    while (cin >> t) {
        coefficients.push_back(t);
    }
    double tolerance = 0.00001;
    newton_raphson(coefficients, tolerance,coefficients.size()-1);
}

