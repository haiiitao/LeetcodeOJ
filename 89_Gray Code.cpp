/**
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
*/
class Solution {
public:
    vector<int> grayCode( int n ) {
        vector<int> result;
        result.push_back( 0 );
        for ( int i = 0; i < n; i++ ) {
            size_t len = result.size();
            int b = 1 << i;
            for ( int j = len - 1; j >= 0; j-- )
                result.push_back( b | result[j] );
        }
        return result;
    }
};