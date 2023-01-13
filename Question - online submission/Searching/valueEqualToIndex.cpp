//
// Created by amirp on 10/24/2022.
//
//coding studio - Easy
#include <bits/stdc++.h>
vector<int> valueEqualToIndices(vector<int>& numArray, int n) {
    // Write your code here.

    vector<int> answer;
    bool flag = false;
    for(int i=0;i<n;i++){
        if(numArray[i]==i){
            flag = true;
            answer.push_back(i);
        }
    }
    if(flag==false){
        answer.push_back(-1);
        return answer;
    }

    return answer;

}
