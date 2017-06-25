class Solution {
public:
    TreeNode* convertBST( TreeNode* root ) {
        int sum = 0;
        dfs( root, sum );
        return root;
    }
    void dfs( TreeNode* root, int& sum ) {
        if ( !root )
            return;
        
        dfs( root->right, sum );
        root->val += sum;
        sum = root->val;
        dfs( root->left, sum );
    }
};