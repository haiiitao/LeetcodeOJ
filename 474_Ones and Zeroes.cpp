class Solution {
public:
    int findMaxForm( vector<string>& strs, int m, int n ) {
        vector<vector<int>> f( m + 1, vector<int>( n + 1, 0 ) );
        for ( auto& str : strs ) {
            int zero_count = 0;
            int one_count = 0;
            for ( auto ch : str ) {
                if ( ch == '0' )
                    zero_count++;
                else
                    one_count++;      
            }
            for ( int i = m; i >= zero_count; i-- ) {
                for ( int j = n; j >= one_count; j-- ) {
                    f[i][j] = max( f[i][j], f[i - zero_count][j - one_count] + 1 );
                }
            }
        }
        return f[m][n];
    }
};