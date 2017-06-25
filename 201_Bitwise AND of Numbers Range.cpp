/**
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
 */
class Solution {
public:
    int rangeBitwiseAnd( int m, int n ) {
        int cnt = 0, diff = n - m, mask = ~0;
        while ( diff ) {
            diff >>= 1;
            cnt++;
        }

        for ( int i = 0; i < cnt; i++ ) {
            mask <<= 1;
        }
        return m & n & mask;
    }
};

// ==>
class Solution {
public:
    int rangeBitwiseAnd( int m, int n ) {
        if ( m == n )
            return n;
            
        int cnt = log( n - m ) / log( 2 ) + 1;
        int mask = ~0 ^ ((1 << cnt) - 1);
        return mask & m & n;
    }
};

class Solution {
public:
    int rangeBitwiseAnd( int m, int n ) {
        if ( m == n )
            return m;

        int mask = 0;
        for ( int i = 0, len = log2( n - m ); i <= len; i++ )
            mask += (1 << i);

        return m & n & ~mask;
    }
};