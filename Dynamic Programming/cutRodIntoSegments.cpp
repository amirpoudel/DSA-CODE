//
// Created by amirp on 12/5/2022.
//

//cut Rod into segements - code studio
#include<bits/stdc++.h>
//recursion solution

int solve(int n,int x,int y ,int z){
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    int firstCut = solve(n-x,x,y,z)+1;
    int secondCut = solve(n-y,x,y,z)+1;
    int thirdCut = solve(n-z,x,y,z)+1;
    int ans = max(firstCut,max(secondCut,thirdCut));
    return ans;
}
//TOPDOWN Approach
int solve(int n,int x,int y ,int z,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int firstCut = solve(n-x,x,y,z,dp)+1;
    int secondCut = solve(n-y,x,y,z,dp)+1;
    int thirdCut = solve(n-z,x,y,z,dp)+1;
    int ans = max(firstCut,max(secondCut,thirdCut));
    dp[n] = ans;
    return dp[n];
}
//Tabulation
int solveTabulation(int n,int x,int y,int z){
    vector<int>dp(n+1,INT_MIN);
    dp[0]=0;


    for(int i=1;i<=n;i++){

        if(i-x>=0){
            dp[i]=max(dp[i],dp[i-x]+1);
        }
        if(i-y>=0){
            dp[i]=max(dp[i],dp[i-y]+1);
        }
        if(i-z>=0){
            dp[i]=max(dp[i],dp[i-z]+1);
        }

    }
    if(dp[n]<0){
        return 0;
    }
    return dp[n];
}
//Space Optimization

int cutSegments(int n, int x, int y, int z) {
    // Write your code here.

    int ans = solve(n,x,y,z);
    if(ans<0){
        return 0;
    }

    return ans;
}