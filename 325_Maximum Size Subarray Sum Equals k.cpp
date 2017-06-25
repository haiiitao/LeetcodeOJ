class Solution {
public:
    int maxSubArrayLen( vector<int>& nums, int k ) {
        unordered_map<int, int> revIdx;
        revIdx[0] = -1;
        int result = 0, sum = 0;
        for ( int i = 0, len = nums.size(); i < len; i++ ) {
            sum += nums[i]; // accumulator
            auto it_target = revIdx.find( sum - k );
            if ( it_target != revIdx.end() ) 
                result = max( result, i - it_target->second );
            
            auto it_sum = revIdx.find( sum ); 
            if ( it_sum == revIdx.end() )
                revIdx[sum] = i; // update reversed index map
        }
        return result;
    }
};