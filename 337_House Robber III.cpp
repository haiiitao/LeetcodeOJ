class Solution {
public:
    int rob(TreeNode* root) {
        int r, l;
        return rob( root, l, r );
    }
    int rob(TreeNode* root, int& l, int& r ) {
        if ( !root )
            return 0;
        
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = rob( root->left, ll, lr );
        r = rob( root->right, rl, rr );
        return max( root->val + ll + lr + rl + rr, l + r );
    }
};