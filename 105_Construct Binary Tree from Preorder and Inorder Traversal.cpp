class Solution {
public:
    TreeNode* buildTree( vector<int>& preorder, vector<int>& inorder ) {
        return buildTree( preorder, 0, preorder.size(), inorder, 0, inorder.size() );
    }
    TreeNode* buildTree( vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end ) {
        if ( pre_end <= pre_start || in_end <= in_start )
            return NULL;
        
        int target = preorder[pre_start];
        int i = in_start;
        for ( ; i < in_end; i++ )
            if ( inorder[i] == target )
                break;
        
        TreeNode* temp = new TreeNode( target );
        temp->left = buildTree( preorder, pre_start + 1, pre_start + (i - in_start + 1), inorder, in_start, i );
        temp->right = buildTree( preorder, pre_start + (i - in_start + 1), pre_end, inorder, i + 1, in_end );
        return temp;
    }
};