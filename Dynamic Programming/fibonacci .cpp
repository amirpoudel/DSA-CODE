//
// Created by amirp on 11/27/2022.
//

//Fibonacci number

//Top Down Approach - Buttom Up Approach - Space Optimization

#include<bits/stdc++.h>
using namespace std;
//Top Down Approach
int fib(int n,vector<int>&dpArr){
    if(n==1 or n==0){
        return n;
    }
    if(dpArr[n]!=-1){
        return dpArr[n];
    }
    dpArr[n]= fib(n-1,dpArr)+fib(n-2,dpArr);
    return dpArr[n];
}

//Buttom Up Approach - Tabulation

int fibonacci(int n,vector<int>&dpArr){
    dpArr[0]=0;
    dpArr[1]=1;
    for(int i=2;i<=n;i++){
        dpArr[i]=dpArr[i-1]+dpArr[i-2];
    }
    return dpArr[n];
}

//Space Optimization
int fibSpace(int n){
    int prev1 = 1;
    int prev2 = 0;

    for(int i=2;i<=n;i++){
        int curr = prev1+prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    /*
    *  Write your code here.
     *  Read input as specified in the question.
     *  Print output as specified in the question.
    */
    int n;
    cin>>n;
    vector<int>dpArr(n+1);
    for(int i=0;i<n+1;i++){
        dpArr[i]=-1;
    }
    int ans = fibonacci(n,dpArr);
    cout<<ans;
}