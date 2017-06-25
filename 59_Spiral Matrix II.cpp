/**
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
 */
class Solution {
public:
    vector<vector<int> > generateMatrix( int n ) {
        vector<vector<int>> matrix( n, vector<int>( n ) );
        if ( n ) {
            int count = 1;
            for ( int i = 0; i < n / 2; i++ ) {
                for ( int j = i; j < n - i - 1; j++ ) 
                	matrix[i][j] = count++;

                for ( int j = i; j < n - i - 1; j++ ) 
                	matrix[j][n - i - 1] = count++;

                for ( int j = i; j < n - i - 1; j++ ) 
                	matrix[n - i - 1][n - j - 1] = count++;

                for ( int j = i; j < n - i - 1; j++ ) 
                	matrix[n - j - 1][i] = count++;
            }
            if ( n % 2 )
                matrix[n / 2][n / 2] = count;
        }
        
        return matrix;
    }
};