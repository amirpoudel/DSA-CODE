//
// Created by amirp on 11/8/2022.
//
//Reverse Stack Using Recursion - code studio



void insertAtBottom(stack<int>&stack,int data){
    if(stack.empty()){
        stack.push(data);
        return;
    }
    int top = stack.top();
    stack.pop();
    insertAtBottom(stack,data);
    stack.push(top);
}

void reverse(stack<int>&stack){
    if(stack.empty()){
        return;
    }
    int top = stack.top();
    stack.pop();
    reverse(stack);
    insertAtBottom(stack,top);
}

void reverseStack(stack<int> &stack) {
    // Write your code here

    reverse(stack);

}