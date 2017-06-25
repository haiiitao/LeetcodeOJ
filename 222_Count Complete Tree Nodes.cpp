/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int countNodes( TreeNode* root ) {
        int leftDepth = 0, rightDepth = 0;
        for ( auto p = root; p; p = p->left ) 
            ++leftDepth;

        for ( auto p = root; p; p = p->right ) 
            ++rightDepth;
        
        if ( leftDepth == rightDepth )
            return (1 << leftDepth) - 1;
            
        return countNodes( root->left ) + countNodes( root->right ) + 1 ;
    }
};

// better solution but more complicate ==>
class Solution {
public:
    int countNodes( TreeNode* root, int leftDepth = 0, int rightDepth = 0 ) {
        if ( !leftDepth )
            for ( auto p = root; p; p = p->left ) 
                ++leftDepth;

        if ( !rightDepth )
            for ( auto p = root; p; p = p->right ) 
                ++rightDepth;
        
        if ( leftDepth == rightDepth )
            return (1 << leftDepth) - 1;
        
        return countNodes( root->left, --leftDepth, 0 ) + countNodes( root->right, 0, --rightDepth ) + 1 ;
    }
};

// better solution but more complicate ==>
class Solution {
public:
    int countNodes( TreeNode* root, int leftDepth = 0, int rightDepth = 0 ) {
        if ( !leftDepth )
            for ( auto p = root; p; p = p->left ) 
                ++leftDepth;

        if ( !rightDepth )
            for ( auto p = root; p; p = p->right ) 
                ++rightDepth;
        
        if ( leftDepth == rightDepth )
            return (1 << leftDepth) - 1;
            
        int left_count = countNodes( root->left, --leftDepth, 0 );
        int right_count = ( left_count != (1 << leftDepth) - 1 ) ? 
            (1 << --rightDepth) - 1 : countNodes( root->right, 0, --rightDepth );

        return left_count + right_count + 1 ;
    }
};