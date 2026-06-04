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
        
        ListNode* temp=head;
     
      
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

    }
};