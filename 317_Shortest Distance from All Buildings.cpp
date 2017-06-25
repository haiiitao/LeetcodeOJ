class Solution {
public:
    int shortestDistance( vector<vector<int>>& grid ) {
        const int m = grid.size(), n = !m ? 0 : grid[0].size();
        vector<vector<int>> memo( m, vector<int>( n, 0 ) );
        int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        queue<pair<int, int>> q, next_q;
        int num_buildings = 0;
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( grid[i][j] != 1 ) 
                    continue;
                    
                q.push( { i, j } );
                int dist = 1;
                while ( !q.empty() ) {
                    while( !q.empty() ) {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        for ( int k = 0; k < 4; k++ ) {
                            int next_x = x + dir[k][0], next_y = y + dir[k][1];
                            if ( unsigned( next_x ) >= m || unsigned( next_y ) >= n || grid[next_x][next_y] != -num_buildings )
                                continue;
                        
                            next_q.push( { next_x, next_y } );
                            memo[next_x][next_y] += dist; 
                            grid[next_x][next_y]--;
                        }
                    }
                    swap( q, next_q );
                    dist++;
                }
                num_buildings++;
            }
        }
        int result = INT_MAX;
        for ( size_t i = 0; i < m; i++ ) {
            for ( size_t j = 0; j < n; j++ ) {      
                if ( grid[i][j] == -num_buildings )
                    result = min( result, memo[i][j] );
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};