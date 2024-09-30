#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int findElement(vector<int>& arr, int k) {
    unordered_map<int, int> freqMap;

    // Step 1: Count frequency of each element
    for (int num : arr) {
        freqMap[num]++;
    }

    // Step 2: Find the first element with frequency exactly k
    for (int num : arr) {
        if (freqMap[num] == k) {
            return num;
        }
    }

    // Step 3: If no element with frequency k, return -1
    return -1;
}

int main() {
    vector<int> arr = {3, 1, 4, 4, 5, 2, 6, 1, 4};
    int k = 2;
    cout << "First element with frequency " << k << " is: " << findElement(arr, k) << endl;
    
    // Test Case 1
    arr = {2, 3, 4, 2, 2, 5, 5};
    k = 2;
    cout << "First element with frequency " << k << " is: " << findElement(arr, k) << endl;

    // Test Case 2
    arr = {1, 1, 1, 1};
    k = 1;
    cout << "First element with frequency " << k << " is: " << findElement(arr, k) << endl;

    // Test Case 3
    arr = {10};
    k = 1;
    cout << "First element with frequency " << k << " is: " << findElement(arr, k) << endl;

    // Test Case 4
    arr = {6, 6, 6, 6, 7, 7, 8, 8, 8};
    k = 3;
    cout << "First element with frequency " << k << " is: " << findElement(arr, k) << endl;

    return 0;
}
