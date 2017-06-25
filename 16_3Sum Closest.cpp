/**
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, 
target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
class Solution {
public:
    int threeSumClosest( vector<int> &num, int target ) {
        int result = 0, min_gap = INT_MAX;
        sort( num.begin(), num.end() );
        for ( int idx = 0, len = num.size(); idx < len - 2; idx++ ) {
            if ( idx && num[idx] == num[idx - 1] )
                continue;
                
            int l = idx + 1, r = len - 1;
            while ( l < r ) {
                const int sum = num[idx] + num[l] + num[r];
                int gap = abs( sum - target );
                if ( gap < min_gap ) {
                    min_gap = gap;
                    result = sum;
                }
                if ( target > sum ) while ( ++l < len && num[l - 1] == num[l] );
                else if ( target < sum ) while ( --r > idx && num[r + 1] == num[r] );
                else return target;
            }
        }
        return result;
    }
};