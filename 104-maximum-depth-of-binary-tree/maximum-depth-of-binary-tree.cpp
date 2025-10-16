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
    int maxDepth(TreeNode* root) {
        int count=0;
        int x=deep(root,count);
        return x;
    }
    int deep(TreeNode* p,int count)
    {
        if(p==nullptr)
        return count;

        if(p->left==nullptr && p->right==nullptr)
        {
            count++;
            return count;
        }
        
        if(p->left==nullptr)
        {
            count++;
            return deep(p->right,count);
        }

        if(p->right==nullptr)
        {
            count++;
            return deep(p->left,count);
        }
        
        else
        {
            count++;
            return max(deep(p->left,count),deep(p->right,count));
        }
    }
};