/**
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
 */
class Solution {
public:
    string countAndSay( int n ) {
        string result( "1" );
        while ( --n > 0 ) {
            stringstream ss;
            for ( size_t i = 0, len = result.size(); i < len; ) {
                size_t pos = result.find_first_not_of( result[i], i );
                if ( pos == string::npos ) pos = len;
                ss << pos - i << result[i];
                i = pos;
            }
            result = ss.str();
        }
        return result;
    }
};