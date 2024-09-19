#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void backtrack(string &s, int start, vector<string> &result) {
    // If we've gone through every character, add the current permutation to the result
    if (start == s.size()) {
        result.push_back(s);
        return;
    }

    // Set to avoid duplicate permutations when there are repeating characters
    unordered_set<char> used;

    for (int i = start; i < s.size(); i++) {
        // If the character has already been used at this position, skip it
        if (used.find(s[i]) != used.end()) continue;
        used.insert(s[i]);

        // Swap the current character with the 'start' character
        swap(s[start], s[i]);

        // Recursively generate the rest of the permutations
        backtrack(s, start + 1, result);

        // Backtrack by swapping back to the original configuration
        swap(s[start], s[i]);
    }
}

vector<string> permute(string s) {
    vector<string> result;
    sort(s.begin(), s.end()); // Sort the string to handle duplicates easily
    backtrack(s, 0, result);
    return result;
}

int main() {
    string s = "abc";
    vector<string> permutations = permute(s);

    // Print the result
    for (const string &perm : permutations) {
        cout << perm << endl;
    }

    return 0;
}
