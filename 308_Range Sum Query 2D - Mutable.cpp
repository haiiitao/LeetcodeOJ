class NumMatrix {
public:
    NumMatrix( vector<vector<int>>& matrix ) : num( matrix ) {
        m = matrix.size();
        if ( !m ) 
            return;
            
        n = matrix[0].size();
        tree = vector<vector<int>>( m + 1, vector<int>( n + 1, 0 ) );
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                modify( i, j, num[i][j] );
            }
        }
    }

    void update( int row, int col, int val ) {
        modify( row, col, val - num[row][col] );
        num[row][col] = val;
    }

    int sumRegion( int row1, int col1, int row2, int col2 ) {
        return read( row2, col2 ) - read( row1 - 1, col2 ) - read( row2, col1 - 1 ) + read( row1 - 1, col1 - 1 );
    }

private:
    void modify( int row, int col, int val ) {
        for ( int i = row + 1; i <= m; i += i & (-i) ) {
            for ( int j = col + 1; j <= n; j += j & (-j) ) {
                tree[i][j] += val;
            }
        }
    }

    int read( int row, int col ) {
        int sum = 0;
        for ( int i = row + 1; i > 0; i -= i & (-i) ) {
            for ( int j = col + 1; j > 0; j -= j & (-j) ) {
                sum += tree[i][j];
            }
        }
        return sum;
    }

    vector<vector<int>> tree;
    vector<vector<int>> num;
    int m;
    int n;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);