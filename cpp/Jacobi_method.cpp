#include<bits/stdc++.h>
using namespace std;

bool makeDiagonallyDominant(vector<vector<float>> &coeff, int n)
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

        float sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i) sum += fabs(coeff[i][j]);
        }

        if (fabs(coeff[i][i]) < sum) return false;
    }
    return true;
}

void jacobiIteration(vector<vector<float>> &coeff, vector<float> &x0, int n, float e)
{
    vector<float> x1(n), error(n);
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

int main()
{
    int n;
    float e;
    cout << "Enter number of variables: ";
    cin >> n;

    vector<vector<float>> coeff(n, vector<float>(n + 1));
    vector<float> x0(n, 0);

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

