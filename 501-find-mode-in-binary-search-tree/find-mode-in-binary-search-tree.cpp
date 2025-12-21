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
      
    vector<int> findMode(TreeNode* root) {
       unordered_map<int,int>count;
       vector<int>modes;
       int maxcount=0;
        
       inorder(root,count,modes,maxcount);
       return modes;
    }
    void inorder(TreeNode* root,unordered_map<int,int> &count,vector<int> &modes,int &maxcount)
    {
       if(root==nullptr)
       return;

       inorder(root->left,count,modes,maxcount);

       count[root->val]++;
       if(count[root->val] > maxcount)
       {
         // remove all elements from vector and add new element with highest mode (i.e) root->val 
         maxcount=count[root->val];
         modes.clear();//clear entire vector
         modes.push_back(root->val);// push highest mode element
       }
       else if(count[root->val] == maxcount)
       {
        // if element count(mode) is same as other element (mode) maxcount then just append this new element to vector modes (bcz both elements have same mode (highest)) 
        modes.push_back(root->val);
       }

       inorder(root->right,count,modes,maxcount);
      

    }
 
};