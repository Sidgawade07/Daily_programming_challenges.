#include <iostream>
#include <stack>
#include <cmath>  // For pow function
#include <sstream>
using namespace std;

int evaluatePostfix(string expression) {
    stack<int> s;
    stringstream ss(expression);
    string token;
    
    while (ss >> token) {
        // If the token is a number, push it to the stack
        if (isdigit(token[0]) || (token.length() > 1 && token[0] == '-')) {
            s.push(stoi(token));
        } else {
            // Pop two operands from the stack for an operator
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            
            // Apply the operation and push the result back to the stack
            if (token == "+") {
                s.push(a + b);
            } else if (token == "-") {
                s.push(a - b);
            } else if (token == "*") {
                s.push(a * b);
            } else if (token == "/") {
                s.push(a / b);  // Integer division
            } else if (token == "^") {
                s.push(pow(a, b));  // Exponentiation
            }
        }
    }

    // The final result is the only element left in the stack
    return s.top();
}

int main() {
    string expression = "3 4 2 * 1 5 - 2 3 ^ ^ / +";
    cout << evaluatePostfix(expression) << endl;  // Expected output: 3
    return 0;
}
