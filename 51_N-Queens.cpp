class Solution {
public:
    vector<vector<string>> solveNQueens( int n ) {
        int cols[n] = {};
        bool b_cols[n] = {};
        bool b_diags[2 * n] = {};
        bool b_adiags[2 * n] = {};
        vector<vector<string>> result;
        dfs( 0, n, cols, b_cols, b_diags, b_adiags, result );
        return result;
    }
    void dfs( int i, int n, int cols[], 
            bool b_cols[], bool b_diags[], bool b_adiags[], vector<vector<string>>& result ) {
        if ( i == n ) {
            vector<string> path;
            for ( int i = 0; i < n; i++ ) {
                string row;
                for ( int j = 0; j < n; j++ ) 
                    row += (cols[j] == i ?' Q' : '.');
                
                path.push_back( row );
            }
            result.push_back( path );
            return;
        }
        for ( int j = 0; j < n; j++ ) {
            if ( b_cols[j] || b_diags[i + j] || b_adiags[i - j + n] )
                continue;
            
            cols[j] = i;
            b_cols[j] = true, b_diags[i + j] = true, b_adiags[i - j + n] = true;
            dfs( i + 1, n, cols, b_cols, b_diags, b_adiags, result );
            cols[j] = 0;
            b_cols[j] = false, b_diags[i + j] = false, b_adiags[i - j + n] = false;
        }
    }
};