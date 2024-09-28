#include <iostream>
#include <stack>

using namespace std;

// Function to insert an element in sorted order
void sortedInsert(stack<int> &st, int element) {
    // Base case: If the stack is empty or the top element is smaller than the element
    if (st.empty() || st.top() <= element) {
        st.push(element);
    } else {
        // Remove the top element
        int top = st.top();
        st.pop();
        // Recursively insert the element
        sortedInsert(st, element);
        // Put the top element back
        st.push(top);
    }
}

// Function to recursively sort the stack
void sortStack(stack<int> &st) {
    // Base case: If the stack is empty, do nothing
    if (!st.empty()) {
        // Remove the top element
        int top = st.top();
        st.pop();
        // Recursively sort the remaining stack
        sortStack(st);
        // Insert the top element back in sorted order
        sortedInsert(st, top);
    }
}

// Helper function to print the stack
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    cout << "Original Stack: ";
    printStack(st);

    // Sort the stack
    sortStack(st);

    cout << "Sorted Stack: ";
    printStack(st);

    return 0;
}
