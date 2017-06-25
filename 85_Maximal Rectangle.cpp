/**
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
 */
class Solution {
public:
    int maximalRectangle( vector<vector<char>>& matrix ) {
        if ( matrix.empty() )
            return 0;
            
        const int m = matrix.size(), n = matrix[0].size();
        int left[n] = { 0 }, right[n], height[n] = { 0 };
        fill_n( right, n, n ); 
        
        int result = 0;
        for ( int i = 0; i < m; i++ ) {
            int cur_left = 0, cur_right = n; 
            for ( int j = 0; j < n; j++ ) {   
                if ( matrix[i][j] == '1' ) {
                    height[j]++; 
                    left[j] = max( left[j], cur_left );
                } else {
                    height[j] = 0;
                    left[j] = 0; 
                    cur_left = j + 1;
                }
            }
            for ( int j = n - 1; j >= 0; j-- ) { 
                if ( matrix[i][j] == '1' )
                    right[j] = min( right[j], cur_right );
                else {
                    right[j] = n; 
                    cur_right = j;
                }    
            }
            for ( int j = 0; j < n; j++ )
                result = max( result, (right[j] - left[j]) * height[j] );
        }
        return result;
    }
};