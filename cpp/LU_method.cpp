#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    double A[4][4], b[4];
    cout << "Enter the elements of matrix A (4x4): " << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Enter the elements of vector b (4x1): " << endl;
    for (int i = 0; i < 4; ++i) {
        cin >> b[i];
    }
    double L[4][4] = {0}, U[4][4] = {0};
    U[0][0] = A[0][0];
    U[0][1] = A[0][1];
    U[0][2] = A[0][2];
    U[0][3] = A[0][3];
    L[1][0] = A[1][0] / U[0][0];
    U[1][1] = A[1][1] - L[1][0] * U[0][1];
    U[1][2] = A[1][2] - L[1][0] * U[0][2];
    U[1][3] = A[1][3] - L[1][0] * U[0][3];
    L[2][0] = A[2][0] / U[0][0];
    L[2][1] = (A[2][1] - L[2][0] * U[0][1]) / U[1][1];
    U[2][2] = A[2][2] - L[2][0] * U[0][2] - L[2][1] * U[1][2];
    U[2][3] = A[2][3] - L[2][0] * U[0][3] - L[2][1] * U[1][3];
    L[3][0] = A[3][0] / U[0][0];
    L[3][1] = (A[3][1] - L[3][0] * U[0][1]) / U[1][1];
    L[3][2] = (A[3][2] - L[3][0] * U[0][2] - L[3][1] * U[1][2]) / U[2][2];
    U[3][3] = A[3][3] - L[3][0] * U[0][3] - L[3][1] * U[1][3] - L[3][2] * U[2][3];


    L[0][0] = 1;
    L[1][1] = 1;
    L[2][2] = 1;
    L[3][3] = 1;
    cout << "\nL matrix:" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << setw(10) << setprecision(4) << L[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nU matrix:" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << setw(10) << setprecision(4) << U[i][j] << " ";
        }
        cout << endl;
    }
    double y[4];
    y[0] = b[0] / L[0][0];
    y[1] = (b[1] - L[1][0] * y[0]) / L[1][1];
    y[2] = (b[2] - L[2][0] * y[0] - L[2][1] * y[1]) / L[2][2];
    y[3] = (b[3] - L[3][0] * y[0] - L[3][1] * y[1] - L[3][2] * y[2]) / L[3][3];
    double x[4];
    x[3] = y[3] / U[3][3];
    x[2] = (y[2] - U[2][3] * x[3]) / U[2][2];
    x[1] = (y[1] - U[1][2] * x[2] - U[1][3] * x[3]) / U[1][1];
    x[0] = (y[0] - U[0][1] * x[1] - U[0][2] * x[2] - U[0][3] * x[3]) / U[0][0];


    cout << "\nSolution vector x:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << setw(10) << setprecision(4) << x[i] << " ";
    }
    cout << endl;

    return 0;
}
