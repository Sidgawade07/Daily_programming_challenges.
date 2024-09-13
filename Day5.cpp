#include <iostream>
#include <vector>
using namespace std;

vector<int> findLeaders(int arr[], int n) {
    vector<int> leaders;
    int max_from_right = arr[n-1]; // The last element is always a leader
    leaders.push_back(max_from_right);
    
    // Traverse the array from right to left
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] > max_from_right) {
            max_from_right = arr[i];
            leaders.push_back(max_from_right);
        }
    }
    
    // Reverse the vector because we collected leaders from right to left
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    vector<int> leaders = findLeaders(arr, n);
    
    cout << "Leaders: ";
    for (int leader : leaders) {
        cout << leader << " ";
    }
    return 0;
}
