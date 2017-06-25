/**
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
 */
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        const int len = nums.size();
        long sums[len + 1] = { 0 };
        for ( int i = 0; i < len; i++ )  
            sums[i + 1] = sums[i] + nums[i];
            
        return help( sums, 0, len + 1, lower, upper );
    }

    int help( long sums[], int start, int end, int lower, int upper ) {
        if ( end - start == 1 )  
            return 0;
            
        int mid = (start + end) / 2;
        int count = help( sums, start, mid, lower, upper ) + help( sums, mid, end, lower, upper );
        int m = mid, n = mid;
        for ( int i = start; i < mid; i++ ) {
            while ( m < end && sums[m] - sums[i] < lower ) m++;
            while ( n < end && sums[n] - sums[i] <= upper ) n++;
            count += n - m;
        }
        // merge sums[start, mid) and sums[mid, end);
        long buffer[end - start];
        int iA = start, iB = mid, iC = 0;
        while ( iA < mid && iB < end ) buffer[iC++] = sums[iA] < sums[iB] ? sums[iA++] : sums[iB++];
        while ( iA < mid ) buffer[iC++] = sums[iA++];  
        while ( iB < end ) buffer[iC++] = sums[iB++];
        for ( int i = 0; i < end - start; i++ )
            sums[start + i] = buffer[i];
            
        return count;
    }
};