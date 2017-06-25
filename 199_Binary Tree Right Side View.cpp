/**
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView( TreeNode* root ) {
        vector<int> res;
        function<void( TreeNode*, int )> dfs = [&]( TreeNode* root, int level ) {
            if ( !root )   
                return;
            
            if ( level == res.size() )
                res.push_back( root->val );
            
            dfs( root->right, level + 1 );
            dfs( root->left,  level + 1 );           
        };
        dfs ( root, 0 );
        return res;
    }
};