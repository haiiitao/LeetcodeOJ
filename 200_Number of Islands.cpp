/**
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
 */
class Solution {
public:
    int numIslands( vector<vector<char>>& grid ) {           
        const int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        function<void( int, int )> dfs = [&]( int i, int j ) {
            if ( unsigned( i ) >= m || unsigned( j ) >= n || grid[i][j] != '1' )
                return;
            
            grid[i][j] = '2';
            dfs( i - 1, j );
            dfs( i + 1, j );
            dfs( i, j - 1 );
            dfs( i, j + 1 );           
        };
        
        int count = 0; 
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( grid[i][j] != '1' ) 
                    continue;

                count++;
                dfs( i, j );
            }
        }
        return count;
    }
};

class Solution {
public:
    int numIslands( vector<vector<char>>& grid ) {           
        const int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        queue<pair<int, int>> q;
        int count = 0; 
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( grid[i][j] != '1' ) 
                    continue;
                
                q.push( { i, j } );
                while ( !q.empty() ) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    for ( int k = 0; k < 4; k++ ) {
                        int next_x = x + dir[k][0], next_y = y + dir[k][1];
                        if ( unsigned( next_x ) >= m || unsigned( next_y ) >= n || grid[next_x][next_y] != '1' )
                            continue;
                        
                        grid[next_x][next_y] = 2;
                        q.push( { next_x, next_y } );
                    }
                }
                count++;
            }
        }
        return count;
    }
};