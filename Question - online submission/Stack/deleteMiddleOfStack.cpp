//
// Created by amir on 8/18/22.
//
//code studio - Easy
//delete middle of Stack

void deleteElement(stack<int>&inputStack,int count,int position){
    if(count == position){
        inputStack.pop();
        return;
    }

    int element = inputStack.top();
    inputStack.pop();
    deleteElement(inputStack,count+1,position);
    inputStack.push(element);
}

void deleteMiddle(stack<int>&inputStack, int N){

    // Write your code here
    int middle = (N)/2;
    int count=0;
    deleteElement(inputStack,count,middle);


}