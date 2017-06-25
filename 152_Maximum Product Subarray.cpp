/**
Find the contiguous subarray within an array (containing at least one number) 
which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
 */
class Solution {
public:
    int maxProduct( vector<int>& nums ) {
        int result = INT_MIN, max_product = 1, min_product = 1;
        for ( auto num : nums ) {
            const int min_temp = min_product * num;
            const int max_temp = max_product * num;
            min_product = min( min( min_temp, max_temp ), num );
            max_product = max( max( min_temp, max_temp ), num );
            result = max( result, max_product );
        }
        return result;
    }
};