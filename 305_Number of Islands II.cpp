/**
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]
 */
class Solution {
public:
    vector<int> numIslands2( int m, int n, vector<pair<int, int>>& positions ) {
        vector<int> result;
        int f[m * n];
        fill_n( f, m * n, -1 );
        const int dirs[][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        int island = 0;
        
        for ( auto& pos : positions ) {
            const int x = pos.first;
            const int y = pos.second;
            const int idx = x * n + y;
            f[idx] = idx;
            ++island;
            for ( int k = 0; k < 4; k++ ) {
                const int row = x + dirs[k][0];
                const int col = y + dirs[k][1];
                const int next_idx = row * n + col;
                if ( unsigned( row ) >= m || unsigned( col ) >= n || f[next_idx] == -1 ) 
                    continue;
                    
                const int root1 = findRoot( next_idx, f );
                const int root2 = findRoot( idx, f );
                if ( root2 != root1 ) {
                    f[root1] = root2;
                    --island;
                }
            }
            result.push_back( island );
        }
        
        return result;
    }

private:
    int findRoot( int i, int f[] ) {
        while ( i != f[i] ) {
            f[i] = f[f[i]]; 
            i = f[i];
        }
        return i;
    }
};

