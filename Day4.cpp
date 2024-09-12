#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

// Function to merge arr1 and arr2 in-place
void mergeInPlace(std::vector<int>& arr1, std::vector<int>& arr2) {
    int m = arr1.size(); // Size of arr1
    int n = arr2.size(); // Size of arr2

    // Start merging from the end of arr1 and arr2
    int i = m - 1; // Pointer for the end of arr1
    int j = 0;     // Pointer for the start of arr2

    while (i >= 0 && j < n) {
        if (arr1[i] > arr2[j]) {
            std::swap(arr1[i], arr2[j]);
            // Now arr2 might not be sorted, we need to sort arr2
            // In this case, we use insertion sort for simplicity
            int k = j;
            while (k + 1 < n && arr2[k] > arr2[k + 1]) {
                std::swap(arr2[k], arr2[k + 1]);
                k++;
            }
        }
        i--;
    }
}

// Function to print the arrays
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr1 = {1, 3, 5, 7};
    std::vector<int> arr2 = {2, 4, 6, 8};

    std::cout << "Before merge:" << std::endl;
    std::cout << "arr1: ";
    printArray(arr1);
    std::cout << "arr2: ";
    printArray(arr2);

    mergeInPlace(arr1, arr2);

    std::cout << "After merge:" << std::endl;
    std::cout << "arr1: ";
    printArray(arr1);
    std::cout << "arr2: ";
    printArray(arr2);

    return 0;
}
