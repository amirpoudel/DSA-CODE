//
// Created by amir on 8/1/22.
//

// Remove Duplicates From Unsorted LL;

#include "iostream"
#include "map"
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

// remove Duplicate using map



Node * removeDuplicateUsingMap(Node* &head){
//    if(head == NULL){
//        return NULL;
//    }
//    Node* tempHead = head;
//    map<int,bool> visited;
//    Node * prev = NULL;
//    while(tempHead->nextNode!=NULL){
//        int data = tempHead->data;
//       if( (tempHead->nextNode!=NULL) and visited[data]== true) {
//           Node *next= tempHead->nextNode;
//           Node *deleteNode = tempHead;
//           prev->nextNode = next;
//           tempHead = prev;
//           delete (deleteNode);
//
//       }
//       visited[data] = true;
//       prev = tempHead;
//       tempHead = tempHead->nextNode;
//
//    }



//    if(head == NULL){
//        return NULL;
//    }
//    Node* current = head;
//    Node * next = head->nextNode;
//    //Node * prev = NULL;
//    map<int,bool> visited;
//    while(current->nextNode!=NULL){
//        visited[current->data]= true;
//        if((next->nextNode!=NULL) and visited[next->data]== true){
//            Node * delete_node = next;
//            next = next->nextNode;
//            current->nextNode = next;
//
//            delete delete_node;
//        }
//
//        next = next->nextNode;
//        current = current->nextNode;
//    }

//try later on cool head;


    return head;

}


int main(){
    Node * data = new Node(4);
    Node* tail= data;
    insertion(tail,2);
    insertion(tail,5);
    insertion(tail,4);
    insertion(tail,2);
    insertion(tail,2);


    print(data);
    Node * newHead = removeDuplicateUsingMap(data);
    print(newHead);
    return 0;
}