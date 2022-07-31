//
// Created by amir on 7/28/22.
//
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

//detect loop through brute force approach

bool detectLoop(Node* head){
    Node* tempHead = head;
    if(head==NULL){
        return false;
    }
    map<Node*,bool> visited;
    while(tempHead!=NULL){
        //cycle is present
        if(visited[tempHead]== true){
            return true;
        }
        visited[tempHead]= true;
        tempHead=tempHead->nextNode;
    }

    return false;
}


//floyds loop detection algorithm
Node* floydsLoopDetect(Node* head){
    if(head == NULL){
        return NULL;
    }


    Node* slow = head;
    Node* fast = head;
    while(slow!=NULL and fast!=NULL){
        fast = fast->nextNode;
        if(fast!=NULL){
            fast = fast->nextNode;
        }
        slow=slow->nextNode;
        if(slow==fast){
            return slow;
        }


    }
    return NULL;
}

//get a starting node of loop

Node* getLoopNode(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* intersectionPoint = floydsLoopDetect(head);
    Node * slow = head;
    //here we use intersectionPoint as fast pointer
    while(slow!=NULL){
        if(slow==intersectionPoint){
            return slow;
        }
        slow=slow->nextNode;
        intersectionPoint = intersectionPoint->nextNode;

    }
    return NULL;

}

//function for creating a loop
void createLoop(Node* headNode,Node* &tail,int postion){
    Node * temphead =headNode;
    for(int i=0;i<postion;i++){
        temphead = temphead->nextNode;
    }
    tail->nextNode = temphead;
}

//function for remove a loop

void removeLoop(Node*&head,Node* &loopNode){
    Node * temp = head;
    while(temp!=loopNode){
        temp=temp->nextNode;
    }
    if(temp==loopNode){
        loopNode->nextNode=NULL;
    }

}

int main(){


    Node * data = new Node(10);
    Node* tail= data;
    insertion(tail,12);
    insertion(tail,13);
    insertion(tail,14);
    insertion(tail,15);
    insertion(tail,16);
    insertion(tail,17);
    insertion(tail,18);
    insertion(tail,19);
    insertion(tail,20);
    insertion(tail,21);
    insertion(tail,22);
    insertion(tail,23);
    insertion(tail,24);

    createLoop(data,tail,9);
    //tail->nextNode = data;

   // cout<<detectLoop(data);
    Node*loop = getLoopNode(data);
    cout<<loop->data;
    removeLoop(data,loop);
    cout<<endl<<detectLoop(data);
    return 1;
}