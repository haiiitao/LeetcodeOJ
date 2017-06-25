class Solution {
public:
    int minPatches( vector<int>& nums, int n ) {
        int i = 0;
        long cur = 1;
        int result = 0;
        while ( cur <= n ) {
            if ( i < nums.size() && cur >= nums[i] ) {
                cur += nums[i++];
            } else {
                cur *= 2;
                result++;
            }
        }
        return result;
    }
};