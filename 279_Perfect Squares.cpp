/**
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
 */
class Solution {
public:
    int numSquares( int n ) {
        static vector<int> dp { 0 };
        while ( dp.size() <= n ) {
            int m = dp.size(), squares = INT_MAX, bnd = sqrt( m );
            for ( int i = 1; i <= bnd; i++)
                squares = min( squares, dp[m - i * i] + 1 );
            
            dp.push_back( squares );
        }
        return dp[n];
    }
};

class Solution {
public:
    int numSquares(int n) {
        while ( n % 4 == 0 )
            n /= 4;
            
        int f[n + 1] = {};
        fill_n( f, n + 1, INT_MAX - 1 );
        f[0] = 0;
        for ( int i = 1; i <= n; i++ ) {
            int bnd = sqrt( i );
            for ( int j =1; j <= bnd; j++ )
                f[i] = min( f[i - j * j] + 1, f[i] );
        }
        return f[n];
    }
};