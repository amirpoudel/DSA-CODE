//
// Created by amir on 7/22/22.
//
#include "iostream"
using namespace std;

class Node{
public:
    Node *prevNode;
    int data ;
    Node *nextNode;

    Node(int data){
        this->prevNode=NULL;
        this->data = data;
        this->nextNode = NULL;
    }





};
//insertion at tail
void insertion(Node* &tail,int data){
    Node* node = new Node(data);
    tail->nextNode = node;
    node->prevNode = tail;
    tail = node;

}

//insertion at head

void insertionAtHead(Node* &head,int data) {
    Node *node = new Node(data);
    node->nextNode = head;
    head->prevNode=node;
    head = node;

}

//print from head
void print(Node * &head){
    Node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->nextNode;
    }
}

//print from tail
void printFromTail(Node* &tail){
    Node * temp = tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->prevNode;
    }
}

//get length
int getLength(Node* &head){
    Node*temp = head;
    int length = 0;
    while(temp!=NULL){
        temp=temp->nextNode;
        length++;
    }

    return length;
}




int main(){

    Node* doubleLL = new Node(10);
    Node* head = doubleLL;
    Node* tail = doubleLL;

    insertion(tail,11);
    insertion(tail,12);
    insertion(tail,13);
    insertion(tail,14);
    insertion(tail,15);

    print(head);
    cout<<endl;
    printFromTail(tail);
    cout<<endl;
    cout<<getLength(head);

    cout<<endl<<"Insertion from head and print"<<endl;
    insertionAtHead(head,21);
    insertionAtHead(head,22);
    insertionAtHead(head,23);
    insertionAtHead(head,24);
    insertionAtHead(head,25);
    print(head);
    cout<<endl;
    printFromTail(tail);

    return 1;
}