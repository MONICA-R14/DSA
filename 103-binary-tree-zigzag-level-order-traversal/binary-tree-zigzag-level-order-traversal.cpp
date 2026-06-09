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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //bfs
        
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(!root) return ans;
        q.push(root);
        int t=0;//to check if level is even or odd

        while(!q.empty())
        {
            t++;
            int size=q.size();
            vector<int>v;
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();

                v.push_back(curr->val);
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(t%2==0) //even level reverse
            {
                reverse(v.begin(),v.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};