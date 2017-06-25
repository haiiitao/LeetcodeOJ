/**
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
 */
// LeetCode, Sudoku Solver
class Solution {
public:
    bool solveSudoku( vector<vector<char>>& board ) {
        for ( int i = 0; i < 9; i++ ) {
            for ( int j = 0; j < 9; j++ ) {
                if ( board[i][j] != '.' )
                    continue;
                    
                for ( int k = 0; k < 9; k++ ) {
                    board[i][j] = '1' + k;
                    if ( isValid( board, i, j ) && solveSudoku( board ) )
                        return true;
                        
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }
    
private:
    bool isValid( const vector<vector<char>>& board, int x, int y ) {
        for ( int i = 0; i < 9; i++ ) // check column
            if ( i != x && board[i][y] == board[x][y] )
                return false;
                
        for ( int j = 0; j < 9; j++ ) // check row
            if ( j != y && board[x][j] == board[x][y] )
                return false;
        
        int boundX = 3 * (x / 3), boundY = 3 * (y / 3);
        for ( int i = boundX; i < boundX + 3; i++ )
            for ( int j = boundY; j < boundY + 3; j++ )
                if ( (i != x || j != y) && board[i][j] == board[x][y] )
                    return false;
                    
        return true;
    }
};