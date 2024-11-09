#include <iostream>
#include <cstring>
#include <cstdlib>  // For new and delete

using namespace std;

// Define the Node class
class Node {
public:
    char data;
    Node *next;

    Node(char d){
        data=d; 
        *next=nullptr
};

// Stack class for managing the stack operations
class Stack {
private:
    Node *top; // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    Stack() : top(nullptr) {}

    // PUSH an element onto the stack
    void PUSH(char data) {
        Node *temp = new Node(data);  // Create a new node with the given data
        temp->next = top;
        top = temp;
    }

    // POP an element from the stack
    char POP() {
        if (top == nullptr) {
            return '\0'; // Stack Underflow
        }

        Node *temp = top;
        char result = temp->data;
        top = top->next;
        delete temp; // Free the memory after popping the element
        return result;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Peek at the top element
    char peek() const {
        return top != nullptr ? top->data : '\0';
    }
};

// Function to check if a character is an operator and return its precedence
int isOperator(char a) {
    if (a == '*' || a == '/') {
        return 2;
    } else if (a == '+' || a == '-') {
        return 1;
    }
    return 0;
}

// Function to convert infix expression to postfix
char* postFix(const char *infix, Stack &stack) {
    int len = strlen(infix);
    char *postfix = new char[len + 1]; // Allocate memory for the postfix string
    int k = 0; // Index for postfix array

    for (int i = 0; i < len; i++) {
        int res = isOperator(infix[i]);
        if (res == 0) {
            postfix[k++] = infix[i]; // If it's an operand, add to postfix
        } else {
            while (!stack.isEmpty() && isOperator(infix[i]) <= isOperator(stack.peek())) {
                postfix[k++] = stack.POP(); // Pop operators from stack to postfix
            }
            stack.PUSH(infix[i]); // Push the current operator onto the stack
        }
    }

    // Pop all remaining operators from the stack
    while (!stack.isEmpty()) {
        postfix[k++] = stack.POP();
    }

    postfix[k] = '\0'; // Null terminate the postfix string
    return postfix;
}

int main() {
    Stack stack; // Create a stack for operators
    const char str[] = "a+b*c-d"; // Infix expression

    char *postfix = postFix(str, stack); // Get the postfix expression

    cout << "POSTFIX STRING: " << postfix << endl;

    delete[] postfix; // Free the allocated memory for postfix string

    return 0;
}
