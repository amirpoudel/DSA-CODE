//
// Created by amirp on 11/7/2022.
//
//get min in constant time and space - code studio


#include<bits/stdc++.h>
class SpecialStack {
    // Define the data members.

    stack<int>st;
    int min;


    /*----------------- Public Functions of SpecialStack -----------------*/
public:

    void push(int data) {
        // Implement the push() function.
        //push first Element
        if(st.empty()){
            st.push(data);

            min  = data;
        }else{
            //if data is less than minimum
            if(data<min){
                int val  = 2*data - min;
                st.push(val);
                min = data;
            }else{
                //normal push
                st.push(data);
            }
        }


    }

    int pop() {
        // Implement the pop() function.
        if(st.empty()){
            return -1;
        }

        int curr = st.top();
        st.pop();
        if(curr>min){
            return curr;

        }else{
            int prevMini = min;
            int val = 2*min - curr;
            min = val;
            return prevMini;
        }




    }

    int top() {
        // Implement the top() function.
        if(st.empty()){
            return -1;

        }
        int curr = st.top();
        if(curr<min){
            return min;
        }else{
            return curr;
        }


    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return st.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if(st.empty()){
            return -1;
        }
        return min;
    }
};