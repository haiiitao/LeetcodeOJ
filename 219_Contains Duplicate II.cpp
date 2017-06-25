/** Description: Given an array of integers and an integer k, 
 * find out whether there are two distinct indices i and j in the array,
 * such that nums[i] = nums[j] and the difference between i and j is at most k.
 */
class Solution {
public:
    bool containsNearbyDuplicate( vector<int>& nums, int k ) {
        unordered_set<int> window;
        for ( size_t i = 0, len = nums.size(); i < len; i++ ) {
            if ( i > k ) 
                window.erase( nums[i - k - 1] );
                
            if ( !window.insert( nums[i] ).second ) 
                return true;
        }
        return false;
    }
};