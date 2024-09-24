#include <iostream>
#include <numeric> // For std::gcd

using namespace std;

long long lcm(long long N, long long M) {
    return (N * M) / gcd(N, M);
}

int main() {
    long long N, M;
    cout << "Enter two integers N and M: ";
    cin >> N >> M;

    cout << "LCM: " << lcm(N, M) << endl;

    return 0;
}
