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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) 
            return head;

        ListNode* odd=head;  //ref striver
        ListNode* even=head->next; ListNode* evenhead=head->next;

        while(even!=nullptr && even->next!=nullptr)
        {
            //to assign values to odd and even ptr
            odd->next=odd->next->next;
            even->next=even->next->next;

            //to move ptr to next value
            odd=odd->next;
            even=even->next;
        }
        //to combine odd's end with even's starting index
        odd->next=evenhead;

        return head;

    }
};