/**
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. 
If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
 */
class Solution {
public:
    int search( vector<int>& nums, int target ) {
        int l = 0, r = nums.size() - 1;
        while ( l < r ) {
            int mid = (l + r) / 2;
            if ( nums[mid] == target )
                return mid;
                
            if ( nums[mid] >= nums[l] ) {
                if ( nums[l] <= target && target < nums[mid] )
                    r = mid - 1;
                else
                    l = mid + 1;
            } else { // nums[mid] < nums[l]
                if ( nums[mid] < target && target <= nums[r] )
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return l < nums.size() && nums[l] == target ? l : -1;
    }
};