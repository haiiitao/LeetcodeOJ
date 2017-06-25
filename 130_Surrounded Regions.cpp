class Solution {
public:
    void solve( vector<vector<char>>& board ) {
        int dir[4][2] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
        const int m = board.size(), n = !m ? 0 : board[0].size();
        for ( int i = 0; i < m; i++ ) {
            bfs( i, 0, dir, board );
            bfs( i, n - 1, dir, board );
        }
        for ( int j = 0; j < n; j++ ) {
            bfs( 0, j, dir, board );
            bfs( m - 1, j, dir, board );
        }
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) 
                board[i][j] = board[i][j] == '#' ? 'O' : 'X';
        }
    }
    
    void bfs( int i, int j, int dir[][2], vector<vector<char>>& board ) {
        const int m = board.size(), n = board[0].size();
        if ( board[i][j] != 'O' )
            return;
        
        queue<pair<int, int>> q;
        q.push( { i, j } );
        board[i][j] = '#';
        while( !q.empty() ) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for ( int k = 0; k < 4; k++ ) {
                int next_x = x + dir[k][0], next_y = y + dir[k][1];
                if ( unsigned( next_x ) >= m || unsigned( next_y ) >= n || board[next_x][next_y] != 'O' )
                    continue;
                
                board[next_x][next_y] = '#';
                q.push( { next_x, next_y } );
            }
        }
    }
};