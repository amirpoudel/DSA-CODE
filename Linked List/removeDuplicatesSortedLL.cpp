//
// Created by amir on 8/1/22.
//
// Remove Duplicates From Sorted Linked List


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


// Remove Duplicates

Node* removeDuplicates(Node* &head){
    Node* tempHead = head;
    if(head == NULL){
        return NULL;
    }

    while(tempHead->nextNode!=NULL){
        if(tempHead->data == tempHead->nextNode->data){

            Node * next_Node = tempHead->nextNode->nextNode;
            Node * delete_Node = tempHead->nextNode;
            delete(delete_Node);
            tempHead->nextNode = next_Node;



        }else{
            tempHead = tempHead->nextNode;
        }


    }

    return head;

}

// print linked list

void print(Node* &head){
    Node* temp  = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->nextNode;
    }
    cout<<endl;
}

int main(){

    Node * data = new Node(10);
    Node* tail= data;
    insertion(tail,12);
    insertion(tail,12);
    insertion(tail,12);
    insertion(tail,15);
    insertion(tail,15);
    insertion(tail,15);
    insertion(tail,15);
    insertion(tail,19);
    insertion(tail,20);
    insertion(tail,20);
    insertion(tail,20);
    insertion(tail,20);
    insertion(tail,24);

    print(data);
    Node * head = removeDuplicates(data);
    print(head);

    return 1;
}