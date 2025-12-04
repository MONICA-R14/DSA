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
/*class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
     return convert(nums,0,nums.size()-1);
    }
    private:
    TreeNode* convert(vector<int>& nums, int left,int right)
    {
        if(left>right)
        return nullptr;

        int mid=(left+right)/2;
        auto root=new TreeNode(nums[mid]);
        root->left=convert(nums,left,mid-1);
        root->right=convert(nums,mid+1,right);
        return root;
    }
};*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }

    TreeNode* build(vector<int>& nums, int start, int end) {
        if (start == end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, start, mid);
        root->right = build(nums, mid + 1, end);
        return root;
    }
};