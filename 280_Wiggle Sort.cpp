/**
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
 */
class Solution {
public:
    void wiggleSort( vector<int>& nums ) {
        int flip = 1;
        for ( int i = 0, len = nums.size(); i < len - 1; i++ ) {
            if ( nums[i] > nums[i + 1] && flip == 1 ) {
                swap( nums[i], nums[i + 1] );
            } else if ( nums[i] < nums[i + 1] && flip == -1 ) {
                swap( nums[i], nums[i + 1] );
            }
            flip *= -1;
        }
    }
};