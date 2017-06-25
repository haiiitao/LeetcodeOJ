/**
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

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
    int kthSmallest( TreeNode* root, int k ) {
        int result;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if ( !root || !k )
                return;
        
            dfs( root->left );
            if ( --k == 0 ) result = root->val;
            dfs( root->right );           
        };
        
        dfs( root);
        return result;
    }
};

//==> better solution
class Solution {
public:
    int kthSmallest( TreeNode* root, int k ) {
        if ( !root ) 
            return 0;
            
        if ( k == 0 ) 
            return root->val;
    
        int n = countSize( root->left );
        if ( k == n + 1 ) 
            return root->val;
    
        if ( n >= k ) 
            return kthSmallest( root->left, k );
        
        if ( n < k )
            return kthSmallest( root->right, k - n - 1 );
}

private:
    int countSize( TreeNode* root ) {
        if ( !root ) 
            return 0;
            
        return 1 + countSize( root->left ) + countSize( root->right );
    }
};