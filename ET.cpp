#include <iostream>
#include <string>
using namespace std;

struct ETNode {
    char data;
    ETNode *LC, *RC;
};

int isOperator(char a) {
    if (a == '(') {
        return 4;
    } else if (a == ')') {
        return 3;
    } else if (a == '*' || a == '/') {
        return 2;
    } else if (a == '+' || a == '-') {
        return 1;
    }
    return 0;
}

void expTree(string postfix, int &top, ETNode *stack[]) {
    int len = postfix.length();
    for (int i = 0; i < len; i++) {
        char res = postfix[i];
        ETNode *temp = new ETNode();
        temp->data = res;
        temp->LC = temp->RC = NULL;

        if (isOperator(res) == 0) {
            // Operand
            stack[++top] = temp;
        } else {
            // Operator
            if (top < 1) {
                cout << "Invalid postfix expression." << endl;
                return;
            }
            temp->RC = stack[top--];
            temp->LC = stack[top--];
            stack[++top] = temp;
        }
    }
}

void InOrder(ETNode *node) {
    if (node == NULL) return;
    if (node->LC!=NULL){
        InOrder(node->LC);
    } 
    cout << node->data << " ";
    if (node->RC != NULL) {
        InOrder(node->RC);
    }
}

// void preOrder(ETNode *node) {
//     if (node == NULL) return;
//     cout << node->data << " ";
//     if (node->LC!=NULL){
//         preOrder(node->LC);
//     } 
//     if (node->RC != NULL) {
//         preOrder(node->RC);
//     }
// }
void preOrder(ETNode *node) {
    if (node == NULL) return;
    cout << node->data << " ";
    preOrder(node->LC);
    preOrder(node->RC);

}

void postOrder(ETNode *node) {
    if (node == NULL) return;
    if (node->LC!=NULL){
        postOrder(node->LC);
    } 
    if (node->RC != NULL) {
        postOrder(node->RC);
    }
    cout << node->data << " ";
}

void deleteTree(ETNode *node) {
    if (node == NULL) return;
    deleteTree(node->LC);
    deleteTree(node->RC);
    delete node;
}

int main() {
    ETNode *stack[10];
    int top = -1;
    ETNode *root = NULL;
    string postfix = "AB+CD-*";
    
    expTree(postfix, top, stack);
    
    if (top == 0) {
        root = stack[top];
        cout << "Inorder Traversal of the Expression Tree: ";
        InOrder(root);
        cout << endl;
        cout << "Preorder Traversal of the Expression Tree: ";
        preOrder(root);
        cout << endl;
        cout << "Postorder Traversal of the Expression Tree: ";
        postOrder(root);
        cout << endl;
    } else {
        cout << "Error in expression." << endl;
    }
    
    deleteTree(root);
    return 0;
}
