/**
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
 */
class Solution {
public:
    int nthUglyNumber( int n ) {
        int f[n] = { 1 };
        int *t2 = f, *t3 = f, *t5 = f, idx = 0;
        while ( ++idx < n ) {
            const int n2 = *t2 * 2, n3 = *t3 * 3, n5 = *t5 * 5;
            f[idx] = min( n2, min( n3, n5 ) );
            if ( n2 == f[idx] ) ++t2;
            if ( n3 == f[idx] ) ++t3;
            if ( n5 == f[idx] ) ++t5;
        }
        return f[n - 1];
    }
};