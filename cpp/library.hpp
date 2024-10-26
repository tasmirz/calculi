#ifndef Library
#include <vector>
double f(std::vector<double> A,double x);
double fp (std::vector<double> A,double x,double h=1e-6);  
std::pair<double, double> find_bounds(const std::vector<double>& coefficients);
#define Library    
#endif