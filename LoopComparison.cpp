#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int MAX = 1000;

double A[MAX][MAX];
double x[MAX];
double y[MAX];

void firstLoops() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

void secondLoops() {
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

int main() {
    for (int i = 0; i < MAX; i++) {
        x[i] = 0.1;
        y[i] = 0;
        for (int j = 0; j < MAX; j++) {
            A[i][j] = i + j;
        }
    }
    auto start1 = high_resolution_clock::now();
    firstLoops();
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    cout << "Tiempo para el primer bucle: " << duration1.count() << " ms" << endl;

    for (int i = 0; i < MAX; i++) {
        y[i] = 0;
    }

    auto start2 = high_resolution_clock::now();
    secondLoops();
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    cout << "Tiempo para el segundo bucle: " << duration2.count() << " ms" << endl;
    return 0;
}
