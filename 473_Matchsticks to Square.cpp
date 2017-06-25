class Solution {
public:
    bool makesquare( vector<int>& nums ) {
        int sum = accumulate( nums.begin(), nums.end(), 0 );
        if ( sum % 4 || nums.empty() )
            return false;
            
        sort( nums.begin(), nums.end(), ::greater<int>() );
        sum /= 4;
        return dfs ( 0, nums, sum, sum, sum, sum );
    }
    
    bool dfs( int idx, vector<int>& nums, int n1, int n2, int n3, int n4 ) {
        if ( !n1 && !n2 && !n3 && !n4 )
            return true;
            
        if ( n1 < 0 || n2 < 0 || n3 < 0 || n4 < 0 || idx == nums.size() )
            return false;
            
        return dfs( idx + 1, nums, n1 - nums[idx], n2, n3, n4 ) ||
            dfs( idx + 1, nums, n1, n2 - nums[idx], n3, n4 ) ||
            dfs( idx + 1, nums, n1, n2, n3 - nums[idx], n4 ) ||
            dfs( idx + 1, nums, n1, n2, n3, n4 - nums[idx] );
    }
};