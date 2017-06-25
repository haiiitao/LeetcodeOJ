/**
Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
(ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
 */
class Solution {
public:
    vector<vector<int>> combinationSum2( vector<int>& candidates, int target ) {
        vector<vector<int>> result;
        vector<int> path;
        sort( candidates.begin(), candidates.end() );
        dfs( result, path, candidates, 0, target );

        return result;
    }

private:
    void dfs( vector<vector<int>>& result, vector<int>& path, vector<int>& candidates, int idx, int gap ) {
        if ( !gap ) {
            result.push_back( path );
            return;
        }
        
        for ( size_t i = idx, len = candidates.size(); i < len; i++ ) {
            if ( idx != i && candidates[i] == candidates[i - 1] )
                continue;
                
            if ( gap - candidates[i] < 0 )
                return;
                
            path.push_back( candidates[i] );
            dfs( result, path, candidates, i + 1, gap - candidates[i] );
            path.pop_back();
        }
    }
};
