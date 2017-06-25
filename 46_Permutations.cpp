/**
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */
class Solution {
public:
    vector<vector<int>> permute( vector<int>& nums ) {
        vector<vector<int>> result;
        dfs( nums, result, 0 );
        
        return result;
    }
    
    void dfs( vector<int>& nums, vector<vector<int>>& result, int idx ) {
        const int len = nums.size();
        if ( idx == len - 1 ) {
            result.push_back( nums );
            return;
        }    
        
        for ( size_t i = idx; i < len; i++ ) {
            swap( nums[i], nums[idx] );
            dfs( nums, result, idx + 1 );
            swap( nums[i], nums[idx] );
        }
    }
};