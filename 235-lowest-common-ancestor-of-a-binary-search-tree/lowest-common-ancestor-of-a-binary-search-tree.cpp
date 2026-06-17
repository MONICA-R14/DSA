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
        //ITERATIVE METHOD
            while(root)
            {
                if(p->val < root->val && q->val <root->val)//both present on left subtree so move left
                  root=root->left;
                else if(p->val >root->val && q->val > root->val)//both are in right subtree so move right
                  root=root->right;
                else //both present in distinct subtree p in left , q in right or vice versa
                 return root;
            }
            return root;

       //RECURSION METHOD

       /*
        if(p==root||q==root)
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