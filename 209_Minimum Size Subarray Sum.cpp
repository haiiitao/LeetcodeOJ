/**
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
 */
class Solution {
public:
    int minSubArrayLen( int s, vector<int>& nums ) {
        int result = INT_MAX, len = nums.size();
        int left = 0, right = 0, sum = 0;

        while ( right < len ) {
            sum += nums[right++];
            while ( sum >= s ) {
                result = min( right - left, result );
                sum -= nums[left++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};