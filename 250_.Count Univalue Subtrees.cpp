/**
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.
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
    int countUnivalSubtrees( TreeNode* root ) {
        int count = 0;
        dfs( root, count );
        return count;
    }
private:
    bool dfs( TreeNode* root, int& count ) {
        if ( !root ) 
            return true;
            
        bool b_L = dfs( root->left, count );
        bool b_R = dfs( root->right, count );
        if ( b_L && b_R
                && (!root->left || root->left->val == root->val)
                && (!root->right || root->right->val == root->val) ) {
            ++count;
            return true;
        }
        return false;
    }
};