//
// Created by amir on 7/26/22.
//
//Question - Reversed Linked List
#include "iostream"

using namespace std;

class Node{
public:
    int data;
    Node* nextNode;

    Node(int data){
        this->data= data;
        this->nextNode= nextNode;
    }

};

void insert(Node* &tailNode,int data){
    Node* node = new Node(data);
    tailNode->nextNode=node;
    tailNode=tailNode->nextNode;
}

void print(Node* &headNode){
    Node* temp = headNode;
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->nextNode;
        cout<<" ";
    }



}


// Approach 1 - delete current connect and make new connection in reverse way

void reverseLLRecursion(Node* &head,Node* curr,Node* prev){
    if(curr==NULL){
        head = prev;
        return;
    }
    reverseLLRecursion(head,curr->nextNode,curr);
    curr->nextNode=prev;


}

void reverseLL(Node* &head){
//    Node* tempNode = head->nextNode;
//    head = tempNode;
//    if(head==NULL){
//        return;
//    }
//
//    tempNode->nextNode=head;
////    head->nextNode=NULL;
//    reverseLL(tempNode);

     Node* prevNode = NULL;
     Node * currNode = head;
     Node* forwardNode =NULL;
//     while(currNode!=NULL){
//         forwardNode = currNode->nextNode;
//         currNode->nextNode=prevNode;
//         prevNode = currNode;
//         currNode = forwardNode;
//
//     }
    reverseLLRecursion(head,currNode,prevNode);
    //head = prevNode;


}




int main(){

    Node* data = new Node(10);
    Node* headNode = data;
    Node* tail = data;
    insert(tail,20);
    insert(tail,30);
    insert(tail,40);
    insert(tail,50);
    insert(tail,60);
    insert(tail,70);
    print(headNode);
    cout<<endl;
    reverseLL(headNode);
    print(headNode);



    return 0;
}