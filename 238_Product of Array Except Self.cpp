/**
 * Description: Given an array of n integers where n > 1, 
 * nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 *
 * Solve it without division and in O(n).
 *
 * For example, given [1,2,3,4], return [24,12,8,6].
 */
class Solution {
public:
    vector<int> productExceptSelf( vector<int>& nums ) {
        const int len = nums.size();
        vector<int> result( len );
        int before = 1;
        for ( int i = 0; i < len; i++ ) {
            result[i] = before;
            before *= nums[i];
        }
        
        int after = 1;
        for ( int i = len - 1; i >= 0; i-- ) {
            result[i] *= after;
            after *= nums[i];
        }
        return result;
    }
};

// one pass
class Solution {
public:
    vector<int> productExceptSelf( vector<int>& nums ) {
        const int len = nums.size();
        vector<int> result( len, 1 );
        int l = 1, r = 1;
        for ( int i = 0, j = len - 1; i < len; i++, j-- ) {
            result[i] *= l;
            result[j] *= r;
            l *= nums[i];
            r *= nums[j];
        }
        return result;
    }
};