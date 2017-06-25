/**
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum( TreeNode* root, int sum ) {
        vector<vector<int>> result;
        vector<int> path;
        dfs( root, sum, result, path );
        return result;
    }
    void dfs ( TreeNode *root, int sum, vector<vector<int>>& result, vector<int>& path ) {
        if ( !root ) 
            return;
            
        path.push_back( root->val );
        int gap = sum - root->val;
        if ( !root->left && !root->right && !gap )
            result.push_back( path ); 
        else {
            dfs( root->left, gap, result, path );
            dfs( root->right, gap, result, path );
        }
        path.pop_back();
        return;
    }
};