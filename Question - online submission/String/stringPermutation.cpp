//
// Created by amir on 1/4/23.
//


#include<bits/stdc++.h>

void solve(string &str,vector<string>&ans,int index){
    if(index>=str.size()){
        ans.push_back(str);
        return;
    }
    for(int i = index ; i<str.size();i++){
        swap(str[index],str[i]);
        solve(str,ans,index+1);
        swap(str[index],str[i]);
    }
}

vector<string> generatePermutations(string &str)
{
    // write your code here
    vector<string>ans;
    solve(str,ans,0);
    sort(ans.begin(),ans.end());
    return ans;
}