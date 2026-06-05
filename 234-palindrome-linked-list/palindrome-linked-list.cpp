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
    bool isPalindrome(ListNode* head) {
      
      //https://chatgpt.com/share/6a226668-fe70-8324-bf01-1afd958e2cbf
      ListNode* slow=head;
      ListNode* fast=head;

     if(head==nullptr || head->next==nullptr)
        return true;

      while(fast!=nullptr && fast->next!=nullptr)
      {
        slow=slow->next;
        fast=fast->next->next;
      }
      // odd length
      if(fast)
        slow = slow->next;


     ListNode* newnode= rever(slow);

     ListNode* ptr1=head;
     ListNode* ptr2=newnode;

     while(ptr2!=nullptr)
     {
        if(ptr1->val!=ptr2->val)return false;

        ptr1=ptr1->next;
        ptr2=ptr2->next;
     }
     return true;
    }

    ListNode* rever(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* next=nullptr;

        while(curr!=nullptr)
        {
            next=curr->next;
            curr->next=prev;

            prev=curr;
            curr=next;
        }
        return prev;
    }
      /* vector<int> v;
       while(head!=nullptr)
       {
        v.push_back(head->val);
        head=head->next;
       }
       int l=0; int r=v.size()-1;
       while(l<r)
       {
        if(v[l]!=v[r])
          return false;
          l++; r--;
       }
       return true; 
       */
    
};