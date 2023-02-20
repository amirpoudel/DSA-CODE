//
// Created by amir on 2/17/23.
//


#include "iostream"
#include "bits/stdc++.h"
using namespace std;

void solve(string &str1,string &str2,int x,int y,string &lcs){
    if(x<0 or y<0){

        return ;
    }

    if(str1[x]==str2[y]){
        lcs.push_back(str1[x]);
        cout<<"Push back "<<str1[x]<<"  "<<str2[y]<<endl;
        solve(str1,str2,x-1,y-1,lcs);
    }else{

        solve(str1,str2,x,y-1,lcs);
        solve(str1,str2,x-1,y,lcs);
    }

}
string printLCS(string &str1,string &str2){

    string lcs;
    int x = str1.size()-1;
    int y = str2.size()-1;
    solve(str1,str2,x,y,lcs);
    return lcs;

}

int main(){

    string  str1 = "abcde";
    string str2 =  "abfce";
    cout<<printLCS(str1,str2);

    return 1;
}