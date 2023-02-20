//
// Created by amir on 1/17/23.
//

// Pizza With 3n Slices

#include <bits/stdc++.h>

int solve(vector<int>&arr,int index ,int endIndex, int k,vector<vector<int>>&dp){
    if(k==0 or index>endIndex){
        return 0;
    }
    if(dp[index][k]!=-1){
        return dp[index][k];
    }
    int include = arr[index]+solve(arr,index+2,endIndex,k-1,dp);
    int exclude = 0+solve(arr,index+1,endIndex,k,dp);
    dp[index][k] = max(include,exclude);
    return dp[index][k];

}

int pizzaSharing(int n, vector<int> &arr)
{
    // Write your code here.\

    vector<vector<int>>dp1(n,vector<int>(n,-1));
    int case1 = solve(arr,0,n-2,n/3,dp1);
    vector<vector<int>>dp2(n,vector<int>(n,-1));
    int case2   = solve(arr,1,n-1,n/3,dp2);
    return max(case1,case2);
}