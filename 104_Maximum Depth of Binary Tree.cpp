/**
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepth( TreeNode* root ) {
        return dfs( root );
    }

private:
    int dfs( TreeNode* root ) {
        if ( !root )
            return 0;

        return max( dfs( root->left ), dfs( root->right ) ) + 1;
    }
};