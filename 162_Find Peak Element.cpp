/**
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
 */
class Solution {
public:
    int findPeakElement( vector<int>& nums ) {
        int left = 0, right = nums.size() - 1;
        while ( left != right ) {
            int mid = (left + right) / 2;
            if ( nums[mid + 1] > nums[mid] )
                left = mid + 1; // middle cannot be the peak
            else
                right = mid; // middle is always different from right
        }
        return left;
    }
};