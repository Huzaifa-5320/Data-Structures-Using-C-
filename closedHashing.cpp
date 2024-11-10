#include<iostream>
#include<string>
using namespace std;

struct Node{
    int data;
    Node  *next = nullptr;
};

// hash size and hash tablle
int hashSize = 7;
int *HT = new int[hashSize];

// loadfactor
double loadFactor = 0.0;

// numbers of elements in hash table
int n = 0;

// function to initialize array with zeros
void initializeArr(int *&arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i]=0;
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

// increasing the size of thee hash table and then copying the elements
void increaseSize()
{
    // new hash size and table
    int newHashSize = findNextPrime();
    int *newHT = new int[newHashSize];
    
    // Initializing array with zeros
    initializeArr(newHT,newHashSize);

    // copying the index of the old hash table to the new hash table
    for (int i = 0; i < hashSize; i++)
    {
        if (HT[i]!=0)
        {
            int key = HT[i];
            int newHI = key % newHashSize;
        
            if (newHT[newHI] == 0)
            {
                newHT[newHI] = key;
            }
            else
            {
                while(newHT[newHI]!=0)
                {
                    newHI = (newHI + 1) % newHashSize;
                }
                newHT[newHI] = key;  
            }
        }
    }
    delete[] HT;
    HT = newHT;
    hashSize = newHashSize;
}

//checking if the key already exists in the hash table
bool contains(int key)
{
    int HI = key % hashSize;
    while(HT[HI]!=0)
    {
        if (HT[HI] == key )
        {
            return true;
        }
        HI = (HI + 1)%hashSize;
    }
    return false;
}

void insert(int key)
{
    // checking if the key already exists
    if(contains(key))
    {
        cout << "Key " << key << " is already present in the hash table." << endl;
        return;
    }

    // calculating hash index
    int HI = key % hashSize;

    // checking if HI is available 
    if(HT[HI]==0)
    {
        HT[HI] = key;
        n++;
    }
    else
    {
        // moving ahead of hash index until we found available index.
        while(HT[HI]!=0)
        {
            HI = (HI + 1) % hashSize;
        }
        HT[HI] = key;
        n++;  
    }

    // update the globaal load factor after each insertion
    loadFactor = (double)n/hashSize;

    // if load factor exceeds 0.5, increase the size of the hash table;
    if (loadFactor > 0.7)
    {
        increaseSize();
    }
}

int search(int key)
{
    int HI = key % hashSize;
    int initialHI = HI;

    // this condition shows that key isn't present
    while(HT[HI] != -1)
    {
        if(HT[HI]==key)
        {
            return HI;
        } 
        // move to next index
        HI = (HI + 1)%hashSize;

        // if we loop back to the start , means we have checked the whole loop and the key isn't present
        if(HI==initialHI)
        {
            break;
        }
    }
    return -1;
}

// Printing the hash table
void printArr()
{
    for(int i=0; i < hashSize; i++)
    {
        cout << HT[i] << endl;
    }
}


int main()
{
    initializeArr(HT, hashSize);
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    insert(14);
    insert(15);
    insert(16);
    insert(21); 
    insert(22);
    insert(23);


    printArr();
    return 0;
}
