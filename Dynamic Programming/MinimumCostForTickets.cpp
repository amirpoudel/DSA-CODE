//
// Created by amir on 1/3/23.
//
 //Recursion



int solve(int n,vector<int>&days,vector<int>&cost,int index){

    if(index>=n){
        return 0;
    }

    //option 1 case  - 1 day travel

    int option1 = cost[0] + solve(n,days,cost,index+1);

    //option 2 case - 7 day travel - here wecannot do index+7 -
    int i;
    for(i = index ; i<n and days[i]<days[index]+7;i++);

    int option2 = cost[1] + solve(n,days,cost,i);

    // option 3 case - 30 day travel -
    for(i = index ; i<n and days[i]<days[index]+30;i++);
    int option3 = cost[2]+solve(n,days,cost,i);
    return min(option1,min(option2,option3));


}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.

    return solve(n,days,cost,0);
}


// Top Down Approach

int solve(int n,vector<int>&days,vector<int>&cost,int index,vector<int>&dp){

    if(index>=n){
        return 0;
    }

    if(dp[index]!=-1){
        return dp[index];
    }

    //option 1 case  - 1 day travel

    int option1 = cost[0] + solve(n,days,cost,index+1,dp);

    //option 2 case - 7 day travel - here wecannot do index+7 -
    int i;
    for(i = index ; i<n and days[i]<days[index]+7;i++);

    int option2 = cost[1] + solve(n,days,cost,i,dp);

    // option 3 case - 30 day travel -
    for(i = index ; i<n and days[i]<days[index]+30;i++);
    int option3 = cost[2]+solve(n,days,cost,i,dp);
    dp[index] =  min(option1,min(option2,option3));
    return dp[index];

}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    vector<int>dp(n+1,-1);
    return solve(n,days,cost,0,dp);
}

//Tabulation


