/**
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 */
class Solution {
public:
    int nthSuperUglyNumber( int n, vector<int>& primes ) {
        int f[n] = { 0 };
        f[0] = 1; // first super ugly number
        
        const int len = primes.size();
        int idxs[len] = { 0 };
        int cur_idx = 1;
        while ( cur_idx < n ) {
            int next = INT_MAX; // next super ugly number
            for ( int i = 0; i < len; i++ ) 
                next = min( next, f[idxs[i]] * primes[i] );
            
            for ( int i = 0; i < len; i++ )
                if( next == f[idxs[i]] * primes[i] )
                    idxs[i]++;
                    
            f[cur_idx++] = next;
            
        }
        return f[n - 1];
    }
};