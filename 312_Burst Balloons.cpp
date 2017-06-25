class Solution {
public:
    int maxCoins( vector<int>& nums ) {
        nums.insert( nums.begin(), 1 );
        nums.insert( nums.end(), 1 );
        const int len = nums.size();
        int dp[len][len] = {};   // dp[i][j] means the maxScore we can reach by bursting all the balloons between (i,j)
        for ( int k = 2; k < len; k++ ) {
            for ( int left = 0; left + k < len; left++ ) {
                int right = left + k;
                for ( int i = left + 1; i < right; i++ ) {
                    dp[left][right] = max( dp[left][right], 
                        dp[left][i] + dp[i][right] + nums[left] * nums[right] * nums[i] );
                }
            }
        }
        return dp[0][len - 1];
    }
};