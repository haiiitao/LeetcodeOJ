class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int const len = nums.size();
        for ( int i = 0; i < len; i++ ) {
            while ( nums[i] != nums[nums[i] - 1] )
                swap( nums[i], nums[nums[i] - 1] );
        }
        vector<int> result;
        for ( int i = 0; i < len; i++ )
            if ( i + 1 != nums[i] )
                result.push_back( nums[i] );
    
        return result;
    }
};