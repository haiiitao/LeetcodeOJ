/**
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
 */
class Solution {
public:
    int minPathSum( vector<vector<int>>& grid ) {
        if ( grid.empty() ) 
            return 0;
    
        const int m = grid.size(), n = grid[0].size();
        int f[n];
        fill_n( f, n, INT_MAX ); 
        f[0] = 0;
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                int prev = j ? f[j - 1] : INT_MAX;
                f[j] = grid[i][j] + min( f[j], prev );
            }
        }
        return f[n - 1];
    }
};