class Solution {
public:
    vector<int> findDisappearedNumbers( vector<int>& nums ) {
        int const len = nums.size();
        for ( int i = 0; i < len; i++ ) {
            while ( nums[i] != nums[nums[i] - 1] )
                swap( nums[i], nums[nums[i] - 1] );
        }
        vector<int> result;
        for ( int i = 0; i < len; i++ )
            if ( i + 1 != nums[i] )
                result.push_back( i + 1 );
    
        return result;
    }
};