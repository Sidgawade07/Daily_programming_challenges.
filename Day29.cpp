#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n) {
    // Special case for n = 0
    if (n == 0) return 0;

    // Special case for n = 1
    if (n == 1) return 1;

    // Create a vector to store Fibonacci numbers
    vector<long double> fib(n + 1);

    // Initialize base cases
    fib[0] = 0;
    fib[1] = 1;

    // Fill the vector using the bottom-up dynamic programming approach
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Return the n-th Fibonacci number
    return fib[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Calculate and output the n-th Fibonacci number
    cout << "The " << n << "-th Fibonacci number is: " << fibonacci(n) << endl;

    return 0;
}
