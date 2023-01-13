//
// Created by amirp on 11/10/2022.
//

//InterLeave the first half or the queue with second half - code studio


#include <bits/stdc++.h>
void interLeaveQueue(queue < int > & q) {
    // Write your code here.

    //creating new queue and push all 0-middle element in new queue;

    queue<int>newQueue;
    int middle = q.size()/2;
    for(int i=0;i<middle;i++){
        newQueue.push(q.front());
        q.pop();
    }
    //now push new queue element in queue and queue element in queue one by one;
    while(!newQueue.empty()){
        q.push(newQueue.front());
        newQueue.pop();
        q.push(q.front());
        q.pop();
    }


}