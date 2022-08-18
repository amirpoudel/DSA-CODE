//
// Created by amir on 8/17/22.
//


//loop node

//LeetCode and Code Studio - Medium;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

    ListNode *meetingPoint(ListNode*head){

        if(head == NULL ){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(slow!=NULL and fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;

            }
            slow = slow->next;
            if(slow == fast){
                return slow;
            }
        }

        return NULL;

    }



public:
    ListNode *detectCycle(ListNode *head) {

        if(head == NULL or head->next==NULL){
            return NULL;
        }


        ListNode* fast = meetingPoint(head);


        ListNode* slow = head;

        while(slow!=NULL){

            if(slow==fast){
                return slow;
            }
            slow = slow->next;
            if(fast==NULL){
                return NULL;
            }
            fast = fast->next;
        }

        return NULL;




    }
};