class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = !m ? 0 : matrix[0].size();
        queue<pair<int, int>> q;
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( matrix[i][j] )
                    matrix[i][j] = INT_MAX;
                else
                    q.push( { i, j } );
            }
        }
        int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };
        while ( !q.empty() ) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for ( int k = 0; k < 4; k++ ) {
                int next_x = x + dir[k][0];
                int next_y = y + dir[k][1];
                if ( unsigned( next_x ) >= m || unsigned( next_y ) >= n || matrix[next_x][next_y] <= matrix[x][y] + 1 )
                    continue;
                
                matrix[next_x][next_y] = matrix[x][y] + 1;
                q.push( { next_x, next_y } );
            }
        }
        return matrix;
    }
};