/**
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder( TreeNode* root ) {
        vector<vector<int>> result;
        dfs( result, root, 0 );

        return result;
    }

private:
    void dfs( vector<vector<int>>& result, TreeNode* root, int level ) {
        if ( !root )
            return;

        if ( result.size() == level )
            result.push_back( vector<int>() );

        result[level].push_back( root->val );
        dfs( result, root->left, level + 1 );
        dfs( result, root->right, level + 1 );
    }
};

// ==> another version
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if ( !root ) 
            return result;
            
        queue<TreeNode*>* pCurrent = new queue<TreeNode*>();
        queue<TreeNode*>* pNext = new queue<TreeNode*>();;
        pCurrent->push( root );
        while ( !pCurrent->empty() ) {
            result.push_back( vector<int>() );
            vector<int>& row = result.back();
            while ( !pCurrent->empty() ) {
                TreeNode* node = pCurrent->front();
                pCurrent->pop();
                row.push_back( node->val );
                if ( node->left ) 
                    pNext->push( node->left );
                if ( node->right ) 
                    pNext->push( node->right );
            }
            swap( pCurrent, pNext );
        }
        delete pCurrent;
        delete pNext;
        
        return result;
    }
};
