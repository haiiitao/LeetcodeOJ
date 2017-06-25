class Solution {
public:
    vector<pair<int, int>> pacificAtlantic( vector<vector<int>>& matrix ) {
        int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        const int m = matrix.size(), n = !m ? 0 : matrix[0].size();
        vector<vector<bool>> memo1( m, vector<bool>( n , false ) );
        vector<vector<bool>> memo2( m, vector<bool>( n , false ) );
        vector<pair<int, int>> result;
        for ( int i = 0; i < m; i++ ) {   
            dfs( i, 0, matrix, memo1, dir );
            dfs( i, n - 1, matrix, memo2, dir );
        }
        for ( int j = 0; j < n; j++ ) {   
            dfs( 0, j, matrix, memo1, dir );
            dfs( m - 1, j, matrix, memo2, dir );
        }
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ )
                if ( memo1[i][j] && memo2[i][j] )
                    result.push_back( { i, j } );
        }
        return result;
    }
    
    void dfs( int i, int j, vector<vector<int>>& matrix, vector<vector<bool>>& memo, int dir[][2] ) {
        if ( memo[i][j] )
            return;
          
        const int m = matrix.size(), n = !m ? 0 : matrix[0].size();  
        memo[i][j] = true;
        for ( int k = 0; k < 4; k++ ) {
            int i_next = i + dir[k][0];
            int j_next = j + dir[k][1];
            if ( unsigned( i_next ) >= m || unsigned( j_next ) >= n || matrix[i_next][j_next] < matrix[i][j] )
                continue;
            
            dfs( i_next, j_next, matrix, memo, dir );
        }
    }
};