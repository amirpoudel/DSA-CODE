//
// Created by amir on 7/27/22.
//
#include "iostream"

using namespace std;

class Node{
public:
    int data;
    Node* nextNode;
    Node(int data){
        this->data=data;
        this->nextNode=NULL;
    }
};


void insertion(Node* &tail , int data){
    Node* node = new Node(data);
    tail->nextNode = node;
    tail = tail->nextNode;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->nextNode;
    }
    cout<<endl;

}





Node*  reverseLLKGroup(Node* &head,int k){
    //base case
    if(head==NULL){
        return NULL;
    }
    // reverse k node ;

    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    int count = 0;
    while(curr !=NULL and count<k){
        forward = curr->nextNode;
        curr->nextNode = prev;

        prev = curr;
        curr = forward;
        count++;
    }


    // call recursion for left part
    if(forward!=NULL){
        head->nextNode = reverseLLKGroup(forward,k);
    }

    return prev;



}


int main(){

    Node * data = new Node(10);
    Node* tail = data;
    insertion(tail,20);
    insertion(tail,40);
    insertion(tail,60);
    insertion(tail,80);
    print(data);

    Node*reverse = reverseLLKGroup(data,2);
    print(reverse);


    return 0;
}