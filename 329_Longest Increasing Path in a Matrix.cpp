/**
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 */
class Solution {
public:
    int longestIncreasingPath( vector<vector<int>>& matrix ) {
        const static int dirs[][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        const int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size(); 
        vector<vector<int>> memo( m, vector<int>( n, 0 ) );
        
        function<int( int, int )> dfs = [&]( int i, int j ) {
            if ( !memo[i][j] ) {
                memo[i][j] = 1;
                for ( int k = 0; k < 4; k++ ) {
                    const int next_x = i + dirs[k][0];
                    const int next_y = j + dirs[k][1];
                    if ( unsigned( next_x ) >= m || unsigned( next_y ) >= n || matrix[next_x][next_y] <= matrix[i][j] ) 
                        continue;

                    memo[i][j] = max( memo[i][j], dfs( next_x, next_y ) + 1 );
                }
            }
            return memo[i][j];           
        };
        
        int ret = 0;
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                ret = max( ret, dfs( i, j ) );
            }
        }
        return ret;
    }
};