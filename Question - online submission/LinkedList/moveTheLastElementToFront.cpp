//
// Created by amirp on 11/12/2022.
//

// Move the last element to front in a linked list;


#include <bits/stdc++.h>
/****************************************************************
Following is the Linked list node structure already written

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data)
    {
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/


LinkedListNode<int>* moveToFront(LinkedListNode<int> *head) {

    /*
     Don't write main().
     Don't read input, it is passed as function argument.
     Write your code here.
    */
    if(head == NULL or head->next==NULL){
        return head;
    }

    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int>*curr = head;

    while(curr->next!=NULL){
        prev = curr;
        curr = curr->next;
    }
    curr->next = head;
    prev->next  = NULL;
    return curr;




}