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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       //https://www.youtube.com/watch?v=RF_M9tX4Eag
        ListNode* dummy=new ListNode(0,head);

        ListNode* curr=head; ListNode* leftprev=dummy;

        for(int i=0;i<left-1;i++)
        {
            leftprev=curr; //at last it stores node-1 see eg in description
            curr=curr->next;
        }
        //reverse from l to r
        ListNode* prev=nullptr;  ListNode* next;
        for(int i=0;i<right-left+1;i++) // from 2 to 4 (3 nodes so 4-2+1=3 correct)
        {
            next=curr->next;
            curr->next=prev;

            prev=curr;//at last prev=4
            curr=next;//at last curr=5 and loop breaks 
        }

        leftprev->next->next=curr;// 2-pointing to 5 in eg in description
        leftprev->next=prev;
        return dummy->next;
  
    }
};