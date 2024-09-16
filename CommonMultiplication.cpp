#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void multiplyMatrices(const vector<vector<double>>& A, const vector<vector<double>>& B, vector<vector<double>>& C){
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
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
        multiplyMatrices(A, B, C);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Tiempo para multiplicar matrices de " << n << "x" << n << ": " << duration.count() << " ms" << endl;
    }
    return 0;
}
