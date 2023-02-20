//
// Created by amir on 1/24/23.
//


#include<iostream>
#include<vector>
int solve(vector<int>&arr,int n){

    if(n<0){
        return 0;
    }

    return solve(arr,n-1)+arr[n];

}

bool subsetSum(vector<int>&arr,int n,int target,vector<vector<int>>&dp){

    if(target==0){
        return true;
    }
    if(n<0 or target<0){
        return false;
    }
    if(dp[n][target]!=-1){
        return dp[n][target];
    }
    bool include ;
    if(arr[n]<=target){
        include = subsetSum(arr, n-1,  target-arr[n],dp);
    }
    bool exclude  = subsetSum(arr,  n-1,  target,dp);
    dp[n][target] =  include || exclude;
    return dp[n][target];

}

bool subsetSumTabulation(vector<int>&arr,int n,int sum){


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

bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.
    int ans = solve(arr,n-1);
    //vector<vector<int>>dp(n+1,vector<int>(ans/2+1,-1));
    if(ans%2==0){
        //return subsetSum(arr,n,ans/2,dp);
        return subsetSumTabulation(arr,n,ans/2);
    }else{
        return false;
    }
}
