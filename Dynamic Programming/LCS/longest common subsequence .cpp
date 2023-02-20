//
// Created by amir on 2/11/23.
//


#include <bits/stdc++.h>

int solve(string &str1,string &str2,int s1,int s2, vector<vector<int>>&dp){
    if(s1==0 or s2==0){
        return 0;
    }

    if(dp[s1-1][s2-1]!=-1){
        return dp[s1-1][s2-1];
    }

    if(str1[s1-1]==str2[s2-1]){
        return dp[s1-1][s2-1] = 1+solve(str1,str2,s1-1,s2-1,dp);
    }else{
        //we have two choice
        return dp[s1-1][s2-1] =  max(solve(str1,str2,s1,s2-1,dp),solve(str1,str2,s1-1,s2,dp));
    }

}


int solveTabulation(string &str1,string &str2,int s1,int s2){

    vector<vector<int>>dp(s1+1,vector<int>(s2+1,0));

    for(int i=1;i<=s1;i++){
        for(int j=1;j<=s2;j++){

            //check
            if(str1[i-1]==str2[j-1]){
                //matching case
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                //no matching case
                dp[i][j] = max( dp[i][j-1],dp[i-1][j]);

            }


        }
    }
    return dp[s1][s2];

}

int getLengthOfLCS(string & str1, string & str2) {
    // Write your code here.
    int s1 = str1.size();
    int s2 = str2.size();
    if(s1==0 or s2==0){
        return 0;
    }
    //vector<vector<int>>dp(s1+1,vector<int>(s2+1,-1));
    //return solve(str1,str2,s1,s2,dp);
    return solveTabulation(str1,str2,s1,s2);
}