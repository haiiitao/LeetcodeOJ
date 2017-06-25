/**
 * Description: Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
 * You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 *
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * Therefore, return the max sliding window as [3,3,5,5,6,7].
 */
class Solution {
public:
    vector<int> maxSlidingWindow( vector<int>& nums, int k ) {
        deque<int> dq;
        vector<int> result;
        for ( int i = 0, len = nums.size(); i < len; i++ ) {
            if ( !dq.empty() && dq.front() == i - k ) 
                dq.pop_front();
                
            while ( !dq.empty() && nums[dq.back()] < nums[i] )
                dq.pop_back();
                
            dq.push_back( i );
            if ( i >= k - 1 ) 
                result.push_back( nums[dq.front()] );
        }
        return result;
    }
};
