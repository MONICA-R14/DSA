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
    int depthx=-1,depthy=-1;
    TreeNode* parentx=nullptr; TreeNode* parenty=nullptr;

    void dfs(TreeNode* node , TreeNode* parent , int depth ,int x,int y)
    {
        if(!node) return;

        if(node->val==x)
        {
            depthx=depth;
            parentx=parent;
        }
        else if(node->val==y)
        {
            depthy=depth;
            parenty=parent;
        }

        dfs(node->left,node,depth+1,x,y);
         dfs(node->right,node,depth+1,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,nullptr,0,x,y);
        return (depthx==depthy) && (parentx!=parenty);
    }
};