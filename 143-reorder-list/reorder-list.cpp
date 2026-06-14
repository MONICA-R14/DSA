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
    void reorderList(ListNode* head) {
        queue<ListNode*>q;
        stack<ListNode*>st;

        ListNode* slow=head; ListNode* fast=head;
        while(fast&& fast->next)
        {
             q.push(slow);
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast==nullptr){  //if fast==nullptr then fast->next->next==nullptr then n=even so no need to push slow to queue
        }
         else //if fast->next is null then n=odd so  need to push slow to queue
        {
            q.push(slow);
            slow=slow->next;
        }
        while(slow!=nullptr)
        {
            st.push(slow);
            slow=slow->next;
        }

        ListNode* dummy=new ListNode(-1);
       // dummy->next=head;
        ListNode* curr=dummy;
        while(!q.empty() && !st.empty())
        {
            ListNode* left=q.front();
            q.pop();

            ListNode* right=st.top();
            st.pop();

            curr->next=left;
            curr=curr->next;
          // if(left==right) break;
            curr->next=right;
            curr=curr->next;//move curr to right's position for next iteration
        }
        //for n= odd length
        while(!q.empty())
        {
            ListNode* left=q.front();
            q.pop();
            curr->next=left;
            curr=curr->next;
        }
        curr->next=nullptr;

      }
    
};