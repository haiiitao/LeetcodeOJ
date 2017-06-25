/**
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
class Solution {
public:
    vector<TreeNode*> generateTrees( int n ) {
        vector<TreeNode*> result;
        if ( n )
            generate( result, 1, n );
        
        return result;
    }
    
private:
    void generate( vector<TreeNode*>& result, int start, int end ) {
        if ( start > end ) 
            result.push_back( NULL );
        
        for ( int k = start; k <= end; k++ ) {
            vector<TreeNode*> leftSubs, rightSubs;
            generate( leftSubs, start, k - 1 );
            generate( rightSubs, k + 1, end );
            for ( auto i : leftSubs ) {
                for ( auto j : rightSubs ) {
                    TreeNode* node = new TreeNode( k );
                    node->left = i;
                    node->right = j;
                    result.push_back( node );
                }
            }
        }
    }
};