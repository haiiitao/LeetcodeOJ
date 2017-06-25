class Solution {
public:
    TreeNode* buildTree( vector<int>& inorder, vector<int>& postorder ) {
        return buildTree( inorder, 0, inorder.size(), postorder, 0, postorder.size() );
    }
    TreeNode* buildTree( vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int post_start, int post_end ) {
        if ( in_end <= in_start || post_end <= post_start )
            return NULL;
        
        int target = postorder[post_end - 1];
        int i = in_start;
        for ( ; i < in_end; i++ )
            if ( inorder[i] == target )
                break;
        
        int length = i - in_start;
        TreeNode* temp = new TreeNode( target );
        temp->left = buildTree( inorder, in_start, i, postorder, post_start, post_start + length );
        temp->right = buildTree( inorder, i + 1, in_end, postorder, post_start + length, post_end - 1 );
    
        return temp;
    }
};