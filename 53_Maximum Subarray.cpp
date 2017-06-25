class Solution {
public:
    int maxSubArray( vector<int>& nums ) {
        int f = 0, result = INT_MIN;
        for ( auto num : nums ) {
            f = max( num, f + num );
            result = max( result, f );
        }
        return result;
    }
};