class Solution {
public:
    vector<int> twoSum( vector<int>& nums, int target ) {
        unordered_map<int, int> revIdx;
        unordered_map<int, int>::iterator found;
        for ( int i = 0, len = nums.size(); i < len; i++ ) {
            found = revIdx.find( target - nums[i] );
            if ( found != revIdx.end() )
                return { found->second, i };
            
            revIdx[nums[i]] = i;
        }
        return { -1, -1 };
    }
};