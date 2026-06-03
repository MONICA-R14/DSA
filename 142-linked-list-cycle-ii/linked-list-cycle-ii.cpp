/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //must ref striver video 14.00 to understand why fast moves 2 steps not(3 or 4) must see

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast) //ref striver like after how much time they will meet 14.00 
            {
               //cycle found
               //ref how this inside happens must see in chat link given  below
              //  https://chatgpt.com/share/6a1fc260-9d7c-8321-b894-0d73d90ba1fe
                 ListNode* ptr=head;
                 while(ptr!=slow)
                 {
                    ptr=ptr->next;
                    slow=slow->next;
                    //slow and ptr takes exacly a steps to reach start of cycle , how?? ref above chat link donkey
                 }
                 return ptr;
            }

        }
        return nullptr;
        
    }
};