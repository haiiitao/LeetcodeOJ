/**
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
 */
class Solution {
public:
    string largestNumber( vector<int>& nums ) {
        auto cmp = []( int lhs, int rhs ) {
            string strL( to_string( lhs ) );
            string strR( to_string( rhs ) );
            return (strL + strR) > (strR + strL);
        };
    
        sort( nums.begin(), nums.end(), cmp );
        if ( !nums.empty() && nums[0] == 0 )
            return "0";
        
        stringstream ss;
        for ( auto v : nums ) ss << v;
        
        return ss.str();
    }
};