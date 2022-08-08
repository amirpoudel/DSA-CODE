//
// Created by amir on 8/4/22.
//

//Adding Two Numbers in Linked list

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
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data;
        cout<<" , ";
        temp=temp->nextNode;
    }
}

//Adding Two Numbers;

void reverseRecursion(Node* &head, Node* prev,Node * curr){
    if(curr==NULL){
        head = prev;
        return;
    }
    reverseRecursion(head,curr,curr->nextNode);

}

Node* reverse(Node* &head){
    Node * curr = head;
    Node * prev = NULL;
    reverseRecursion(head,prev,curr);
    return head;

}
void insertAtTail(Node* &head,Node*tail,int data){
    Node * temp = new Node(data);
    if(head==NULL){
        head = temp;
        tail = temp;
        return;
    } else{
        tail->nextNode= temp;
        tail= temp;
    }



}
Node* addingTwoNumbers(Node* &head1,Node* &head2){
    //Step one Reverse Linked List
    Node* reverseHead1 = reverse(head1);
    Node* reverseHead2 = reverse(head2);

    //creating Node  for answer
    Node * ansHead=  new Node(0);
    Node * ansTail = ansHead;

    int carry=0;
    while (reverseHead1!=NULL and reverseHead2!=NULL){
        int data1 = reverseHead1->data;
        int data2 = reverseHead2->data;
        int sum = data1+data2+carry;
        int lastDigit = sum%10;
        insertAtTail(ansHead,ansTail,lastDigit);
        carry = sum/10;
        reverseHead1 = reverseHead1->nextNode;
        reverseHead2 = reverseHead1->nextNode;

    }
    while(reverseHead1!=NULL){
        int sum = reverseHead1->data+carry;
        int lastDigit = sum%10;
        insertAtTail(ansHead,ansTail,lastDigit);
        carry = sum/10;
        reverseHead1 = reverseHead1->nextNode;

    }

    while (reverseHead2!=NULL){
        int sum = reverseHead2->data+carry;
        int lastDigit = sum%10;
        insertAtTail(ansHead,ansTail,lastDigit);
        carry = sum/10;
        reverseHead2 = reverseHead2->nextNode;
    }
    while(carry!=0){
        int sum = carry;
        int lastDigit = sum%10;
        insertAtTail(ansHead,ansTail,lastDigit);
        carry = sum/10;
    }
    Node* final = reverse(ansHead);
    return final;

}




int main(){

    Node* data1 = new Node(4);
    Node* tail1 = data1;

    insertion(tail1,5);


    Node* data2 = new Node(3);
    Node* tail2 =  data2;
    insertion(tail2,4);
    insertion(tail2,5);

    Node * result = addingTwoNumbers(data1,data2);
    //print(result);
    cout<<result->data;
    cout<<"Hello world";
    return 0;
}