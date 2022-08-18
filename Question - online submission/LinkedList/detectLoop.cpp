//
// Created by amir on 8/17/22.
//
//detect loop in ll
//leetcode and coding studion submission - Easy and Medium

class Solution {
        public:
        bool hasCycle(ListNode *head) {
            if(head == NULL or head->next==NULL){
                return false;
            }


            ListNode* slow = head;
            ListNode* fast = head;

            while(slow!=NULL and fast!=NULL){
                fast = fast->next;
                if(fast!=NULL){
                    fast = fast->next;
                }


                slow = slow->next;
                if(fast == slow){
                    return true;
                }
            }

            return false;

        }
};