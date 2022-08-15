//
// Created by amir on 8/15/22.
//

// Reverse first K Element of Queue


#include "iostream"
#include "queue"
#include "stack"
using namespace std;


void reverseKElementQueue(queue<int>* &q,int k){

    //create stack
    stack<int> stack;
    //fetch from queue and push k element in stack
    for(int i=0;i<k;i++){
        int data = q->back();
        q->pop();
        stack.push(data);
    }

    //fetch from stack in insert in queue
    while(!stack.empty()){
        int data =  stack.top();
        stack.pop();
        q->push(data);
    }

    //fetch (n-K) element from queue and pushback in that queue

    int t = q->size()-k;
    while(t--){
        int val = q->front();
        q->pop();
        q->push(val);
    }

}


int main(){

    queue<int>* q = new queue<int> ;
    q->push(1);
    q->push(2);
    q->push(3);
    q->push(4);
    q->push(5);

    cout<<endl<<q->front();
    cout<<endl<<q->back();
    reverseKElementQueue(q,2);

    cout<<endl<<q->front();

    cout<<endl<<q->back();



    return 0;
}