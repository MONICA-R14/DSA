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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        vector<int>arr; 
        while(temp!=nullptr)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
         //to access arr2[x] in vector arr2 to access specific index value , we must declare it with total size else we cant access specific index 
        vector<int>arr2(n);
        for(int i=0;i<n;i++)
        {
            int x=(i+k)%n;
            //to access arr2[x] in vector arr2 to access specific index value , we must declare it with total size else we cant access specific index 
            arr2[x]=arr[i];
        }

        temp=head; int i=0;
        while(temp!=nullptr)
        {
            temp->val=arr2[i];
            temp=temp->next;
            i++;
        }

        return head;
    }
};