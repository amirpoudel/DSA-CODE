//
// Created by amir on 8/9/22.
//


#include "iostream"

using namespace std;

class Stack{
    char* data;
    int top;
    int size;
public:

    Stack(int size){
        this->size = size;
        this->data = new char(size);
        this->top = -1;
    }

    void push(char data){
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
        }else{
            top--;
        }
    }

    char peek(){
        if(isEmpty()){
            return NULL;
        }else return data[top];
    }



};

int main(){
    string input = "hello";
    Stack stack(5);
    stack.push('h');
    stack.push('e');
    stack.push('l');
    stack.push('l');
    stack.push('o');


    string result="";

    result.push_back(stack.peek());
    stack.pop();
    result.push_back(stack.peek());
    stack.pop();
    result.push_back(stack.peek());
    stack.pop();
    result.push_back(stack.peek());
    stack.pop();
    result.push_back(stack.peek());
    cout<<result;


    return 0;
}
