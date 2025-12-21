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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return symmet(root->left,root->right);
    }
    bool symmet(TreeNode* p,TreeNode* q)
    {
        if(p==nullptr && q==nullptr)
        return true;

        if(p==nullptr || q==nullptr)
        return false;

        if(p->val!=q->val)
        return false;

        return (symmet(p->right,q->left)&& symmet(p->left,q->right));
    }
};