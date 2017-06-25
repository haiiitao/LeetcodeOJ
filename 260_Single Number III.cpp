/**
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity? 
 */
class Solution {
public:
    vector<int> singleNumber( vector<int>& nums ) {
        int diff = 0, a = 0, b = 0;
        for ( auto num : nums )
            diff ^= num;

        diff &= -diff;
        for ( auto num : nums ) 
            num & diff ? a ^= num : b ^= num;
        
        return { a, b };
    }
};