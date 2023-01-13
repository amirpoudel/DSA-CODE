//
// Created by amirp on 11/28/2022.
//

// Count Ways To Climbing Stairs

//top down approach -

#include <bits/stdc++.h>
#define MOD 1000000007
// TOP DOWN APPROACH
int countWays(int n,vector<int>&dpArr){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dpArr[n]!=-1){
        return dpArr[n];
    }
    dpArr[n] = ( countWays(n-1,dpArr)+countWays(n-2,dpArr))%MOD;
    return dpArr[n];
}




int countDistinctWays(int nStairs) {
    //  Write your code here.
    vector<int>dpArr(nStairs+1);
    for(int i=0;i<=nStairs;i++){
        dpArr[i]=-1;
    }
    return countWays(nStairs,dpArr);
}


//BUTTOM UP APPROACH - Tabulation

class Solution {
public:
    int solve(vector<int>&cost,int n){

        vector<int>dpArr(n);

        dpArr[0] = cost[0];
        dpArr[1] = cost[1];
        for(int i=2;i<n;i++){
            dpArr[i] = min(dpArr[i-1],dpArr[i-2])+cost[i];
        }


        return min(dpArr[n-1],dpArr[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();


        int ans = solve(cost,n);
        return ans;
    }

};

// Space Optimization

class Solution {
public:
    int solve(vector<int>&cost,int n){



        int prev2 = cost[0];
        int prev1 = cost[1];
        for(int i=2;i<n;i++){
            int curr = min(prev2,prev1)+cost[i];
            prev2 = prev1;
            prev1 = curr;

        }
        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();


        int ans = solve(cost,n);
        return ans;
    }

};
