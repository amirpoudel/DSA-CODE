//
// Created by amir on 8/16/22.
//
//Leet code
//Question   -25. Reverse Nodes in k-Group
//Hard

//Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
//
//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
//
//You may not alter the values in the list's nodes, only nodes themselves may be changed.
class Solution {

    bool isCompleteNode(ListNode* head,int k){

        if(head==NULL){
            return false;
        }

        for(int i=0;i<k;i++){
            if(head==NULL){
                return false;
            }
            head=head->next;
        }

        return true;

    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        // base case

        if(head==NULL){
            return NULL;
        }

        //reverse first k group list

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int count = 0;



        if(isCompleteNode(head,k)){
            while(curr!=NULL and count<k){
                next = curr->next;
                curr->next = prev;

                prev = curr;
                curr = next;
                count++;
            }
        }else{
            prev = curr;
            curr = next;
            count++;
        }

        //left part
        if(next!=NULL){
            head->next = reverseKGroup(next,k);
        }

        return prev;


    }
};