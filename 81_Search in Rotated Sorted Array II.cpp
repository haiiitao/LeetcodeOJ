/**
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
 */
class Solution {
public:
    bool search( vector<int>& nums, int target ) {
        int left = 0, right = nums.size() - 1;
        while ( left <= right ) {
            int mid = ( left+ right ) / 2;
            if ( nums[mid] == target )
                return true;
            
            if ( nums[right] < nums[mid] ) {
                if ( nums[left] <= target && target < nums[mid] )
                    right = --mid;
                else
                    left = ++mid;
            } else if ( nums[right] > nums[mid] ) {
                if ( nums[mid] < target && target <= nums[right] )
                    left = ++mid;
                else
                    right = --mid;               
            } else
                right--;
        }
        return  false;
    }
};