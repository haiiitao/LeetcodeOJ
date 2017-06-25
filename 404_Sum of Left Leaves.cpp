/**
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 */
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
    int sumOfLeftLeaves( TreeNode* root ) {
        int sum = 0;
        dfs( root, sum, false );
        return sum;
    }
    void dfs( TreeNode* root, int& sum, bool fromLeft ) {
        if ( !root )
            return;
            
        if ( !root->left && !root->right && fromLeft )
            sum += root->val;
        
        dfs( root->left, sum, true );
        dfs( root->right, sum, false );
    }
};