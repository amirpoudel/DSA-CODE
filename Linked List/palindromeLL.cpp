//
// Created by amir on 8/3/22.
//

// Check LL is Palindrome or not

#include "iostream"

#include "vector"
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

//Approach #1 - convert ll to array and perform palidrome logic on array

//bool isPalindrome(Node* head){
//    if(head==NULL){
//        return NULL;
//    }
//    //creating array using vector
//    vector<int> arr;
//    Node * tempHead = head;
//    int count=0;
//
//    //copy value of LL to arr
//    while(tempHead!=NULL){
//        int data = tempHead->data;
//        arr.push_back(data);
//        count++;
//        tempHead = tempHead->nextNode;
//    }
//
//    //write palidrome to logic to array
//    int start = 0;
//    int end = arr.size()-1;
//    while(start<=end){
//        if(start != end){
//            return false;
//        }
//        start++;
//        end--;
//    }
//
//    return true;
//
//}

// Approach #2 without creating another arr using linked list time- O(N) space O(1);

Node * findMiddle(Node *  head){
    Node * tempHead = head;
    Node * fast = head;
    Node * slow = head;
    while(fast!=NULL){
        fast = fast->nextNode->nextNode;
        if(fast==NULL){
            return slow;
        }
        slow = slow->nextNode;
    }
    return slow;
}

void reverseRecursion(Node* &head,Node * prev,Node* curr){
    if(curr==NULL){
        head = prev;
        return;
    }
    reverseRecursion(head,curr,curr->nextNode);

}

Node * reverse(Node* &head){
    Node * prev = NULL;
    Node * curr = head;

    reverseRecursion(head,prev,curr);
    return head;
}

bool isPalindrome(Node * head){
    //find middle Node
    Node* middleNode = findMiddle(head);
    //Reverse LL From middle Node
    Node * reverseLL = reverse(middleNode->nextNode);
   // compare LL of 2 part

   Node* tempHead = head;
   Node* tempReverse = reverseLL;

   while(tempReverse!=NULL){
       if(tempHead->data != tempReverse->data){
           return false;
       }
       tempHead = tempHead->nextNode;
       tempReverse = tempReverse->nextNode;

   }



    return true;
}




int main(){

    Node* data = new Node(10);
    Node*tail = data;
//    insertion(tail,2);
//    insertion(tail,3);
//    insertion(tail,3);
//    insertion(tail,2);
//    insertion(tail,1);
    insertion(tail,20);
    insertion(tail,30);
    insertion(tail,40);
    insertion(tail,50);
    insertion(tail,50);
    insertion(tail,40);
    insertion(tail,30);
    insertion(tail,20);
    insertion(tail,10);


   // print(data);

    cout<<isPalindrome(data);

    return 0;
}