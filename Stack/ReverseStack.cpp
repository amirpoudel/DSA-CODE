//
// Created by amir on 8/10/22.
//

//Reverse Stack Using Recursion

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

void insertAtBottom(Stack* &stack,int data) {
    if (stack->isEmpty()) {
        stack->push(data);
        return;
    }
    int element = stack->peek();
    stack->pop();
    insertAtBottom(stack, data);
    stack->push(element);

}
void reverseStack(Stack* &stack){
    if(stack->isEmpty()){
        return;
    }
    int topElement = stack->peek();
    stack->pop();
    reverseStack(stack);
    insertAtBottom(stack,topElement);

}

int main(){
    Stack* stack = new Stack(5);
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    cout<<stack->peek()<<endl;
    reverseStack(stack);
    cout<<stack->peek();
    return 0;
}
