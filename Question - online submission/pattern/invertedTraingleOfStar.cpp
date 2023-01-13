//
// Created by amir on 1/8/23.
//




#include <bits/stdc++.h>
vector<string> Triangle(int n)
{



    vector<string>ans;
    int size = n*2-1;
    for(int i=0;i<n;i++){
        string star;
        int k = 0;
        while(k<i){
            star+=" ";
            k++;
        }
        for(int j = i;j<size;j++){
            star+="*";
        }
        size--;
        ans.push_back(star);
        star.clear();

    }
    return ans;


}
