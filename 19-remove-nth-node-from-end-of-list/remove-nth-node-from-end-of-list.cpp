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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //https://chatgpt.com/share/6a21a82d-4154-8324-9a90-daede4e672af
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
         ListNode* slow=dummy;
         ListNode*fast=dummy;
         

         for(int i=0;i<n;i++)
            fast=fast->next; //fast will be at nth node from start eg:2nd position

        while(fast->next!=nullptr) 
        {
            //fast is at 2 , slow is at 0  diff 2-0=2
            // so when fast->next reaches end slow->next will be at 2 steps behind end , so after loop delete node after slow->next , bcz slow->next is exactly at 2 (n) steps from end 
            // since diff bwt them is 2
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;

        return dummy->next;

       /* ListNode* temp=head;
     
      
        int count=0;

        while(temp!=nullptr)//bcz we need to count so go till last
        {
             count++;
            temp=temp->next;
           
        }
        int x=count-n; 
        //if n=count then need to remove 1st element alone
        if(count==n) return head->next; 

       temp=head;
       for(int i=1;i<x;i++)
       {
         temp=temp->next;
       }
     
            temp->next=temp->next->next;

       return head;
       */

    }
};