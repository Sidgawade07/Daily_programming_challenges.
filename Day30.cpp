#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1); // Create a dp array of size amount+1, initialized to a large value
    dp[0] = 0; // Base case: No coins are needed to make amount 0

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1); // Take the minimum coins required
            }
        }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount]; // If the value is unchanged, return -1
}

int main() {
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Minimum coins for amount " << amount1 << ": " << coinChange(coins1, amount1) << endl;

    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Minimum coins for amount " << amount2 << ": " << coinChange(coins2, amount2) << endl;

    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Minimum coins for amount " << amount3 << ": " << coinChange(coins3, amount3) << endl;

    return 0;
}
