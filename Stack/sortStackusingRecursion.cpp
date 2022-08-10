//
// Created by amir on 8/10/22.
//
//Sort Stack Using Recursion
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
void insertInSortedWay(Stack* &stack,int element){
    if(stack->isEmpty() or (!stack->isEmpty()) and stack->peek()<element){
        stack->push(element);
        return;
    }
    int topElement = stack->peek();
    stack->pop();
    insertInSortedWay(stack,element);
    stack->push(topElement);
}
void sortStack(Stack* &stack){
    if(stack->isEmpty()){
        return;
    }
    int element = stack->peek();
    stack->pop();
    sortStack(stack);
    insertInSortedWay(stack,element);

}


int main(){
    Stack* stack = new Stack(5);
    stack->push(5);
    stack->push(4);
    stack->push(3);
    stack->push(2);
    stack->push(1);
    cout<<stack->peek()<<endl;
    sortStack(stack);
    cout<<stack->peek();
    return 0;
}
