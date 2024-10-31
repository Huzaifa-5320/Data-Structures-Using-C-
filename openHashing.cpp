#include<iostream>
#include<string>
using namespace std;

struct Node{
    int data;
    Node  *next = nullptr;
};

int hashSize = 7;
Node **HT = new Node *[hashSize];

// Number of elements in Hash Table;
int n = 0;

double loadFactor = 0.0;

// function to initialize hash table
void initializeHT(Node **&HT,int size)
{
    for(int i=0;i<size;i++)
    {
        HT[i] = nullptr; // Initialize all pointers to nullptr
    }
}

int findNextPrime()
{
    int nextPrime = hashSize * 2;
    bool flag = false;

    while(!flag)
    {
        flag = true;
        for(int i = 2 ; i <= nextPrime/2; i++)
        {
            if(nextPrime % i == 0)
            {
                flag = false;  // its not prime
                break;
            }
        }
        if(!flag)
        {
            nextPrime++;
        }
    }
    return nextPrime;
}


void increaseSize()
{
    // creating a new hash table with larger size
    int newHashsize = findNextPrime();
    Node **newHT = new Node *[newHashsize];

    // initializing the newly created hash table with nullptr
    initializeHT(newHT,newHashsize);

    // copying the values from the old table to the newly created table
    for (int i = 0; i < hashSize; i++)
    {
        if (HT[i] != nullptr)
        {

            // Taking the first node at index i 
            Node *current = HT[i];
            
            // loop through the chain and rehash every node into the new table
            while(current != nullptr)
            {
                int HI = current->data % newHashsize;
                Node *temp = new Node;
                temp->data = current->data;

                // if new hash index is empty
                if (newHT[HI]==nullptr)
                {
                    newHT[HI] = temp;
                }
                else
                {
                    // Append at the end of that chain. 
                    Node *current = newHT[HI];
                    while(current->next!=nullptr)
                    {
                        current = current->next;
                    }
                    current->next = temp;

                }

                // move to the  next node in the old chain
                current = current->next;

            }

        }
    }

    // update hash table with the new one
    HT = newHT;
    hashSize = newHashsize;
}


bool contains(int key)
{
    int HI = key % hashSize;
    if (HT[HI]==nullptr)
    {
        return false;
    }
    else
    {
        Node *current = HT[HI];
        while(current!=nullptr)
        {
            if (current->data == key)
            {
                return true;
            }
            current = current->next;
        }
    } 
    return false;
}

void insert(int key){
    // checking if it already exists
    if(contains(key)){
        cout << "Duplicate index are not allowed"; 
        return;
    }

    // calculating hash index 
    int HI = key % hashSize;

    Node *temp = new Node;
    temp->data=key;

    // if hash index is null 
    if(HT[HI] == nullptr)
    {
        HT[HI] = temp;
    }
    else
    {
        // appending at the last of that particular index
        Node *current = HT[HI];
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next=temp;
    }

    // updating the number of elements
    n++;

    // updating the load balancer after each insertion 
    loadFactor = (double)n / hashSize;

    if (loadFactor > 0.5)
    {
        increaseSize();
    }
}



Node* search(int key)
{
    int HI = key % hashSize;
    Node *temp = HT[HI];

    while(temp != nullptr)
    {
        if(temp->data==key)
        {
            cout << "key exists" <<endl;
            return temp;
        }
        temp = temp->next;
    }

    cout << "key does not exisst" <<endl;
    return nullptr;
}

void printArr(){
    for (int i = 0; i < hashSize; i++)
    {
        Node *current = HT[i];
        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
    
}


int main(){
    initializeHT(HT, hashSize);
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    // insert(14); // first increase will be after inserting 14.
    // insert(15);
    // insert(16);
    //insert(21); // second increase will be after inserting 21.
    // insert(22);
    // insert(23);


    printArr();

    return 0;
}