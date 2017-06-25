class Solution {
    struct TrieNode {
        // Initialize your data structure here.
        TrieNode() {
            for ( int i = 0; i < 26; i++ ) child[i] = NULL;
            isEnd = false;
        }
        ~TrieNode() {
            for ( int i = 0; i < 26; i++ ) delete child[i];
        }
        TrieNode* child[26];
        bool isEnd;
    };
    
    void addWord( string& word ) {
        TrieNode* cur = root;
        for ( auto ch : word ) {
            int idx = ch - 'a';
            if ( !cur->child[idx] )
                cur->child[idx] = new TrieNode();
                
            cur = cur->child[idx];
        }
        cur->isEnd = true;            
    }
    void search( int i, int j, vector<string>& result, string& path, vector<vector<char>>& board,
            TrieNode* cur ) {
        const int m = board.size(), n = board[0].size();
        if ( unsigned(i) >= m || unsigned(j) >= n )
            return;
        
        char temp = board[i][j];
        if ( !temp )
            return;
        
        TrieNode* next = cur->child[temp - 'a'];
        if( !next )
            return;
        
        board[i][j] = 0;
        path.push_back( temp );
        if ( next->isEnd ) {
            next->isEnd = false;
            result.push_back( path );
        }
        search( i + 1, j, result, path, board, next );
        search( i - 1, j, result, path, board, next );
        search( i, j + 1, result, path, board, next );
        search( i, j - 1, result, path, board, next );
        path.pop_back();
        board[i][j] = temp;
    }
public:
    vector<string> findWords( vector<vector<char>>& board, vector<string>& words ) {
        root = new TrieNode();
        for ( auto& i : words )
            addWord( i );
        
        string path;
        vector<string> result;
        const int m = board.size(), n = !m ? 0 : board[0].size();
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                search( i, j, result, path, board, root );
            }
        }
        return result;
    }
    TrieNode* root;
};