//
// Created by amirp on 11/12/2022.
//

//Remove Duplicate From Unsorted Linked List - code studio - Medium



#include <bits/stdc++.h>
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    // Write your code here
    unordered_map<int,bool>isPresent;

    Node*curr = head;
    Node*prev=NULL;


    while(curr!=NULL){

        if(isPresent[curr->data]){
            prev->next =curr->next;
            curr->data = NULL;
        }else{
            isPresent[curr->data]=true;
            prev = curr;

        }

        curr = curr->next;


    }
    return head;
}