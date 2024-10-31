#include<iostream>
#include<string>
#include<array>
using namespace std;



int* bHT; // Declare the pointer for the dynamic array globally
int length; // Variable to track the array size
int idx = 1; 

void initializeArray(int initialSize) {
    bHT = new int[initialSize]; // Allocate memory for bHT
    length = initialSize; // Set the length
    for (int i = 0; i < length; i++)
    {
        bHT[i] = -1;
    }
    
}

// to add -1 to the newly created array
void increaseArr()
{
    // Allocate a new array with double the size
    int* newBHT = new int[length * 2];

    // Copy contents from bHT to newHT
    for (int k = 0; k < length; k++) {
        newBHT[k] = bHT[k];
    }

    for (int l = length*2 ;l > length;l--)
    {
        newBHT[l] = -1;
    }

    delete[] bHT;

    bHT = newBHT;
    length *= 2;
}

void enQueue(int data)
{
    // if array is filled completely
    if(idx >= length)
    {
        increaseArr();
    }

   
    bHT[idx] = data;
    int i = idx;
    while (i > 1 && bHT[i] > bHT[i/2])
    {
        // perform swapping
        int temp = bHT[i];
        bHT[i] = bHT[i/2];
        bHT[i/2] = temp;

        i = i / 2;
    }
    
    idx++;
}

int dequeue()
{
    if (idx <= 1) // No elements to dequeue
    {
        cout << "Heap is empty!" << endl;
        return -1;
    }

    int result = bHT[1]; // root element (max element)
    bHT[1] = bHT[idx - 1]; // replace root with the last element
    bHT[idx - 1] = -1; // reset the last element
    idx--; // decrease heap size

    // Reheapify from the root
    int N = 1;
    while (N * 2 < idx) // ensure we don't go beyond heap size
    {
        int left = N * 2;
        int right = N * 2 + 1;

        // Find the larger child
        int greater = left;
        if (right < idx && bHT[right] > bHT[left])
        {
            greater = right;
        }

        // Swap if parent is smaller than the larger child
        if (bHT[N] < bHT[greater])
        {
            int temp = bHT[N];
            bHT[N] = bHT[greater];
            bHT[greater] = temp;
            N = greater; // continue heapifying down
        }
        else
        {
            break; // heap property restored
        }
    }

    return result;
}

void printBHT(int arr[])
{
    for(int j = 1;j < length;j++)
    {
        cout << arr[j] << " " << endl;
    }
}


int main()
{   
    // Call the initialization function
    initializeArray(6);
    enQueue(47);
    enQueue(5);
    enQueue(23);
    enQueue(69);
    enQueue(88);
    enQueue(67);
    // printBHT(bHT);

    cout << "Dequeue: " << dequeue() << endl;
    cout << "Dequeue: " << dequeue() << endl;
    cout << "Dequeue: " << dequeue() << endl;
    cout << "Dequeue: " << dequeue() << endl;
    cout << "Dequeue: " << dequeue() << endl;
    cout << "Dequeue: " << dequeue() << endl;
   
    return 0;
}