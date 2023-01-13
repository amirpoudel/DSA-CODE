//
// Created by amir on 9/9/22.
//


#include <bits/stdc++.h>
int findKthLargest(vector<int>& nums, int k) {

    // Write your code here
    priority_queue<int,vector<int>,greater<int> >pq;
    //insert first k element in k;
    for(int i=0;i<k;i++){
        pq.push(nums[i]);
    }
    //process remaining element;
    for(int i=k;i<nums.size();i++){
        //if element is larger then pop and push
        if(pq.top()<nums[i]){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();


}