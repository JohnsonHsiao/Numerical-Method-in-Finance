#include<iostream>
using namespace std;

const int MAX_SIZE = 50;

void print(double arr[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void gauss_jordan(double a[MAX_SIZE][MAX_SIZE], int n, double b[MAX_SIZE][MAX_SIZE], int m) {
    double temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                temp = a[j][i] / a[i][i];
                for (int k = 0; k < n; k++) {
                    a[j][k] -= temp * a[i][k];
                    b[j][k] -= temp * b[i][k];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        temp = a[i][i];
        for (int j = 0; j < n; j++) {
            a[i][j] /= temp;
            b[i][j] /= temp;
        }
    }
}

int main() {
    int n;
    double a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE];
    cout << "Enter the size of matrix: ";
    cin >> n;
    cout << "Enter the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (i == j) {
                b[i][j] = 1;
            }
            else {
                b[i][j] = 0;
            }
        }
    }
    gauss_jordan(a, n, b, n);
    cout << "Inverse matrix:" << endl;
    print(b, n);
    return 0;
}
