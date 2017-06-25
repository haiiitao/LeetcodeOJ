/**
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */
class Solution {
public:
    vector<vector<int>> subsets( vector<int>& nums ) {
        sort( nums.begin(), nums.end() );
        vector<int> path;
        vector<vector<int>> result;
        dfs( result, path, nums, 0 );
        return result;
    }

private:   
    void dfs( vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int start ) {
        result.push_back( path );
        for ( int i = start, len = nums.size(); i < len; i++ ) {
            path.push_back( nums[i] );
            dfs( result, path, nums, i + 1 );
            path.pop_back();
        }
    }
};