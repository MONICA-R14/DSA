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

    vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
                //ref rednote for more
            if (i == size - 1)   //  rightmost of this level
                ans.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return ans;
}

  /*  vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        queue<TreeNode*>q;
        if(root) q.push(root);
        while(!q.empty())
        {
            TreeNode* right=nullptr;
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front(); q.pop();
                if(node)
                {
                    right=node;
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
            if(right)
            {
                res.push_back(right->val);
            }  
        }
        return res;
    }*/
};