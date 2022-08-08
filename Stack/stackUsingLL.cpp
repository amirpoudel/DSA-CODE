//
// Created by amir on 8/8/22.
//

// Stack Using LL

#include "iostream"

using namespace std;

//creating Linked List Node
class Node{
public:
    int data;
    Node* nextNode;

public:
    Node(int data){
        this->data = data;
        this->nextNode = NULL;
    }

};



// creating Stack

class Stack{
    Node* top = NULL;
    int size ;
    int count;
public:
    Stack(int size){
        this->size = size;
        this->count = -1;
    }

    bool isEmpty(){
        if(top==NULL){
            return true;
        } else return false;
    }
    bool isFull(){
        if(count>=size-1){
            return true;
        } else return false;
    }
    void push(int data){
        if(count<size-1){
            Node* node = new Node(data);
            node->nextNode = top;
            top = node;
            count++;
        } else{
            cout<<"Stack Is Full";
        }

    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack Is Empty";
        } else{
            Node * temp = top;
            cout<<endl<< temp->data;
            top  = top->nextNode;
            cout<<endl<<top->data;
            count--;
            delete(temp);
        }
    }

    int peek(){
        return top->data;
    }

};


int main(){
    Stack stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
   // cout<<stack.peek();
    stack.pop();
    stack.pop();
    stack.pop();
   // cout<<stack.peek();
    //cout<<stack.isFull();



    return 0;
}