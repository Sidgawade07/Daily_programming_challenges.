#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int atMostKDistinct(const string &s, int k) {
    unordered_map<char, int> charCount;
    int left = 0, count = 0;

    for (int right = 0; right < s.size(); ++right) {
        charCount[s[right]]++;

        while (charCount.size() > k) {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0) {
                charCount.erase(s[left]);
            }
            left++;
        }

        count += right - left + 1;  // Count valid substrings ending at right
    }

    return count;
}

int countSubstringsWithExactlyKDistinct(const string &s, int k) {
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main() {
    string s = "pqpqs";
    int k = 2;

    int result = countSubstringsWithExactlyKDistinct(s, k);
    cout << result << endl;  // Output: 7

    return 0;
}
