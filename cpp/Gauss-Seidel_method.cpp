#include <bits/stdc++.h>
using namespace std;

bool makeDiagonallyDominant(vector<vector<double>> &coeff, int n) {
    for (int i = 0; i < n; i++) {
        int maxRow = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(coeff[j][i]) > fabs(coeff[maxRow][i])) {
                maxRow = j;
            }
        }
        if (maxRow != i) {
            swap(coeff[i], coeff[maxRow]);
        }
        double sum = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) sum += fabs(coeff[i][j]);
        }
        if (fabs(coeff[i][i]) < sum) return false;
    }
    return true;
}

void gaussSeidelIteration(vector<vector<double>> &coeff, vector<double> &x, int n, double e) {
    vector<double> error(n);
    int step = 1;
    bool flag;

    cout << setprecision(6) << fixed;
    cout << endl << "Count\t";
    for (int i = 0; i < n; i++) cout << "x" << i + 1 << "\t\t";
    cout << endl;

    do {
        flag = true;
        for (int i = 0; i < n; i++) {
            double old_xi = x[i];
            x[i] = coeff[i][n];
            for (int j = 0; j < n; j++) {
                if (i != j) x[i] -= coeff[i][j] * x[j];
            }
            x[i] /= coeff[i][i];
            error[i] = fabs(x[i] - old_xi);
            if (error[i] > e) flag = false;
        }

        cout << step << "\t";
        for (int i = 0; i < n; i++) {
            cout << x[i] << "\t";
        }
        cout << endl;
        step++;
    } while (!flag);

    cout << endl << "Solution: ";
    for (int i = 0; i < n; i++) cout << "x" << i + 1 << " = " << x[i] << ", ";
}

int main() {
    int n;
    double e=1e-4;

    vector<vector<double>> coeff;

    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<double> row;
        double value;
        while (iss >> value) {
            row.push_back(value);
        }
        if (!row.empty()) {
            coeff.push_back(row);
        }
    }
    n = coeff.size();
    vector<double> x(n, 0);


    if (makeDiagonallyDominant(coeff, n)) {
        gaussSeidelIteration(coeff, x, n, e);
    } else {
        cout << "Failed to make diagoanlly dominant" << endl;
    }
    return 0;
}

