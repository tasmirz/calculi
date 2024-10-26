#include <vector>
#include <algorithm>
#include<cmath>
double f(std::vector<double> A,double x) {
    double sum=A[0];
    for (int i=1;i<A.size();i++) {
        sum=(sum*x+A[i]);
    }
    return sum;
}
double fp (std::vector<double> A,double x,double h=1e-6) {
    return (f(A,x+h)-f(A,x))/h;
}
std::pair<double, double> find_bounds(const std::vector<double>& coefficients) {
    double a_n = coefficients[0];
    double M = 1;
    for (size_t i = 1; i < coefficients.size(); ++i) {
        M = std::max(M, ceil(std::abs(coefficients[i] / a_n)));
    }
    return std::make_pair(-M + 1, M + 1);
}