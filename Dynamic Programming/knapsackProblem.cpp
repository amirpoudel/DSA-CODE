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


#include <bits/stdc++.h>

int solve(vector<int>&arr,int sum,int n,vector<vector<int>>&dp){

    if(sum==0){
        return 1;
    }
    if(n<0 or sum<0){
        return 0;
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }

    if(arr[n]<=sum){
        //we have some choice
        dp[n][sum] =  solve(arr,sum-arr[n],n-1,dp) || solve(arr,sum,n-1,dp);
        return dp[n][sum];
    }else{
        //we have no choice
        dp[n][sum] =  solve(arr,sum,n-1,dp);
        return dp[n][sum];
    }



}
int solveTab(vector<int>&arr,int sum,int n){

    vector<vector<int>>dp(n+1,vector<int>(sum+1));


    //init

    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                dp[i][j]= false;
            }
            if(j==0){
                dp[i][j]=  true;
            }
        }
    }


    for(int i=1;i<n+1;i++){

        for(int j=1;j<sum+1;j++){
            //for this point check with previou ;
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }

        }
    }
    return dp[n][sum];

}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    // vector<vector<int>>dp(n+1,vector<int>(k+1,-1));

    // return solve(arr,k,n-1,dp);
    return solveTab(arr,k,n);
}