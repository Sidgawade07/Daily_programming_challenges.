#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int>& s, int element) {
    // Base case: If stack is empty, push the element
    if (s.empty()) {
        s.push(element);
        return;
    }

    // Step 1: Remove the top element
    int topElement = s.top();
    s.pop();

    // Step 2: Recursively call insertAtBottom
    insertAtBottom(s, element);

    // Step 3: Push the top element back
    s.push(topElement);
}

// Function to reverse the stack
void reverseStack(stack<int>& s) {
    // Base case: If stack is empty, return
    if (s.empty()) {
        return;
    }

    // Step 1: Pop the top element
    int topElement = s.top();
    s.pop();

    // Step 2: Recursively reverse the remaining stack
    reverseStack(s);

    // Step 3: Insert the popped element at the bottom
    insertAtBottom(s, topElement);
}

// Helper function to print the stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Original Stack: ";
    printStack(s);

    reverseStack(s);

    cout << "Reversed Stack: ";
    printStack(s);

    return 0;
}
