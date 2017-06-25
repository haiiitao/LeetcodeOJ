class Solution {
private:
    TreeNode *tail;
public:
    void flatten( TreeNode* root ) {
        if ( !root ) 
            return;
            
        tail = root;
        if ( root->left ) {
            flatten( root->left );
            tail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        flatten( tail->right );
    }
};