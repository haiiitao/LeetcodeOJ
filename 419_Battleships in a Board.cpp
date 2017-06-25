class Solution {
public:
    int countBattleships( vector<vector<char>>& board ) {
        const int m = board.size(), n = !m ? 0 : board[0].size();
        int result = 0;
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( board[i][j] == '.' )
                    continue;
                
                if ( i && board[i - 1][j] == 'X' )
                    continue;
                    
                if ( j && board[i][j - 1] == 'X' )
                    continue;
                    
                result++;                        
            }
        }
        return result;
    }
};