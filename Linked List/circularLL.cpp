//
// Created by amir on 7/28/22.
//

// Question - find ll is circular ?

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


void insertion(Node* &tail,int data){
    Node* node = new Node(data);
    tail->nextNode = node;
    tail = tail->nextNode;

}



bool isCircular(Node* &head){
    Node* tempHead = head;
    while(tempHead!=NULL){
        tempHead = tempHead->nextNode;
        if(tempHead->data == head->data){
            return true;
        }
    }
    return false;
}

int main(){

    Node* data = new Node(10);
    Node * tail = data;
    insertion(tail,20);
    insertion(tail,20);
    insertion(tail,30);
    insertion(tail,40);







    return 0;
}