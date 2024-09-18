#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagrams;
    
    // Iterate over each string in the input list
    for (string word : strs) {
        // Create a frequency count for each character (26 letters)
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        // Convert the frequency count to a string to use as a key
        string key = "";
        for (int count : freq) {
            key += to_string(count) + "#"; // Use '#' as a separator
        }
        
        // Group the original word with other anagrams
        anagrams[key].push_back(word);
    }
    
    // Collect the grouped anagrams from the map
    vector<vector<string>> result;
    for (auto& group : anagrams) {
        result.push_back(group.second);
    }
    
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> output = groupAnagrams(strs);
    
    // Print the output
    for (const auto& group : output) {
        cout << "[";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}
