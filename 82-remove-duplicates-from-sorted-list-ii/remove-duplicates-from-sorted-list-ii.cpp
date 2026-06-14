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
        
      ListNode* temp=head;
      ListNode* dummy=new ListNode(-1);
      ListNode* prev=dummy;
      dummy->next=head;
      ListNode* curr=nullptr;
      

      while(temp && temp->next!=nullptr)
      {
       
        int a=0;
        if(temp->val==temp->next->val)
        {
           int dup=temp->val;
           curr=temp->next; //or temp
           while(curr && curr->val==dup)
           {
            curr=curr->next;
           }
           prev->next=curr; 
           temp=curr;
           a=1; 
        }
       if(a==0) 
       {
        prev=prev->next;
        temp=temp->next;
       }
      }
      return dummy->next;
    }
};