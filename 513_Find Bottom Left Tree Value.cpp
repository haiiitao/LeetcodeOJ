class Solution {
public:
    int findBottomLeftValue( TreeNode* root ) {
        vector<int> result;
        dfs( root, result, 0 );
        return result.back();
    }
    void dfs( TreeNode* root, vector<int>& result, int level ) {
        if ( !root )
            return;
        
        if ( result.size() == level )
            result.push_back( 0 );
        
        result[level] = root->val;
        dfs( root->right, result, level + 1 );
        dfs( root->left, result, level + 1 );
    }
};