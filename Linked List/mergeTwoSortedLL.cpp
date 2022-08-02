//
// Created by amir on 8/2/22.
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

Node* mergeTwoSortedLL(Node* &head1,Node* &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
       return head1;

    }

    Node* current = head1->nextNode;
    Node* prev = head1;

    Node*temp = head2;
    while(current!=NULL and temp!=NULL){
        if(temp->data>=prev->data and temp->data<=current->data){
            Node* tempCurr = current;
            Node* temphead2Next = temp->nextNode;
            prev->nextNode = temp;
            temp->nextNode = tempCurr;
            prev = prev->nextNode;
            temp = temphead2Next;

        } else{
            current= current->nextNode;
            prev= prev->nextNode;
        }
    }

    return head1;
}

int main(){

    Node* head1 = new Node(1);
    Node* tailHead1 = head1;
    insertion(tailHead1,4);
    insertion(tailHead1,4);
    insertion(tailHead1,5);
    Node * head2 = new Node(2);
    Node* tailHead2 = head2;
    insertion(tailHead2,2);
    insertion(tailHead2,3);
    insertion(tailHead2,3);
    insertion(tailHead2,5);

    Node * merged = mergeTwoSortedLL(head1,head2);

   print(merged);

    return 1;
}
