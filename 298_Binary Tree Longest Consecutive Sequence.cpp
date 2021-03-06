/**
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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
    int longestConsecutive( TreeNode* root ) {
        int result = 0;
        longestConsecutive( root, 0, result );
        return result;
    }
    void longestConsecutive( TreeNode* root, int level, int& result ) {
        if ( !root )
            return;
            
        level++;
        result = max( result, level );
        if ( root->left ) 
            longestConsecutive( root->left, root->left->val == root->val + 1 ? level : 0, result );
         
        if ( root->right ) 
            longestConsecutive( root->right, root->right->val == root->val + 1 ? level : 0, result );
    }
};