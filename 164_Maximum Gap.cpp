/**
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 */
class Solution {
public:
int maximumGap( vector<int>& nums ) {
        const int len = nums.size();
        if ( len < 2 ) 
            return 0;
        
        int maxA[len], minA[len];
        fill_n( minA, len, INT_MAX ), fill_n( maxA, len, INT_MIN );
        int maxE = *max_element( nums.begin(), nums.end() );
        int minE = *min_element( nums.begin(), nums.end() );
        if ( maxE == minE ) 
            return 0;
            
        double bucket_size = double(maxE - minE) / (len - 1);
        for ( int i = 0; i < len; i++ ) {
            int index = (nums[i] - minE) / bucket_size;
            maxA[index] = max( maxA[index], nums[i] );
            minA[index] = min( minA[index], nums[i] );
        }
        
        int result = 0, prev = maxA[0];
        for ( int i = 1; i < len; i++ ) {
            if ( minA[i] == INT_MAX ) 
                continue;
                
            result = max( result, minA[i] - prev );
            prev = maxA[i];
        }
        return result;
    } 
};