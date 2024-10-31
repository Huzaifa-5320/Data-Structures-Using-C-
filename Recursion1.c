#include<stdio.h>

//Q1
void printNum(int n){
    if (n==0){
        return;
    }
    printf("%d\n",n);
    printNum(n-1);

}

//Q2
int printSum(int i,int n,int sum){
    if (i==n){
        sum+=i;
        printf("%d\n",sum);
        return;
    }
    
    sum += i;
    printSum(i+1,n,sum);
    printf("%d\n",i);

}

//Q3
int factorial(int n){
    if (n==1 || n==0){
        return 1;
    }
    int fact_nm1 = factorial(n-1);
    int fact_n = n*fact_nm1;
    return fact_n;
}


//Q4
void fibonacci(int a,int b,int n){
    if(n==0){
        return;
    }
    int c = a + b;
    printf("%d\n",c);
    fibonacci(b,c,n-1);

}

//Q5
int power(int x,int n){
    if(n==0){
        return 1;
    }
    if(x==0){
        return 0;
    }
    int xPownm1 = power(x,n-1);
    int xPown = x * xPownm1;
    return xPown;
}

//Q6
int power1(int x,int n){
    if(n==0){
        return 1;
    }
    if(x==0){
        return 0;
    }
    //if n is even 
    if(n%2==0){
        return power1(x,n/2)*power1(x,n/2);
    }
    else{
        return power1(x,n/2)*power1(x,n/2)*x;
    }

}



int main(){
    // printNum(5);

    // printSum(1,5,0);

    // int n=5;
    // int ans = factorial(n);
    // printf("%d\n",ans);

    // int a=0;
    // int b=1;
    // printf("%d\n",a);
    // printf("%d\n",b);
    // int n=7;
    // fibonacci(a,b,n-2);

    // int x=2;
    // int n=5;
    // int ans = power(x,n);
    // printf("%d\n",ans);

    int x=2;
    int n=5;
    int ans = power1(x,n);
    printf("%d\n",ans);




    return 0;
}
