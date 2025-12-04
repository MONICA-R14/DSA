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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       if(nums.empty())
         return nullptr;
         if(nums.size()==1)
         {
            auto root=new TreeNode(nums[0]);
            return root;
         }
        int n=nums.size(); int x=n/2;
        int mid=nums[x];
        auto root=new TreeNode(mid); 
    
        vector<int>v1(nums.begin(), nums.begin()+x);
         root->left= sortedArrayToBST(v1);

    
         vector<int>v2( nums.begin()+x+1,nums.end());
          root->right= sortedArrayToBST(v2);

       
           
        return root;
        
    }
};