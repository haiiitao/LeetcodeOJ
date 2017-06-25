class Solution {
public:
    int diameterOfBinaryTree( TreeNode* root ) {
        int result = 0;
        dfs( result, root );
        return result;
    }
    int dfs( int& result, TreeNode* root ) {
        if ( !root )
            return 0;
        
        int l = dfs( result, root->left );
        int r = dfs( result, root->right );
        result = max( result, l + r );
        return max( l, r ) + 1;
    }
};