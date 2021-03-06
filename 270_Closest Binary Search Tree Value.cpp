/**
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
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
    int closestValue( TreeNode* root, double target ) {
        double result = numeric_limits<double>::infinity();
        
        function<void( TreeNode* )> binary_search = [&]( TreeNode* root ) {
            if ( !root )
                return;
                
            if ( fabs( root->val - target) < fabs( target - result ) )
                result = root->val;
            
            root->val > target ? binary_search( root->left ) : binary_search( root->right );           
        };
        
        binary_search( root );
        return (int)result;
    }
};