#include <iostream>
#include <iomanip>

float fsumAscending (float a[], int N) {
    float sum = 0;
    for (int i=0;  i < N;  ++i) {
        sum += a[i];
    }
    return sum;
}

float fsumDescending (float a[], int N) {
    float sum = 0;
    for (int i=N-1;  i >= 0;  --i) {
        sum += a[i];
    }
    return sum;
}

double dsumAscending (float a[], int N) {
    double sum = 0;
    for (int i=0;  i < N;  ++i) {
        sum += a[i];
    }
    return sum;
}

double dsumDescending (float a[], int N) {
    double sum = 0;
    for (int i=N-1;  i >= 0;  --i) {
        sum += a[i];
    }
    return sum;
}

float kahan(float a[], int N) {
        float sum = a[0];
        float c = 0.0;
        for (int i=1;  i < N;  ++i) {
            float y = a[i] - c;
            float t = sum + y;
            c = (t - sum) - y;
            sum = t;
        }
        return sum;
    }

void main() {
    const int N = 100000;
    float a[N]; // Reciprocals { 1/100000, 1/99999, 1/99998, 1/99997, ..., 1/3, 1/2, 1/1 }

    for (int i=0;  i < N;  ++i) {
        a[N-1-i] = static_cast<float>(1.0/(i+1));
    }

    std::cout << std::setprecision(16) << " float descending: " << fsumDescending(a,N) << '\n';
    std::cout << std::setprecision(16) << " float ascending:  " << fsumAscending(a,N) << '\n';
    std::cout << std::setprecision(16) << " kahan descending: " << kahan(a,N) << '\n';
    std::cout << std::setprecision(16) << "double ascending:  " << dsumAscending(a,N) << '\n';
    std::cout << std::setprecision(16) << "double descending: " << dsumDescending(a,N) << '\n';
}
