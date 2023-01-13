//
// Created by amirp on 12/4/2022.
//

// House Robbery Problem I Code studio

int solve(vector<int>&houses,int n,vector<int>&dp){
    if(n==0){
        return houses[0];
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int include = solve(houses,n-2,dp)+houses[n];
    int exclude = solve(houses,n-1,dp);

    dp[n] = max(include,exclude);
    return dp[n];

}

//Tabulation

int tabulation(vector<int>&houses){
    int n = houses.size();
    vector<int>dp(n,0);

    dp[0] = houses[0];
    if(n==0){
        return dp[0];
    }


    for(int i=1;i<n;i++){
        int include = dp[i-2]+houses[i];
        int exclude = dp[i-1];
        dp[i] = max(include,exclude);

    }
    return dp[n-1];
}

//Space Optimization

int spaceOpti(vector<int>&houses){

    int n = houses.size();
    int prev1 = houses[0];
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int include = prev2+houses[i];
        int exclude = prev1;
        int ans = max(include,exclude);
        prev2 = prev1;
        prev1 = ans;

    }
    return prev1;

}

int maxMoneyLooted(vector<int> &houses, int n)
{
    /*
        Write your code here.
        Don't write main().
         Don't take input, it is passed as function argument.
         Don't print output.
         Taking input and printing output is handled automatically.
    */
    vector<int>dp(n,-1);
    return solve(houses,n-1,dp);
}