/**
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
 */
class Solution {
public:
    int uniquePathsWithObstacles( vector<vector<int>>& obstacleGrid ) {
        if ( obstacleGrid.empty() )
            return 0;
            
        const int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int f[n] = { 0 };
        f[0] = 1;
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                int prev = j ? f[j - 1] : 0;   
                f[j] = obstacleGrid[i][j] ? 0 : f[j] + prev;
            }
        }
        return f[n - 1];
    }
};