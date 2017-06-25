class Solution {
public:
    bool exist( vector<vector<char>>& board, string word ) {
        const int m = board.size();
        const int n = m ? board[0].size() : 0;
        for ( size_t i = 0; i < m; i++ )
            for ( size_t j = 0; j < n; j++ )
                if ( dfs( board, word, 0, i, j ) )
                    return true;
                    
        return false;
    }
    
    bool dfs( vector<vector<char>>& board, string& word, int idx, int i, int j ) {
        if ( idx == word.size() )
            return true;
            
        if ( unsigned( i ) >= board.size() || unsigned( j ) >= board[0].size() || board[i][j] != word[idx] )
            return false;
        
        board[i][j] = '#';
        if ( dfs( board, word, idx + 1, i + 1, j ) ||
                dfs( board, word, idx + 1, i - 1, j ) ||
                dfs( board, word, idx + 1, i, j + 1 ) ||
                dfs( board, word, idx + 1, i, j - 1 ) )
            return true;
            
        board[i][j] = word[idx];
        return false;
    }
};