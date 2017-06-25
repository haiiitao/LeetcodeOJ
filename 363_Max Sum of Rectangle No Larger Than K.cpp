class Solution {
public:
    int maxSumSubmatrix( vector<vector<int>>& matrix, int k ) {
        const int m = matrix.size(), n = m ? matrix[0].size() : 0;
        int f[m], result = INT_MIN;
        for ( int left = 0; left < n; left++ ) {
            fill_n( f, m, 0 );
            for ( int right = left; right < n; right++ ) {
                for ( int i = 0; i < m; i++ )
                    f[i] += matrix[i][right];
                
                set<int> set_Acc;
                set_Acc.insert( 0 );
                int acc = 0;
                for ( int i = 0; i < m; i++ ) {
                    acc += f[i];
                    auto it = set_Acc.lower_bound( acc - k );
                    if ( it != set_Acc.end () )
                        result = max( result, acc - *it );
                    
                    set_Acc.insert( acc );
                }
            }
        }
        return result;
    }
};