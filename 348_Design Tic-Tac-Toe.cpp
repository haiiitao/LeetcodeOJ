class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe( int n ) {
        rows.resize( n );
        cols.resize( n );
        dia1 = 0;
        dia2 = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move( int row, int col, int player ) {
        int len = rows.size();
        if( player == 2) {
            rows[row]++;
            cols[col]++;
            if ( row == col ) dia1++;
            if ( row + col == len - 1 ) dia2++;
        } else {
            rows[row]--;
            cols[col]--;
            if ( row == col ) dia1--;
            if ( row + col == len - 1 ) dia2--;          
        }

        if ( rows[row] == len || cols[col] == len || dia1 == len || dia2 == len )
            return 2;
        else if ( rows[row] == -len || cols[col] == -len || dia1 == -len || dia2 == -len )
            return 1;
            
        return 0;
    }
    vector<int> rows, cols;
    int dia1, dia2;
};