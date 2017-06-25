class Solution {
public:
    int sumNumbers( TreeNode* root ) {
        int result = 0;
        dfs( root, 0, result );
        return result;
    }
    void dfs( TreeNode* root, int sum, int& result ) {
        if ( !root )
            return;
        
        if ( !root->left && !root->right ) {
            result += sum * 10 + root->val;
            return;
        }
        dfs( root->left, sum * 10 + root->val, result );
        dfs( root->right, sum * 10 + root->val, result );
    }
};