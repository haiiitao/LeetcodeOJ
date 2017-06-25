/**
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
 */

// Binary Search
class Solution {
public:
    int lengthOfLIS( const vector<int>& nums ) {
        vector<int> tails;
        for ( auto num : nums ) {
            auto iter = lower_bound( tails.begin(), tails.end(), num );
            if ( iter == tails.end() )
                tails.push_back( num );
            else if ( num < *iter )
                *iter = num;
        }
        return tails.size();
    }
};

// DP
class Solution {
public:
    int lengthOfLIS( vector<int>& nums ) {
        int len = nums.size(), max_length = 0;
        int f[len];
        fill_n( f, len, 1 );
        for ( int i = 0; i < len; i++ ) {
            for ( int j = 0; j < i; j++ ) {
                if ( nums[j] < nums[i] && f[i] < f[j] + 1 )
                    f[i] = f[j] + 1;
            }
            max_length = max( max_length, f[i] );
        }
        return max_length;
    }
};