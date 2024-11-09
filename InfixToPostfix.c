#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // For malloc and free

struct Node {
    char data;
    struct Node *next;
};

// Function to PUSH an element onto the stack
void PUSH(char data, struct Node **top) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); // Use malloc for memory allocation in C
    temp->data = data;
    temp->next = *top;
    *top = temp;
}

// Function to POP an element from the stack
char POP(struct Node **top) {
    if (*top == NULL) {
        return '\0';
    }

    struct Node *temp = *top;
    char result = temp->data;
    *top = (*top)->next;
    free(temp); // Free the memory after popping the element
    return result;
}

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
//By passing &top, the function postFix receives a struct Node **top (a pointer to a pointer), which allows the function to modify the top pointer itself, not just the contents of the node it points to.
char* postFix(char *infix, struct Node **top) {
    int len = strlen(infix);
    char *postfix = (char *)malloc((len + 1) * sizeof(char)); // Allocate memory for the postfix string
    int k = 0; // Index for postfix array

    for (int i = 0; i < len; i++) {
        int res = isOperator(infix[i]);
        if (res == 0) {
            postfix[k++] = infix[i];
        } else {  //*top represents the pointer to the top node of the stack. 
            while (*top != NULL && isOperator(infix[i]) <= isOperator((*top)->data)) {
                postfix[k++] = POP(top);
            }
            PUSH(infix[i], top);
        }
    }

    while (*top != NULL) {
        postfix[k++] = POP(top);
    }

    postfix[k] = '\0'; // Null terminate the postfix string
    return postfix;
}

int main() {
    struct Node *top = NULL;
    char str[] = "a+b*c-d";
    char *postfix = postFix(str, &top);//This means the postFix function receives a pointer to the pointer top.
    //If you passed just top (instead of &top), the function would only have a copy of the top pointer and could not modify the original top pointer in main. As a result, any changes to the stack (like pushing or popping nodes) would not be reflected outside the function.

    printf("POSTFIX STRING : %s\n", postfix);
    
    free(postfix); // Free the allocated memory for postfix

    return 0;
}
