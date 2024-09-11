#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(const vector<int>& arr) {
    int slow = arr[0];
    int fast = arr[0];

    // Phase 1: Move slow by 1 step and fast by 2 steps until they meet
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    // Phase 2: Move both pointers one step at a time to find the duplicate
    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;  // This is the duplicate number
}

int main() {
    vector<int> arr = {3, 1, 3, 4, 2};  // Example input
    cout << "Duplicate Number: " << findDuplicate(arr) << endl;
    return 0;
}
