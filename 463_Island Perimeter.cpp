class Solution {
public:
    int islandPerimeter( vector<vector<int>>& grid ) {
        const int m = grid.size(), n = !m ? 0 : grid[0].size();
        int result = 0;
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( !grid[i][j] || grid[i][j] == -1 )
                    continue;
                    
                dfs( i, j, grid, result );
            }
        }
        return result;
    }
    void dfs( int i, int j, vector<vector<int>>& grid, int& result ) {
        const int m = grid.size(), n = !m ? 0 : grid[0].size();
        static int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        if ( !grid[i][j] )
            return;
        
        grid[i][j] = -1;
        result += 4;
        for ( int k = 0; k < 4; k++ ) {
            int next_i = i + dir[k][0];
            int next_j = j + dir[k][1];
            if ( unsigned(next_i) >= m || unsigned(next_j) >= n || !grid[next_i][next_j])
                continue;
            
            result--;
            if ( grid[next_i][next_j] == -1 )
                continue;
            
            dfs( next_i, next_j, grid, result );
        }
    }
};