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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
       if(!head)return nullptr;
        if(head->next==nullptr)
        {
            TreeNode* root=new TreeNode(head->val);
            return root;
        }

        auto fast=head->next,slow=head;
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;// to find middle element
            slow=slow->next;
        }
        auto mid=slow->next;// mid= slow->next

        slow->next=nullptr;// to separate left subtree alone so create break node before mid(slow->next) thats slow->next=nullptr 

      auto root=new TreeNode(mid->val);// FOR MID

        root->left=sortedListToBST(head);// FROM HEAD TO MID-1
        //leftsubtree from head to mid-1 node since we made slow->next=null it'll stop there

        root->right=sortedListToBST(mid->next); // FROM MID+1 TO LAST NODE
        //right subtree from mid->next to last node

        return root;
    }
};