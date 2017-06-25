/**Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
 *
 * For example, given the following matrix:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * Return 4.
 */
class Solution {
public:
    int maximalSquare( vector<vector<char>>& matrix ) {
        int result = 0;
        const int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();
        int f[n];
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0, prev = 0; j < n; j++ ) {
                int diag = (i && j) ? prev : 0;
                int vert = (i) ? f[j] : 0;
                int hori = (j) ? f[j - 1] : 0;
                prev = f[j];
                f[j] = (matrix[i][j] == '1') ? min( diag, min( vert, hori ) ) + 1 : 0;
                result = max( result, f[j] );
            }
        }
        return result * result;
    }
};

class Solution {
public:
    int maximalSquare( vector<vector<char>>& matrix ) {
        int result = 0;
        const int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();
        vector<vector<int>> f( m, vector<int>( n, 0 ) );
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                int diag = (i && j) ? f[i - 1][j - 1] : 0;
                int vert = (i) ? f[i - 1][j] : 0;
                int hori = (j) ? f[i][j - 1] : 0;
                f[i][j] = (matrix[i][j] == '1') ? min( diag, min( vert, hori ) ) + 1 : 0;
                result = max( result, f[i][j] );
            }
        }
        return result * result;
    }
};