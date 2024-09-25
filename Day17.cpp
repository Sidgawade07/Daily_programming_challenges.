#include <iostream>
using namespace std;

void primeFactorization(int N) {
    // Print the number of 2s that divide N
    while (N % 2 == 0) {
        cout << 2 << " ";
        N /= 2;
    }

    // N must be odd at this point, so we can skip even numbers
    for (int i = 3; i * i <= N; i += 2) {
        // While i divides N, print i and divide N
        while (N % i == 0) {
            cout << i << " ";
            N /= i;
        }
    }

    // This condition is to check if N is a prime number greater than 2
    if (N > 2)
        cout << N << " ";
}

int main() {
    int N = 18;  // Example input
    primeFactorization(N);
    return 0;
}
