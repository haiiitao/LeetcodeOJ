class Solution {
public:
    bool checkSubarraySum( vector<int>& nums, int k ) {
        int sum = 0, prev = 0;
        unordered_set<int> cache;
        for ( int i = 0, len = nums.size(); i < len; i++ ) {
            sum += nums[i];
            sum = !k ? sum : sum % k;
            if ( cache.count( sum ) )
                return true;
            
            cache.insert( prev );
            prev = sum;
        }
        return false;
    }
};