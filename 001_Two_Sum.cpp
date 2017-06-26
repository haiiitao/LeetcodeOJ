class Solution {
public:
    vector<int> twoSum( vector<int>& nums, int target ) {
        unordered_map<int, int> revIdx;
        for ( int i = 0, len = nums.size(); i < len; i++ ) {
            auto it = revIdx.find( target - nums[i] );
            if ( it != revIdx.end() )
                return { it->second, i };
            
            revIdx[nums[i]] = i;
        }
        return { -1, -1 };
    }
};