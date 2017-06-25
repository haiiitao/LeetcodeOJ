class Solution {
public:
    TreeNode* upsideDownBinaryTree( TreeNode* root ) {
        TreeNode* next_root, *next_right = NULL, *next_left = NULL;
        while( root ) {
            TreeNode* t1 = root, *t2 = root->right;
            next_root = root->left;
            root->left = next_left;
            root->right = next_right;
            next_right = t1;
            next_left = t2;
            root = next_root;
        }
        return next_right;
    }
};