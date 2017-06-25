class WordDictionary {
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
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord( string word ) {
        TrieNode* cur = root;
        for ( auto ch : word ) {
            int idx = ch - 'a';
            if ( !cur->child[idx] )
                cur->child[idx] = new TrieNode();
                
            cur = cur->child[idx];
        }
        cur->isEnd = true;            
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search( string word ) {
        return search( root, word );
    }
    bool search( TrieNode* cur, string& word, int start = 0 ) { 
        for ( int i = start, len = word.size(); i < len; i++ ) {
            if ( word[i] != '.' ) {
                int idx = word[i] - 'a';
                if ( !cur->child[idx] )
                    return false;
                
                cur = cur->child[idx];
            } else {
                for ( int j = 0; j < 26; j++ )
                    if ( cur->child[j] && search( cur->child[j], word, i + 1 ) )
                        return true;
                
                return false;
            }
        }
        return cur->isEnd;
    }
    TrieNode* root;
};