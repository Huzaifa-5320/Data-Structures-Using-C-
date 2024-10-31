#include <iostream>
#include<string>
using namespace std;

void towerOfHanoi(int n,string src,string helper,string dest)
{
    if(n==1)
    {
        cout << "Transfer disk " + to_string(n) + " from " + src + " to " + dest <<endl;
        return;
    }
    towerOfHanoi(n-1,src,dest,helper);
    cout << "Transfer disk " + to_string(n) + " from " + src + " to " + dest <<endl;
    towerOfHanoi(n-1,helper,src,dest);
}

void revString(string str,int idx)
{
    if (idx == 0)
    {
        cout << str[idx];
        return;
    }
    cout << str[idx];
    revString(str,idx-1);
}

void firstAndLastOccurance(string str,int idx,char element)
{
    static int first = -1;
    static int last = -1;

    if(idx == str.length())
    {
        cout << first << endl;
        cout << last << endl;
        return;
    }
    char curChar = str[idx];
    if (curChar == element)
    {
        if(first == -1)
        {
            first = idx;
        }
        else{
            last = idx;
        }
    }
    firstAndLastOccurance(str,idx+1,element);
}

 
bool strictlySorted(int arr[],int size,int idx)
{
    if(idx==size-1)
    {
        return true;
    }
    if(arr[idx]>=arr[idx+1])
    {
        return false;
    }
    return strictlySorted(arr,size,idx+1);
}

// Through iteration approach
// string moveX(string str)
// {   
//     int j=0;
//     for(int i=0;i<str.length();i++) 
//     {
//         if(str[i]!='x' && str[j]=='x')
//         {
//             char temp = str[i];
//             str[i]=str[j];
//             str[j]=temp;
//         }
//         if(str[j]!='x')
//         {
//             j++;
//         }
//     }
//     return str;
// }

// Through recursion
void moveX(string str,int idx,int count,string &newString)
{
    if(idx == str.length())
    {
        for(int i=0;i<count;i++)
        {
            newString += 'x';

        }
        cout << newString <<endl;
        return;
    }
    char currChar = str[idx];
    if(currChar == 'x')
    {
        count++;
        moveX(str,idx+1,count,newString);
    }
    else{
        newString += currChar;
        moveX(str,idx+1,count,newString);
    }
}

int main(){
    //Q1 
    int n = 4;
    // towerOfHanoi(n,"S","H","D");

    //Q2
    string str = "HUZAIFA";
    // revString(str,str.length()-1);

    //Q3
    string str1 = "babababab";
    // firstAndLastOccurance(str1,0,'a');

    //Q4
    int arr[7]={1,2,3,4,5,6,7};
    int size = 7;
    // cout << strictlySorted(arr,7,0) <<endl;

    //Q5
    string str2 = "axvgxsxsxx";
    string newString = "";
    // iterative approach
    // cout << moveX(str2) << endl;
    //recursive approaach
    // moveX(str2,0,0,newString);
    
    //Q6
    string str3 = "avbxcefgabwsc";
    // removeDup(str3);



    
    return 0;
}