/**
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,20,4,5,2,7],
    _3_
   /   \
  9    20
 / \   / \
4   5 2   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,5,2],
  [20],
  [7]
]
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
    vector<vector<int>> verticalOrder( TreeNode* root ) {
        vector<vector<int>> result;
        map<int, vector<int>> map_width2Val;
        queue<pair<int, TreeNode*>> q;
        if ( root ) 
            q.push( pair<int, TreeNode*>( 0, root ) );
            
        while ( !q.empty() ) {
            for ( size_t i = 0, len = q.size(); i < len; i++ ) {
                auto& cur = q.front();
                map_width2Val[cur.first].push_back( cur.second->val );
                if ( cur.second->left ) q.push( make_pair( cur.first - 1, cur.second->left ) );
                if ( cur.second->right ) q.push( make_pair( cur.first + 1, cur.second->right ) );
                q.pop();
            }
        }
        for ( auto it = map_width2Val.begin(), itEnd = map_width2Val.end(); it != itEnd; it++ )
            result.push_back( it->second );
        
        return result;
    }
};