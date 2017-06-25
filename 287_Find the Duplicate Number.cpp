/**
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
 */
class Solution {
public:
    int findDuplicate( vector<int>& nums ) {
        int a = 0, b = 0;
        do {
            a = nums[nums[a]];
            b = nums[b]; 
            
        } while (a != b);
        
        b = 0;
        while ( a != b ) { 
            a = nums[a];
            b = nums[b];
        }
        return a;
    }
};

class Solution {
public:
    int findDuplicate( vector<int>& nums ) {
        int left = 0, right = nums.size();
        while ( left < right ) {
            int mid = (left + right) / 2;
            int counter = 0;
            for ( auto i : nums ) {
                if ( i <= mid )
                    counter++;
            }
            if ( counter > mid )
                right = mid;
            else 
                left = mid + 1;
        }
        return left;
    }
};