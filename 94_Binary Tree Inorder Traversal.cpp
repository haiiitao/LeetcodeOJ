/**
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
    vector<int> inorderTraversal( TreeNode* root ) {
        vector<int> result;
        stack<TreeNode*> s;
        while ( root || !s.empty() ) {
            if ( root ) {
                s.push( root );
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                result.push_back( root -> val );
                root = root->right;
            }
        }
        return result;
    }
};

class Solution { // morris, O(1) space
public:
    vector<int> inorderTraversal( TreeNode* root ) {
        vector<int> result;
        TreeNode *prev, *cur = root;
        while ( cur ) {
            if ( !cur->left ) {
                result.push_back( cur->val );
                prev = cur;
                cur = cur->right;
            } else {
                TreeNode* p = cur->left;
                while ( p->right && p->right != cur )
                    p = p->right;
                    
                if ( !p->right ) {
                    p->right = cur;
                    cur = cur->left;
                } else {
                    result.push_back( cur->val );
                    p->right = NULL;
                    prev = cur;
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> inorderTraversal( TreeNode* root ) {
        stack<TreeNode*> stk;
        vector<int> result;
        
        while( root ) {
            stk.push( root );
            root = root->left;
        }
        while ( !stk.empty() ) {
            TreeNode* p = stk.top();
            stk.pop();
            result.push_back( p->val );
            if ( p->right ) {
                p = p->right;
                while ( p ) {
                    stk.push( p);
                    p = p->left;
                }
            }
        }
        return result;
    }
};