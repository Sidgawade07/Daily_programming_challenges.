#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string S) {
    vector<int> lastIndex(256, -1); // Vector to store the last index of every character
    int max_len = 0;  // Maximum length of the substring without repeating characters
    int start = -1;   // Start of the current substring

    for (int i = 0; i < S.length(); ++i) {
        // Update the start position to the maximum of current start or the last index of the character
        start = max(start, lastIndex[S[i]]);
        // Calculate the max length by considering the current substring length
        max_len = max(max_len, i - start);
        // Update the last index of the current character
        lastIndex[S[i]] = i;
    }

    return max_len;
}

int main() {
    string S = "abcabcbb";
    cout << lengthOfLongestSubstring(S) << endl;  // Output: 3
    return 0;
}
