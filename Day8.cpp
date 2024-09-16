#include <iostream>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    // Step 1: Remove leading and trailing spaces
    int n = s.length();
    int left = 0, right = n - 1;
    
    // Trim leading spaces
    while (left < n && s[left] == ' ') left++;
    
    // Trim trailing spaces
    while (right >= 0 && s[right] == ' ') right--;
    
    string result = "";
    string word = "";
    
    // Step 2: Traverse from the right and build the reversed word list
    for (int i = right; i >= left; --i) {
        if (s[i] != ' ') {
            word += s[i];  // Build the current word in reverse
        } else if (!word.empty()) {
            reverse(word.begin(), word.end());  // Reverse the current word
            if (!result.empty()) {
                result += " ";  // Add a space before appending next word
            }
            result += word;  // Append the reversed word to the result
            word = "";  // Reset the word
        }
    }
    
    // Add the last word
    if (!word.empty()) {
        reverse(word.begin(), word.end());
        if (!result.empty()) {
            result += " ";
        }
        result += word;
    }
    
    return result;
}

int main() {
    string s = "  the sky  is blue  ";
    cout << "\"" << reverseWords(s) << "\"" << endl;  // Output: "blue is sky the"
    return 0;
}
