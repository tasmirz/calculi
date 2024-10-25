#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

void gaussJordan(vector<vector<double>>& matrix) {
    int n = matrix.size();
    const double EPS = 1e-9; // Precision tolerance

    for (int i = 0; i < n; ++i) {
        // Pivoting: find the maximum element in the current column
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (fabs(matrix[k][i]) > fabs(matrix[maxRow][i])) {
                maxRow = k;
            }
        }
        // Swap rows if needed
        if (fabs(matrix[maxRow][i]) < EPS) {
            cout << "No unique solution exists." << endl;
            return;
        }
        swap(matrix[i], matrix[maxRow]);

        // Make the diagonal element 1
        double diagElement = matrix[i][i];
        for (int j = 0; j <= n; ++j) {
            matrix[i][j] /= diagElement;
        }

        // Make the other elements in the current column 0
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j <= n; ++j) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
}

void printMatrix(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;

    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n + 1));

    cout << "Enter the augmented matrix (coefficients and constants):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cin >> matrix[i][j];
        }
    }

    gaussJordan(matrix);

    cout << "\nThe solution is:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << matrix[i][n] << endl;
    }

    return 0;
}

