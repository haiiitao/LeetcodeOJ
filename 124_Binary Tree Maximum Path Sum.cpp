class Solution {
public:
    int maxPathSum( TreeNode* root ) {
        int result = INT_MIN;
        dfs( root, result );
        return result;
    }
    int dfs( TreeNode* root, int& result ) {
        if ( !root )
            return 0;
        
        int l = max( 0, dfs( root->left, result ) );
        int r = max( 0, dfs( root->right, result ) );
        result = max( result, root->val + l + r );
        return max( l, r ) + root->val;
    }
};