#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> slidingWindowMax(const vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < arr.size(); ++i) {
        // Remove elements that are out of the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove elements smaller than the current element from the deque
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        // Add current element's index to the deque
        dq.push_back(i);

        // If we have processed at least k elements, add the maximum to the result
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = slidingWindowMax(arr, k);

    // Output the result
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
