//
// Created by amir on 1/3/23.
//


// coin change problem GFG solution

//Top Down Approach

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:


    long long int  solve(int coins[],int N,int sum,vector<vector<long long int>>&dp){
        if(sum==0){
            return 1;
        }
        if(sum<0){
            return 0;
        }
        if(N<0){
            return 0;
        }
        if(dp[N][sum]!=-1){
            return dp[N][sum];
        }
        dp[N][sum]  = solve(coins,N,sum-coins[N],dp)+ solve(coins,N-1,sum,dp);

        return dp[N][sum];
    }

    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>>dp(N,vector<long long int>(sum+1,-1));
        return solve(coins,N-1,sum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends