class Solution {
public:
    vector<string> findMissingRanges( vector<int>& nums, int lower, int upper ) {
        long prev = (long)lower - 1;
        vector<string> result;
        for ( int i = 0, len = nums.size(); i < len; i++ ) {
            if ( nums[i] == 2 + prev )
                result.push_back( to_string( prev + 1 ) );
            else if ( nums[i] > 2 + prev )
                result.push_back( to_string( prev + 1 ) + "->" + to_string( nums[i] - 1 ) );
            
            prev = nums[i];
        }
        if ( upper - prev == 1 )
            result.push_back( to_string( upper ) );
        else if (  upper - prev > 1 )
            result.push_back( to_string( prev + 1 ) + "->" + to_string( upper ) );
        
        return result;
    }
};