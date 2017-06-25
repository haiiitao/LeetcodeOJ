/**
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/
class Solution {
public:
    vector<vector<int>> combinationSum3( int k, int target ) {
        vector<vector<int>> result;
        vector<int> path;
        dfs( result, path, k, 1, target );
        
        return result;
    }
    
private:
    void dfs( vector<vector<int>>& result, vector<int>& path, int k, int begin, int gap ) {
        if ( path.size() == k && !gap ) {
            result.push_back( path );
            return;
        }
        
        for ( int i = begin; i <= gap && i <= 9; i++ ) {
            path.push_back( i );
            dfs( result, path, k, i + 1, gap - i );
            path.pop_back();
        }
    }
};