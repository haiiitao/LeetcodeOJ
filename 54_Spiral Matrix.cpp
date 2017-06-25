/**
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
class Solution {
public:
    vector<int> spiralOrder( vector<vector<int>>& matrix ) {
        if ( matrix.empty() )
            return vector<int>();
        
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> result( m * n, 0 );
        int left = 0, right = n - 1, top = 0, bottom = m - 1, idx = 0;
        while ( left < right && top < bottom ) {
            for ( int i = left; i < right; i++ )
                result[idx++] = matrix[top][i];

            for ( int i = top; i < bottom; i++ )
                result[idx++] = matrix[i][right];

            for ( int i = right; i > left; i-- )
                result[idx++] = matrix[bottom][i];

            for ( int i = bottom; i > top; i-- )
                result[idx++] = matrix[i][left];
                
            left++, right--, top++, bottom--;
        }

        if ( left == right ) {
            for ( int i = top; i <= bottom; i++ )
                result[idx++] = matrix[i][left];
        } else if ( top == bottom ) {
            for ( int i = left; i <= right; i++ )
                result[idx++] = matrix[top][i];
        }
        
        return result;
    }
};