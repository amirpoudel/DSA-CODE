//
// Created by amir on 8/17/22.
//
//

//Remove duplicates from sorted Linked List
//Leet Code and Coding Studio - Easy

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {


        if(head==NULL or head->next==NULL){
            return head;
        }

        ListNode* tempHead = head;

        while(tempHead->next!=NULL){

            if(tempHead->val == tempHead->next->val){
                ListNode* nextNode = tempHead->next->next;
                ListNode* deleteNode = tempHead->next;
                delete (deleteNode);
                tempHead->next = nextNode;
            }else{
                tempHead=tempHead->next;
            }

        }

        return head;

    }
};