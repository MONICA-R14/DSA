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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
          ListNode* t1=list1;
          for(int i=0;i<a-1;i++)
          {
            t1=t1->next;
          }
          ListNode* z=t1->next;
          for(int i=0;i<b-a+1;i++)
          {
             z=z->next;
          }
            t1->next=list2;
          while(list2->next)
          {
              list2=list2->next;
          }
          list2->next=z;
          return list1;
    }
};