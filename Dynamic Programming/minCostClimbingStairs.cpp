//
// Created by amirp on 11/28/2022.
//

// Minimum Cost Climbing Stairs

//Approach -1 Top Down Approch
class Solution {
public:
    int solve(vector<int>&cost,vector<int>&dpArr,int n){
        if(n==0){
            return cost[n];
        }
        if(n<0){
            return 0;
        }
        if(dpArr[n]!=-1){
            return dpArr[n];
        }
        dpArr[n] = min(solve(cost,dpArr,n-1),solve(cost,dpArr,n-2))+cost[n];
        return dpArr[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dpArr(n);
        for(int i=0;i<n;i++){
            dpArr[i]=-1;
        }
        int ans = min(solve(cost,dpArr,n-1),solve(cost,dpArr,n-2));
        return ans;
    }

};

//Approach 2 - Tabulation
