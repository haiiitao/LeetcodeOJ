/**
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
 */
class Solution {
public:
    void wallsAndGates( vector<vector<int>>& rooms ) {
        static const int dir[][2] = { { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 } };
        queue<pair<int, int>> q;
        const int m = rooms.size(), n = m ? rooms[0].size() : 0;
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( !rooms[i][j] )
                    q.push( { i, j } );
            }
        }
        
        while ( !q.empty() ) {
            const int x = q.front().first; 
            const int y = q.front().second;
            const int dist = rooms[x][y] + 1;
            q.pop();
            for ( int i = 0; i < 4; i++ ) {
                const int next_x = x + dir[i][0];
                const int next_y = y + dir[i][1];
                if ( unsigned( next_x ) >= m || unsigned( next_y ) >= n  || rooms[next_x][next_y] <= dist )
                    continue;
                
                rooms[next_x][next_y] = dist;
                q.push( { next_x, next_y } );
            }
        }
    }
};