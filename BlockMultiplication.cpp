#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void multiplyMatricesBlocked(const vector<vector<double>>& A, const vector<vector<double>>& B, vector<vector<double>>& C, int blockSize) {
    int n = A.size();
    for (int ii = 0; ii < n; ii += blockSize) {
        for (int jj = 0; jj < n; jj += blockSize) {
            for (int kk = 0; kk < n; kk += blockSize) {
                for (int i = ii; i < min(ii + blockSize, n); ++i) {
                    for (int j = jj; j < min(jj + blockSize, n); ++j) {
                        for (int k = kk; k < min(kk + blockSize, n); ++k) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    vector<int> sizes = {100, 200, 500, 1000};
    for (auto n : sizes) {
        vector<vector<double>> A(n, vector<double>(n, 1)); 
        vector<vector<double>> B(n, vector<double>(n, 2));
        vector<vector<double>> C(n, vector<double>(n, 0));

        auto start = high_resolution_clock::now();
        multiplyMatricesBlocked(A, B, C,32);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Tiempo para multiplicar matrices de " << n << "x" << n << ": " << duration.count() << " ms" << endl;
    }
    return 0;
}
