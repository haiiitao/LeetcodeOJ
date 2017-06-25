/**
There are two sorted arrays nums1 and nums2 of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */
class Solution {
public:
    double findMedianSortedArrays( vector<int>& nums1, vector<int>& nums2 ) {
        const int total = nums1.size() + nums2.size();
        if ( total & 1 ) // odd
            return find_kth_elem( nums1, nums2, total / 2 + 1 );
        else // even
            return ( find_kth_elem( nums1, nums2, total / 2 + 1 ) +
                     find_kth_elem( nums1, nums2, total / 2 ) ) / 2.0;
    }
    
private:
    int find_kth_elem( vector<int>& nums1, vector<int>& nums2, int k ) {
        int begin1 = 0, begin2 = 0;
        while ( true ) {
            if ( nums1.size() - begin1 > nums2.size() - begin2 ) { // For convenience, always make size of nums2 larger than nums1.
                swap( nums1, nums2 );
                swap( begin1, begin2 );
            }
            
            if ( begin1 == nums1.size() ) 
                return nums2[begin2 + k - 1]; 
            
            if ( k == 1 ) 
                return min( nums1[begin1], nums2[begin2] );
                
            int k1 = min( k / 2, (int)nums1.size() - begin1 ), k2 = k - k1;
            int num1 = nums1[begin1 + k1 - 1], num2 = nums2[begin2 + k2 - 1];
            if ( num1 < num2 ) {
                k -= k1;
                begin1 += k1;
            } else if ( num1 > num2 ) {
                k -= k2;
                begin2 += k2;
            } else
                return num1;
        }
        return -1;
    }
};