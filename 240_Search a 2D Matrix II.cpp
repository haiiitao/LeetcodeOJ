/**
 * Description: Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 */
class Solution {
public:
    bool searchMatrix( vector<vector<int>>& matrix, int target ) {
        if ( matrix.empty() )
            return false;
            
        const int m = matrix.size(), n = matrix[0].size();
        if ( !m || !n || target < matrix[0][0] || target > matrix[m - 1][n - 1] )    
            return false;
        
        int i = 0, j = n - 1;
        while ( i < m && j >= 0 ) {
            if ( target == matrix[i][j] ) {
                return true;
            } else if ( target < matrix[i][j] ) {
                j--;
            } else { 
                i++;
            }
        }
        return false;
    }
};