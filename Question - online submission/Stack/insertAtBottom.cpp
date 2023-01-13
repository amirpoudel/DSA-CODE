//
// Created by amirp on 11/8/2022.
//

//Insert At Bottom Code - Code Studio

#include <bits/stdc++.h>

void insertAtBottom(stack<int>&myStack,stack<int>&result,int x){
    if(myStack.empty()){
        result.push(x);
        return;
    }
    int top = myStack.top();
    myStack.pop();
    insertAtBottom(myStack,result,x);
    result.push(top);

}

stack<int> pushAtBottom(stack<int>& myStack, int x)
{
    // Write your code here.
    stack<int>result;
    insertAtBottom(myStack,result,x);
    return result;
}

