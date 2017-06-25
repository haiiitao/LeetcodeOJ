/**
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
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
    vector<int> closestKValues( TreeNode* root, double target, int k ) {
        deque<int> myQ; 
        stack<TreeNode*> ss; // use stack to do in-order search 
        while ( root || !ss.empty() ) {
            if ( root ) {
                ss.push( root );
                root = root->left;
            } else {
                root = ss.top();
                ss.pop();
                if ( myQ.size() < k ) myQ.push_back( root->val );
                else if ( target > root->val || abs( target - root->val ) < abs( target - myQ.front() ) ) {
                    myQ.push_back( root->val );
                    myQ.pop_front();
                } else break;
                root = root->right;
            }
        }
        return vector<int>( myQ.begin(), myQ.end() );
    }
};

class Solution {
public:
    vector<int> closestKValues( TreeNode* root, double target, int k ) {
        deque<int> q; 
        stack<TreeNode*> stk; 
        while ( root ) {
            stk.push( root );
            root = root->left;
        }
        while ( !stk.empty() ) {
            TreeNode* p = stk.top();
            stk.pop();
            if ( q.size() < k ) 
                q.push_back( p->val );
            else if ( target > p->val || p->val -target < abs( target - q.front() ) ) {
                q.push_back( p->val );
                q.pop_front();               
            } else 
                break;
            
            if ( p->right ) {
                p = p->right;
                while ( p ) {
                    stk.push( p );
                    p = p->left;
                }
            }    
        }
        return vector<int>( q.begin(), q.end() );
    }
};