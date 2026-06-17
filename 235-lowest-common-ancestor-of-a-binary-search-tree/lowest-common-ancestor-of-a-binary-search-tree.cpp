/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         
         if(!root) return root;
         if(p==nullptr || q==nullptr) return root;

         if(p->val >= root->val && q->val <= root->val) 
           return root; 
          if(p->val <= root->val && q->val >= root->val) 
           return root; 

          if(p->val > root->val && q->val >root->val)
           root= lowestCommonAncestor(root->right,p,q);

           else 
             root=lowestCommonAncestor(root->left,p,q);

             return root;
        
        
        
        
        
        
        
        /*if(p==root||q==root)
        return root;

        if((p->val > root->val && q->val < root->val)|| (p->val < root->val && q->val > root->val)) 
        {
            // both are in different subtrees so return root its only common ancestor bwt them 
            return root;
        }
        else if(p->val > root->val && q->val > root->val)
        {
            //both in right subtree so again recurssive func to find lowest common ancestor but root=root->right bcz both p,q are in right subtree
            return lowestCommonAncestor(root->right, p, q);
        }
        else if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q); // both are in left subtree
         }
         else 
         return root;// this is not required. Adding it to avoid error like "missing return .."
         */
    }
};