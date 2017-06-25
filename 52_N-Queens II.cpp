class Solution {
public:
    int totalNQueens(int n) {
        int cols[n] = {};
        bool b_cols[n] = {};
        bool b_diags[2 * n] = {};
        bool b_adiags[2 * n] = {};
        int count = 0;
        dfs( 0, n, cols, b_cols, b_diags, b_adiags, count );   
        return count;
    }
        
    void dfs( int i, int n, int cols[], 
            bool b_cols[], bool b_diags[], bool b_adiags[], int& count ) {
        if ( i == n ) {
            count++;
            return;
        }
        for ( int j = 0; j < n; j++ ) {
            if ( b_cols[j] || b_diags[i + j] || b_adiags[i - j + n] )
                continue;
            
            cols[j] = i;
            b_cols[j] = true, b_diags[i + j] = true, b_adiags[i - j + n] = true;
            dfs( i + 1, n, cols, b_cols, b_diags, b_adiags, count );
            cols[j] = 0;
            b_cols[j] = false, b_diags[i + j] = false, b_adiags[i - j + n] = false;
        }
    }
};