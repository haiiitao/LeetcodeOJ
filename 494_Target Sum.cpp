class Solution {
public:
    int findTargetSumWays( vector<int>& nums, int S ) {
        int sum = accumulate( nums.begin(), nums.end(), 0 );
        if ( S < -sum || S > sum )
            return 0;
        
        vector<int> f( 2 * sum + 1, 0 );
        f[sum] = 1;
        for ( int i = 0, len = nums.size(); i < len; i++ ) {
            vector<int> next_f( 2 * sum + 1, 0 );
            for ( int j = -sum; j <= sum; j++ ) {
                int idx = sum + j;
                if ( f[idx] ) {
                    next_f[idx - nums[i]] += f[idx];
                    next_f[idx + nums[i]] += f[idx];
                }
            }
            swap( f, next_f );
        }
        return f[sum + S];
    }
};