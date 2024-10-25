#include <boost/python.hpp>

double add(double a, double b) {
    return a + b;
}

BOOST_PYTHON_MODULE(my_module) {
    boost::python::def("add", add);
}
