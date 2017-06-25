class Solution {
public:
    int findMaxConsecutiveOnes( vector<int>& nums ) {
        int count = 0;
        int result = 0;
        nums.push_back( 0 );
        for ( auto num : nums ) {
            if ( !num ) {
                result = max( result, count );
                count = 0;
            } else
                count++;
        }
        return result;
    }
};