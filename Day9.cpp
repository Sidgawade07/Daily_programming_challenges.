#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    // Start with the first string as the common prefix
    string prefix = strs[0];

    // Iterate over the rest of the strings
    for (int i = 1; i < strs.size(); i++) {
        // Compare the current string with the prefix
        int j = 0;
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
            j++;
        }
        // Reduce the prefix to the common part
        prefix = prefix.substr(0, j);

        // If at any point the prefix becomes empty, return ""
        if (prefix.empty()) {
            return "";
        }
    }

    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    string result = longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}
