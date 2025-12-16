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
     void similar (TreeNode* root,vector<int>&v)
     {
        if(root==nullptr)
        return;
        if(!root->left && !root->right)
        {
           v.push_back(root->val);
        }
        similar(root->left,v);
        similar(root->right,v);
        
     }  
      bool leafSimilar(TreeNode* root1, TreeNode* root2) {
         vector<int>v1,v2;
         similar(root1,v1);
         similar(root2,v2);
        if(v1==v2)
         return true;
        else
        return false;
    }
    
};