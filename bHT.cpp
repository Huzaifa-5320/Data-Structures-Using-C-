#include <iostream>
using namespace std;

int* bHT; // Declare the pointer for the dynamic array globally
int length; // Variable to track the array size
int i = 0; // For maintaining the index of arr throughout the program

// Function to initialize the dynamic array
void initializeArray(int initialSize) {
    bHT = new int[initialSize]; // Allocate memory for bHT
    length = initialSize; // Set the length
}



// Function to increase the size of the array
void increaseArr() {
    // Allocate a new array with double the size
    int* newBHT = new int[length * 2];

    // Copy contents from bHT to newBHT
    for (int k = 0; k < length; k++) {
        newBHT[k] = bHT[k]; // Copy the existing elements
    }

    delete[] bHT; // Free the old array memory
    bHT = newBHT; // Update the pointer to point to the new array
    length *= 2; // Update the length
}

// Function to enqueue data into the array
void enQueue(int data) {
    // If the array is filled completely
    if (i == length) { // Correctly check if current index equals length
        increaseArr(); // Call to increase the array size
    }
    
    bHT[i] = data; // Assign data to the current index
    i++; // Increment the index
}

// Function to print the contents of the array
void printBHT() {
    for (int j = 0; j < i; j++) { // Print only filled elements
        cout << bHT[j] << " "; // Print each element
    }
    cout << endl; // New line after printing
}

int main() {
    initializeArray(4); // Call the initialization function
    cout << "Initial length: " << length << endl;

    // Enqueue some elements
    enQueue(47);
    enQueue(5);
    enQueue(23);
    enQueue(69);
    // Uncomment to test dynamic resizing
    // enQueue(88); 
    // enQueue(67); 
    
    cout << "Elements in bHT: ";
    printBHT(); // Print the array contents

    // Free dynamically allocated memory
    delete[] bHT; // Ensure to free the allocated memory
    return 0;
}
