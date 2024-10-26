#include <vector>
double f(std::vector<double> A,double x) {
    double sum=*A.end();
    for (int i=A.size()-2;i>=0;i--) {
        sum+=(sum*x+A[i]);
    }
    return sum;
}
double fp (std::vector<double> A,double x,double h=1e-6) {
    return (f(A,x+h)-f(A,x))/h;
}