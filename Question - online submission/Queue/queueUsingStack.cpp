//
// Created by amirp on 11/9/2022.
//
//Implementation Queue Using Stack - Two Stack - recursion stack


#include<stack>

void findPeek(stack<int>&st,int&data,int ele=0){
    if(st.empty()){
        data = ele;
        return;
    }
    int top = st.top();
    st.pop();
    findPeek(st,data,top);
    st.push(top);
}

class Queue {
    // Define the data members(if any) here.
    //Define Two Stack
    stack<int>st1;




public:
    Queue() {
        // Initialize your data structure here.


    }




    void enQueue(int val) {
        // Implement the enqueue() function.


        st1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(st1.empty()){
            return -1;
        }

        int top= st1.top();
        st1.pop();
        if(st1.empty()){

            return top;
        }
        int item =  deQueue();
        st1.push(top);
        return item;


    }

    int peek() {
        // Implement the peek() function here.
        if(st1.empty()){
            return -1;
        }

        int data;
        findPeek(st1,data);
        return data;



    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        if(st1.empty()){
            return true;
        }else{
            return false;
        }
    }
};