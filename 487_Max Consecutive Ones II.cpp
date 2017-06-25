class Solution {
public:
    int findMaxConsecutiveOnes( vector<int>& nums ) {
        int l = 0, r = 0, len = nums.size();
        int count = 0, result = 0;
        while ( r < len ) {
            if ( nums[r] ) {
                count++;
                r++;
            } else if ( r - l == count ) {
                r++;
            } else {
                while ( l < r && nums[l] )
                    l++;
                
                l++;
                count = r - l;
            }
            result = max( result, r - l );
        }
        return result;
    }
};