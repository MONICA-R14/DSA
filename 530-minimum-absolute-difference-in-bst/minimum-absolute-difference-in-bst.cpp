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
      vector<int> v;
    int getMinimumDifference(TreeNode* root) {
        inorder(root);

         int min=v[1]-v[0];
    
        for(int i=0;i<v.size()-1;i++)
        {
            if(min>v[i+1]-v[i])
              min=v[i+1]-v[i];
        }
        return min;
    }

    void inorder(TreeNode* root)
    {
        if(root==nullptr)
        return;

        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
};