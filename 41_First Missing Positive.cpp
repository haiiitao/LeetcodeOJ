/**
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
class Solution {
public:
    int firstMissingPositive( vector<int>& nums ) {
        const size_t len = nums.size();
        for ( size_t i = 0; i < len; i++ )
            while ( nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i] )
                swap( nums[i], nums[nums[i] - 1] );

        for ( size_t i = 0; i < len; i++ )
            if ( nums[i] != i + 1 )
                return i + 1;

        return len + 1;
    }
};