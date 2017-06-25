/**
Description:

Count the number of prime numbers less than a non-negative number, n.
 */
class Solution {
public:
    int countPrimes( int n ) {
        if ( n <= 2 ) 
            return 0;

        bool primes[n];
        fill_n( primes, n, true );
        int sqr = sqrt( n );
        for ( int i = 2; i <= sqr; i++ ) {
            if ( primes[i] ) {
                for ( int j = i * i; j < n; j += i )
                    primes[j] = false;
            }
        }

        int result = 0;
        for ( int i = 2; i < n; i++ )
            if ( primes[i] ) result++;

        return result;
    }
};