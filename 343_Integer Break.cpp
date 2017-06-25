class Solution {
public:
    int integerBreak( int n ) {
        int f[n + 1] = { 0 };
        f[1] = 1;
        for ( int i = 2; i <= n; i++ )
            for ( int j = 1; j < i; j++ )
                f[i] = max( f[i], j * f[i - j] );
                
        return f[n];
    }
};