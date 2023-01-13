//
// Created by amirp on 12/4/2022.
//

//House Robbery II Code Studio

#include <bits/stdc++.h>
int solve(vector<int>&houses){

    int n = houses.size();
    int prev1 = houses[0];
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int include = prev2+houses[i];
        int exclude = prev1+0;
        int ans = max(include,exclude);
        prev2 = prev1;
        prev1 = ans;

    }
    return prev1;

}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();

    if(n==1){
        return valueInHouse[0];
    }
    vector<int>first,second;


    for(int i=0;i<n;i++){
        if(i!=n-1){
            first.push_back(valueInHouse[i]);
        }
        if(i!=0){
            second.push_back(valueInHouse[i]);
        }
    }
    long long int ans =  max(solve(first),solve(second));
    return ans;
}
