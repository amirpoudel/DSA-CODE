//
// Created by amir on 8/2/22.
//
//sort ll 0,1,2;

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

void print(Node* &head){
    Node* temp  = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->nextNode;
    }
    cout<<endl;
}

 void sortLinkedList(Node * &head){
    //traverse linked list to found zero one and two
    int zeroCount=0;
    int oneCount=0;
    int twoCount=0;
    Node* tempHead = head;
    while(tempHead!=NULL){
        if(tempHead->data==0){
            zeroCount++;
        }
        if(tempHead->data==1){
            oneCount++;
        }
        if(tempHead->data=2){
            twoCount++;
            }
        tempHead = tempHead->nextNode;
    }


    //now change data in linked list

    tempHead = head;

    while(tempHead!=NULL){
        if(zeroCount!=0){
            tempHead->data = 0;
            zeroCount--;
            tempHead=tempHead->nextNode;
        } else if(oneCount!=0){
            tempHead->data = 1;
            oneCount--;
            tempHead=tempHead->nextNode;
        } else if(twoCount!=0){
            tempHead->data = 2;
            twoCount--;
            tempHead=tempHead->nextNode;
        }
    }



}


int main(){
    Node * data = new Node(1);
    Node * tail = data;
    insertion(tail,0);
    insertion(tail,0);
    insertion(tail,0);
    insertion(tail,2);
    insertion(tail,2);
    insertion(tail,1);
    insertion(tail,1);
    insertion(tail,1);
    insertion(tail,1);
    insertion(tail,2);
    insertion(tail,2);
    insertion(tail,2);
    insertion(tail,2);
    print(data);
    cout<<endl;
    sortLinkedList(data);
    print(data);
}