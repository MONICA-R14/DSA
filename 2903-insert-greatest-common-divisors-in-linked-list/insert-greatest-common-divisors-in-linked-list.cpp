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
      static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* next=head->next;
        ListNode* curr=head;
        while(next!=nullptr)
        {
            int val=gcd(curr->val,next->val);
            ListNode* newnode =new ListNode(val);
            newnode->next=curr->next;
            curr->next=newnode;
           curr=newnode->next;
           next=curr->next;
        }
        return head;
    }
};