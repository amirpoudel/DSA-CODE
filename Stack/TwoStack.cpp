//
// Created by amir on 8/9/22.
//
// Two stack using single array

#include "iostream"
using namespace std;

class Stack{
    int top1;
    int top2;
    int *arr;
    int size;
public:

    Stack(int size){
        this->size = size;
        this->top1 =-1;
        this->top2 = size;
        this->arr = new int(size);
    }
    void push1(int data){
        if(top1<top2-1){
            top1++;
            arr[top1] = data;
           // cout<<"update";
        } else{
            cout<<"Stack1 OverFlow";
        }
    }
    void push2(int data){
        if(top2>top1+1){
            top2--;
            arr[top2]=data;
        } else{
            cout<<"Stack2 overFlow";
        }
    }

    bool isStack1Empty(){
        if(top1==-1){
            return true;
        } else return false;

    }
    bool isStack2Empty(){
        if(top2==size){
            return true;
        } else return false;
    }

    void pop1(){
        if(isStack1Empty()){
            cout<<"Stack is Empty so cannot perform pop operation";
        } else{
            top1--;
        }
    }
    void pop2(){
        if(isStack2Empty()){
            cout<<"Stack is Empty so cannot perform pop operation";
        }else{
            top2++;
        }
    }

    int peek1(){
        return arr[top1];
    }
    int peek2(){
        return arr[top2];
    }



};

int main(){

    Stack twoStack(5);
    twoStack.push2(1);
    twoStack.push2(12);
    twoStack.push1(13);
    twoStack.push1(41);
    twoStack.push1(51);
    twoStack.pop1();
    cout<<twoStack.peek1();
    twoStack.pop2();
    cout<<endl<<twoStack.peek2();





    return 0;
}