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
       TreeNode* fe=nullptr; //first element
       TreeNode* se=nullptr;
       TreeNode* prev=nullptr;
    void recoverTree(TreeNode* root) {
        //ref note for explanation --
        //inorder traversal to find that two elements which causes the violation 
        traverse(root);
        //for swapping that two elements that causes the violation
         int temp=fe->val;
         fe->val=se->val;
         se->val=temp;
    }
    void traverse(TreeNode* root)
    {
        if(root==nullptr)
        return;

        traverse(root->left);
          // to find first violation
       /* if(fe==nullptr && prev->val >= root->val)
        {
            fe=prev;
        }
        //to find second violation
        if(fe!=nullptr && prev->val >= root->val)
        {
            se=root;
        }
        */
        if (prev != nullptr && prev->val > root->val)
         {
            if (fe == nullptr) {
                fe = prev;     // first violation
            }
            se = root;        // second violation (or update)
        }
        prev=root;

        traverse(root->right);
    }

};