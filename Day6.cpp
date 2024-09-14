#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<pair<int, int>> findSubarraysWithZeroSum(vector<int>& arr) {
    unordered_map<int, int> prefixSums;
    vector<pair<int, int>> result;
    int prefixSum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            result.push_back({0, i});
        }

        if (prefixSums.find(prefixSum) != prefixSums.end()) {
            result.push_back({prefixSums[prefixSum] + 1, i});
        }

        prefixSums[prefixSum] = i;
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};
    vector<pair<int, int>> result = findSubarraysWithZeroSum(arr);

    for (auto& subarray : result) {
        cout << "(" << subarray.first << ", " << subarray.second << ")\n";
    }

    return 0;
}
