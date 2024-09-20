#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    
    for (char ch : s) {
        // If it's an opening bracket, push it to the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } 
        // If it's a closing bracket, check for a matching opening bracket
        else {
            if (st.empty()) return false;  // No matching opening bracket
            char top = st.top();
            st.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    // If the stack is empty, all brackets were matched
    return st.empty();
}

int main() {
    string s = "[{()}]";
    cout << (isValid(s) ? "true" : "false") << endl;
    return 0;
}
