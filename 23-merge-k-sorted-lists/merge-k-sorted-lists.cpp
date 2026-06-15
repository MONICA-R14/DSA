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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //ref striver  https://www.youtube.com/watch?v=1zktEppsdig
        //for priority queue syntax      https://claude.ai/share/e3d77ece-d301-470b-a634-bb11330dd646

        priority_queue <  pair<int,ListNode*>,
                          vector<pair<int,ListNode*>>,
                          greater<pair<int,ListNode*>>
                        >pq;

        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
               pq.push({lists[i]->val,lists[i]});
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        while(!pq.empty())
        {
            ListNode* temp=pq.top().second;
            pq.pop();
           curr->next=temp;
            if(temp->next)
            {
                pq.push({temp->next->val,temp->next});
            }
            
            curr=curr->next;
        }
        return dummy->next;
    }
};