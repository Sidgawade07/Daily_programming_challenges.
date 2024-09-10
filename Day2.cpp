#include <iostream>
#include <vector>

int findMissingNumber(const std::vector<int>& arr) {
    int n = arr.size() + 1;  // Since the array length is n-1, n should be arr.size() + 1
    int totalSum = n * (n + 1) / 2;  // Sum of the first n natural numbers
    int arraySum = 0;  // To store the sum of elements in the array

    // Calculate the sum of elements in the array
    for (int num : arr) {
        arraySum += num;
    }

    // The missing number is the difference between the total sum and the array sum
    return totalSum - arraySum;
}

int main() {
    // Example array
    std::vector<int> arr = {1, 2, 4, 5};

    // Find and print the missing number
    int missingNumber = findMissingNumber(arr);
    std::cout << "Missing Number: " << missingNumber << std::endl;  // Output: 3

    return 0;
}
