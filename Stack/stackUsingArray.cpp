//
// Created by amir on 8/8/22.
//

//stack using array

#include "iostream"

using namespace std;
class Stack{
// properties
    int* arr;
    int size;
    int topIndex;
public:
    Stack(int size){
        this->size = size;
        arr = new int[size];
        topIndex = -1;
    }

    //operation

    void push(int data){
        if(topIndex >= size-1){
            cout<<"Stack Is FULL";
            return;
        } else{
            topIndex++;
            arr[topIndex]=data;
        }
    }

    bool isEmpty(){
        if(topIndex==-1){
          return true;
        } else return false;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is Empty";
            return;
        } else{
            topIndex--;
        }
    }

    int peek(){
        return arr[topIndex];
    }




};

int main(){

    Stack stack(5);
    stack.push(2);
    stack.push(2);
    stack.push(12);
    stack.push(13);
    stack.push(14);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();






    cout<<stack.peek()<<endl;
    cout<<stack.isEmpty();

    return 0;
}