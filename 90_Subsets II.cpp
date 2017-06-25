/**
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup( vector<int>& nums ) {
        sort( nums.begin(), nums.end() );
        vector<int> path;
        vector<vector<int>> result;
        dfs( result, path, nums, 0 );
        return result;
    }
    
private:   
    void dfs( vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int idx ) {
        result.push_back( path );
        for ( size_t i = idx, len = nums.size(); i < len; i++ ) {
            if ( i > idx && nums[i] == nums[i - 1] )
                continue;
                
            path.push_back( nums[i] );
            dfs( result, path, nums, i + 1 );
            path.pop_back();
        }
    }
};