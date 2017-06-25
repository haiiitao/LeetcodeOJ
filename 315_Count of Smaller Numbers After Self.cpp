class Solution {
public:
    struct TreeNode {
        int val;
        int smaller_cnt, same_cnt;
        TreeNode* left, *right;
        TreeNode( int v ) : val( v ), smaller_cnt( 0 ), same_cnt( 1 ), left( NULL ), right( NULL ) {}
    };
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        TreeNode* root = NULL;
        for ( int i = nums.size() - 1; i >= 0; i-- ) {
            int count = 0;
            root = build_tree( root, nums[i], count );
            result.push_back( count );
        }
        reverse( result.begin(), result.end() );
        return result;
    }
    TreeNode* build_tree( TreeNode* root, int num, int& count ) {
        if ( !root ) {
            root = new TreeNode( num );
        } else if ( root->val < num ) { // go right
            count += root->smaller_cnt + root->same_cnt;
            root->right = build_tree( root->right, num, count );
        } else if ( root->val > num ) {
            root->smaller_cnt++;
            root->left = build_tree( root->left, num, count );
        } else {
            count += root->smaller_cnt;
            root->same_cnt++;
        }
        return root;
    }
};