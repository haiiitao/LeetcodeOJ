/**
 * Description: Given an integer array of size n, 
 * find all elements that appear more than ⌊ n/3 ⌋ times. 
 * The algorithm should run in linear time and in O(1) space.
 */
class Solution {
public:
    vector<int> majorityElement( vector<int>& nums ) {
        int cnt1 = 0, cnt2 = 0, a, b;
        for ( auto num : nums ) {
            if ( cnt1 && a == num ) {
                cnt1++;
            } else if ( cnt2 && b == num ) {
                cnt2++;
            } else if ( !cnt1 ) {
                a = num;
                cnt1++;
            } else if ( !cnt2 ) {
                b = num;
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for ( auto num : nums ) {
            if ( num == a ) 
                cnt1++;
            else if ( num == b ) 
                cnt2++;
        }

        vector<int> result;
        if ( cnt1 > nums.size() / 3 ) result.push_back( a );
        if ( cnt2 > nums.size() / 3 ) result.push_back( b );
        
        return result;
    }
};