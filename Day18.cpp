#include <iostream>

int countDivisors(int N) {
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if (N % i == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    std::cout << "Enter a positive integer N: ";
    std::cin >> N;

    if (N <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    int divisorsCount = countDivisors(N);
    std::cout << "Number of divisors of " << N << " is: " << divisorsCount << std::endl;

    return 0;
}
