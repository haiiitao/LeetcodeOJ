/**
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void dfs( vector<string>& result, string path, TreeNode* root ) {
        if ( !root ) 
            return;
            
        if ( !root->left && !root->right ) {
            result.push_back( path + to_string( root->val ) );
            return ;
        }
        path += to_string( root->val ) + "->";
        dfs( result, path, root->left );
        dfs( result, path, root->right );
    }
    
public:
    vector<string> binaryTreePaths( TreeNode* root ) {
        vector<string> result;
        dfs( result, "", root );
        return result;
    }
};