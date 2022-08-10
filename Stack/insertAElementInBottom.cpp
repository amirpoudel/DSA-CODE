//
// Created by amir on 8/10/22.
//

//Insert A Element At its Bottom in a given stack;


#include "iostream"

using namespace std;

class Stack{
    int* data;
    int top;
    int size;
public:

    Stack(int size){
        this->size = size;
        this->data = new int(size);
        this->top = -1;
    }

    void push(int data){
        if(top<size-1){
            top++;
            this->data[top] = data;
        }else{
            cout<<"Stack is full";
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        } else return false;

    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is Empty";
            return;
        }else{
            top--;
        }
    }

    int peek(){
        if(isEmpty()){
            return NULL;
        }else return data[top];
    }



};


void insertAtBottom(Stack* &stack,int data){
    if(stack->isEmpty()){
        stack->push(data);
        return;
    }
    int element = stack->peek();
    stack->pop();
    insertAtBottom(stack,data);
    stack->push(element);

}

int main(){
    Stack* stack = new Stack(10);
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    cout<<stack->peek();
    insertAtBottom(stack,6);
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();

    cout<<endl<<stack->peek();



    return 0;
}