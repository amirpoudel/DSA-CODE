//
// Created by amirpoudel on 12/9/2022.
//
//Knapsack Problem - code studio


#include <bits/stdc++.h>
//Recursive
#include <bits/stdc++.h>

int solve(vector<int>&weight,vector<int>&value,int maxWeight,int n){
    if(n==0){
        if(weight[n]<=maxWeight){
            return value[n];
        }else{
            return 0;
        }
    }
    int include = 0;
    if(weight[n]<=maxWeight){
        include = value[n]+solve(weight,value,maxWeight-weight[n],n-1);

    }
    int exclude = 0+ solve(weight,value,maxWeight,n-1);


    int ans = max(include,exclude);
    return ans;

}

int solveMemo(vector<int>&weight,vector<int>&value,int maxWeight,int n,vector<vector<int>>&dp){
    if(n==0){
        if(weight[n]<=maxWeight){
            return value[n];
        }else{
            return 0;
        }
    }
    if(dp[n][maxWeight]!=-1){
        return dp[n][maxWeight];
    }
    int include = 0;
    if(weight[n]<=maxWeight){
        include = value[n]+solveMemo(weight,value,maxWeight-weight[n],n-1,dp);

    }
    int exclude = 0+ solveMemo(weight,value,maxWeight,n-1,dp);


    dp[n][maxWeight] = max(include,exclude);
    return dp[n][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    //return solve(weight,value,maxWeight,n-1);
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
    return solveMemo(weight,value,maxWeight,n-1,dp);
}