/**
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.
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
    int largestBSTSubtree( TreeNode* root ) {
        int res = 0, mini, maxi;
        isBST( root, res, mini, maxi );

        return res;
    }
private:
    bool isBST( TreeNode* node, int& res, int& mini, int& maxi ) {
        if ( !node )
            return true;

        int res_left = 0, res_right = 0;
        int left_mini, left_maxi, right_mini, right_maxi;

        bool b_left = isBST( node->left, res_left, left_mini, left_maxi );
        bool b_right = isBST( node->right, res_right, right_mini, right_maxi );

        if ( b_left && b_right ) {
            if ( (!node->left || node->val > left_maxi) && 
                 (!node->right || node->val < right_mini) ) {
                res = res_left + res_right + 1;
                mini = node->left ? left_mini : node->val;
                maxi = node->right ? right_maxi : node->val;
                return true;
            }
        }
        res = max( res_left, res_right );
        return false;
    }
};