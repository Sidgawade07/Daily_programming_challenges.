#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    int start = 0, maxLength = 1;

    for (int i = 0; i < s.length(); i++) {
        // Check for odd length palindromes
        int left = i, right = i;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }

        // Check for even length palindromes
        left = i;
        right = i + 1;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    string input = "babad";
    string result = longestPalindrome(input);
    cout << "Longest Palindromic Substring: " << result << endl;
    return 0;
}
