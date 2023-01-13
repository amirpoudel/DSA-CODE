//
// Created by amirpoudel on 12/10/2022.
//

// combination sum iv

#include <bits/stdc++.h>
int solve(vector<int>&num,int tar){
    if(tar==0){
        return 1;
    }
    if(tar<0){
        return 0;
    }
    int ans = 0;
    for(int i=0;i<num.size();i++){
        ans += solve(num,tar-num[i]);
    }
    return ans;
}

int solveMemo(vector<int>&num,int tar,vector<int>&dp){
    if(tar==0){
        return 1;
    }
    if(tar<0){
        return 0;
    }

    int ans = 0;
    if(dp[tar]!=-1){
        return dp[tar];
    }
    for(int i=0;i<num.size();i++){

        ans += solveMemo(num,tar-num[i],dp);

    }
    dp[tar]=ans;
    return dp[tar];
}
int solveTabulation(vector<int>&num,int tar){
    vector<int>dp(tar+1,0);
    dp[0]=1;

    //traversing through 1 to tar
    for(int i=1;i<=tar;i++){
        //traversing through number;
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0){
                dp[i] += dp[i-num[j]];
            }


        }
    }
    return dp[tar];

}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    vector<int>dp(tar+1,-1);
    //return solve(num,tar);
    //return solveMemo(num,tar,dp);
    return solveTabulation(num,tar);
}