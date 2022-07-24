//
// Created by amir on 7/22/22.
//
#include "iostream"

using namespace std;



    class Node{
    public:
        int data;
        Node* nextNode;
    public:
      Node(int data){
          this->data=data;
          this->nextNode=NULL;
      }

        void Display(){
            cout<<this->data;
        }


    };


void insertAtHead(Node* &head,int data){
    Node * node = new Node(data);
    node->nextNode = head;
    head = node;
}

void insertAtTail(Node* &tail,int data){
    Node*node = new Node(data);
    tail->nextNode=node;
    tail=tail->nextNode;


}


void insertAtpostion(Node* &head,int position ,int data){
    Node* temp  = head;
    for(int i=1;i<position-1;i++){
        temp = temp->nextNode;
    }
    Node* node = new Node(data);
    Node* nextNode = temp->nextNode->nextNode;
    temp->nextNode=node;
    node->nextNode=nextNode;



}



void print(Node* &head){
    Node* temp  = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->nextNode;
    }
    cout<<endl;
}

void deleteHeadNode(Node* &head){
    Node*temp = head;
    head = temp->nextNode;
    delete temp;
}


void deleteAtAnyPostion(Node* &head,int position){
    if(position==1){
        deleteHeadNode(head);
        return;
    }
    Node* temp = head;
    for(int i=1;i<position-1;i++){
           temp=temp->nextNode;
    }


    Node * next = temp->nextNode->nextNode->nextNode;
    temp->nextNode = next;




}


    int main() {

       Node* node = new Node(200);
       Node* head = node;
       Node* tail = node;
       insertAtHead(head,12);
       insertAtHead(head,13);
       insertAtHead(head,14);
       insertAtHead(head,15);
       insertAtpostion(head,3,500);
       //deleteHeadNode(head);
       deleteAtAnyPostion(head,2);
       print(head);


        insertAtTail(tail,12);
        insertAtTail(tail,13);
        insertAtTail(tail,14);
        insertAtTail(tail,15);
        insertAtTail(tail,16);
        //deleteTailNode(tail);
        print(node);




        return 0;
    }