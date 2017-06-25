/**
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
 */
class Solution {
public:
    bool isPerfectSquare( int num ) {
        int low = 1,  high = num;
        while ( low < high ) {
            int mid = (low + high) / 2;
            if ( num / mid > mid ) 
                low = mid + 1;
            else 
                high = mid;
        }
        return low * low == num;
       
    }
};