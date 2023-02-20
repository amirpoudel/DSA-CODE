//
// Created by amir on 1/23/23.
//


//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:

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

    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n = arr.size();
        //vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));

        //return solve(arr,sum,n-1,dp);
        return solveTab(arr,sum,n);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0;
}

// } Driver Code Ends