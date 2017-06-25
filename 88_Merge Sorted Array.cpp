class Solution {
public:
    void merge( vector<int>& nums1, int m, vector<int>& nums2, int n ) {
        int k = m + n - 1, i = m - 1, j = n - 1;
        while ( i >= 0 || j >= 0 ) {
            int v1 = i >= 0 ? nums1[i] : INT_MIN;
            int v2 = j >= 0 ? nums2[j] : INT_MIN;
            if ( v1 >= v2 ) {
                i--;
                nums1[k--] = v1;
            } else {
                j--;
                nums1[k--] = v2;
            }
        }
    }
};