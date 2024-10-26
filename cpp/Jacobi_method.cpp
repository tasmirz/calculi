#include <vector>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

bool makeDiagonallyDominant(std::vector<std::vector<double>> &coeff, int n)
{
    for (int i = 0; i < n; i++)
    {
        int maxRow = i;
        for (int j = i + 1; j < n; j++)
        {
            if (fabs(coeff[j][i]) > fabs(coeff[maxRow][i]))
            {
                maxRow = j;
            }
        }

        if (maxRow != i)
        {
            swap(coeff[i], coeff[maxRow]);
        }

        double sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i) sum += fabs(coeff[i][j]);
        }

        if (fabs(coeff[i][i]) < sum) return false;
    }
    return true;
}

void jacobiIteration(std::vector<std::vector<double>> &coeff, std::vector<double> &x0, int n, double e)
{
    std::vector<double> x1(n), error(n);
    int step = 1;
    bool flag;

    cout << setprecision(6) << fixed;
    cout << endl << "Count\t";
    for (int i = 0; i < n; i++) cout << "x" << i + 1 << "\t\t";
    cout << endl;

    do
    {
        flag = true;
        for (int i = 0; i < n; i++)
        {
            x1[i] = coeff[i][n];
            for (int j = 0; j < n; j++)
            {
                if (i != j) x1[i] -= coeff[i][j] * x0[j];
            }
            x1[i] /= coeff[i][i];
        }

        cout << step << "\t";
        for (int i = 0; i < n; i++)
        {
            cout << x1[i] << "\t";
            error[i] = fabs(x1[i] - x0[i]);
            if (error[i] > e) flag = false;
            x0[i] = x1[i];
        }
        cout << endl;
        step++;
    }
    while (!flag);

    cout << endl << "Solution: ";
    for (int i = 0; i < n; i++) cout << "x" << i + 1 << " = " << x1[i] << ", ";
}

//BOOST_PYTHON_MODULE(jacobi_method)
//{
//    def("jacobiIteration", jacobiIteration);
//}

int main()
{
    int n;
    double e;
    cout << "Enter number of variables: ";
    cin >> n;

    std::vector<std::vector<double>> coeff(n, std::vector<double>(n + 1));
    std::vector<double> x0(n, 0);

    cout << "Enter coefficients of equations:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> coeff[i][j];
        }
    }

    cout << "Enter tolerable error: ";
    cin >> e;

    if (makeDiagonallyDominant(coeff, n))
    {
        jacobiIteration(coeff, x0, n, e);
    }
    else
    {
        cout << "The system could not be made diagonally dominant and may not converge using the Jacobi method.";
    }
    return 0;
}
