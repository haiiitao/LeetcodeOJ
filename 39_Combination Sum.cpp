/**
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
 */
class Solution {
public:
    vector<vector<int>> combinationSum( vector<int>& candidates, int target ) {
        vector<vector<int>> result;
        vector<int> path;
        sort( candidates.begin(), candidates.end() );
        dfs( result, path, candidates, 0, target );

        return result;
    }
    void dfs( vector<vector<int>>& result, vector<int>& path, vector<int>& candidates, int idx, int gap ) {
        if ( !gap ) {
            result.push_back( path );
            return;
        }

        for ( size_t i = idx, len = candidates.size(); i < len; i++ ) {
            if ( gap - candidates[i] < 0 )
                return;

            path.push_back( candidates[i] );
            dfs( result, path, candidates, i, gap - candidates[i] );
            path.pop_back();
        }
    }
};