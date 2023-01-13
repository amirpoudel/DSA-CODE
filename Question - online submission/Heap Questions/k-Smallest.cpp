//
// Created by amir on 12/24/22.
//


#include <bits/stdc++.h>
int kthSmallest(vector<int> input, int k)
{
    // Write your code here.
    //creating map heap priority queue
    priority_queue<int>pq;

    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    //process remaining elements ;
    for(int i=k;i<input.size();i++){
        //if any element less than heap top the pop top and push that element
        if(pq.top()>input[i]){
            pq.pop();
            pq.push(input[i]);
        }
    }
    return pq.top();
}