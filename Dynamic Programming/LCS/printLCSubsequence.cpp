//
// Created by amir on 2/17/23.
//


#include "iostream"
#include "bits/stdc++.h"
using namespace std;



string solve(string &str1,string &str2,int x,int y){
    if(x< 0 or y<0){
        return "";
    }

    if(str1[x]==str2[y]){
        return str1[x]+ solve(str1,str2,x-1,y-1);
    }else{
        string lcs1 = solve(str1,str2,x,y-1);
        string lcs2 = solve(str1,str2,x-1,y);
        return lcs1.size()> lcs2.size()?lcs1:lcs2;
    }
}

string solveTab(string &str1,string &str2){





}

void printLCS(string &str1,string &str2 ){
    int x = str1.size()-1;
    int y = str2.size()-1;

    string ans = solve(str1,str2,x,y);
    reverse(ans.begin(),ans.end());
    cout<<ans;
}


int main(){

    string  str1 = "abcde";
    string str2 =  "abfce";
    vector<char> ans;

    printLCS(str1,str2);

    return 1;
}