//
// Created by amir on 7/26/22.
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

void insert(Node* &tail,int data){
    Node* node = new Node(data);
    tail->nextNode=node;
    tail=node;

}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data;
        cout<<" , ";
        temp=temp->nextNode;
    }
}
int getLength(Node *&head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp=temp->nextNode;
    }
    return count;
}
int nthPositionData(Node* &head,int position){
    Node* temp = head;
    for(int i=0;i<position-1;i++){
        temp=temp->nextNode;
    }
    return temp->data;
}

int middleData(Node* &head ) {
    int length = getLength(head);
    int middle = (length/2)+1;
    return nthPositionData(head,middle);

}


//optimized code
int optimizedMiddleData(Node* &head){
    Node * temp = head;
    Node * oneStep = temp;
    Node * twoStep = temp->nextNode;
    while(twoStep!=NULL){
        oneStep = temp->nextNode;
        twoStep = twoStep->nextNode;
        temp= temp->nextNode;

    }
    return oneStep->data;
}


int main(){

    Node * data = new Node(10);
    Node*head = data;
    Node* tail = data;
    insert(tail,20);
    insert(tail,30);
    insert(tail,40);
    insert(tail,50);
    insert(tail,60);
    insert(tail,70);
    print(head);
    cout<<endl<<getLength(head)<<endl<<middleData(head);
    cout<<endl<<optimizedMiddleData(head);

}