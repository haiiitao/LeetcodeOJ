class Solution {
public:
    bool isValidBST( TreeNode* root, long lower_bound = LONG_MIN, long upper_bound = LONG_MAX ) {
        if ( !root )
            return true;
        
        if ( root->val <= lower_bound || root->val >= upper_bound )
            return false;
        
        return isValidBST( root->left, lower_bound, root->val ) &&
            isValidBST( root->right, root->val, upper_bound );
    }
};