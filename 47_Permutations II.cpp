/**
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
class Solution {
public:
    vector<vector<int> > permuteUnique( vector<int>& nums ) {
        vector<vector<int> > result;
        const int len = nums.size();
        sort( nums.begin(), nums.end() );       
        result.push_back( nums );
        int i, j;
        while ( true ) {
            for ( i = len - 1; i > 0; i--) {
                if ( nums[i - 1] < nums[i] )
                    break;
            }
            
            if ( !i )
                break;

            int pivot = i - 1;
            for ( j = len - 1; j > pivot; j--) {
                if ( nums[j] > nums[pivot] )
                    break;           
            }
            
            swap( nums[pivot], nums[j]);
            reverse( nums.begin() + i, nums.end() );
            result.push_back( nums );
        }
        return result;
    }
};

class Solution {
public:
    void dfs( vector<int>& nums, int n, vector<int>& path, bool used[], vector<vector<int>>& result ) {
        const int len = nums.size();
        if ( n == len ) {
            result.push_back( path );
            return;
        }
        for ( int i = 0; i < len; i++ ) {
            if ( used[i] ) 
                continue;
            
            used[i] = true;
            path.push_back( nums[i] );
            dfs( nums, n + 1, path, used, result );
            path.pop_back();
            used[i] = false;
            while ( i + 1 < len && nums[i] == nums[i + 1] )
                i++;
        }
    }
    vector<vector<int>> permuteUnique( vector<int>& nums ) {
        sort( nums.begin(), nums.end() );
        bool used[nums.size()] = { false };
        
        vector<vector<int>> result;
        vector<int> path;
        dfs( nums, 0, path, used, result );
        
        return result;
    }
};