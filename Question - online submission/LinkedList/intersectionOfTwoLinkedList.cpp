//
// Created by amirp on 11/13/2022.
//
//Intersection of Two Linked List - code Studio


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
int findHeight(Node *head){
    if(head==NULL){
        return 0;
    }
    int height = 0;
    Node *temp = head;
    while(temp!=NULL){
        height++;
        temp = temp->next;
    }
    return height;
}

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    //Finding heights
    int firstHeight = findHeight(firstHead);
    int secondHeight = findHeight(secondHead);

    int diff = abs(firstHeight - secondHeight);

    //Making Height Level Equal

    if(firstHeight>secondHeight){
        for(int i=0;i<diff;i++){
            firstHead = firstHead->next;
        }
    }else if(secondHeight>firstHeight){
        for(int i=0;i<diff;i++){
            secondHead= secondHead->next;
        }
    }



    while(firstHead!=secondHead){
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }
    if(firstHead){
        return firstHead->data;
    }
    return -1;



}