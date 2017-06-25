class Solution {
public:
    int getMoneyAmount( int n ) {
        int f[n + 2][n + 2] = {};
        for ( int d = 1; d <= n; d++ ) {
            for ( int l = 1; l + d <= n; l++) {
                int r = l + d;
                f[l][r] = INT_MAX;
                for ( int k = l; k <= r; k++ ) {
                    f[l][r] = min( f[l][r], k + max( f[l][k - 1], f[k + 1][r] ) );
                }
            }
        }
        return f[1][n];
    }
};