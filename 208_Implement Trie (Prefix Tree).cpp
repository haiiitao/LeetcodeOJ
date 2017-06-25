class Trie {
public:
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
    
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert( string word ) {
        TrieNode* cur = root;
        for ( auto ch : word ) {
            int idx = ch - 'a';
            if ( !cur->child[idx] )
                cur->child[idx] = new TrieNode();
                
            cur = cur->child[idx];
        }
        cur->isEnd = true;       
    }
    
    /** Returns if the word is in the trie. */
    bool search( string word ) {
        TrieNode* cur = root;
        for ( auto ch : word ) {
            int idx = ch - 'a';
            if ( !cur->child[idx] )
                return false;
                
            cur = cur->child[idx];
        }
        return cur->isEnd;        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith( string prefix ) {
        TrieNode* cur = root;
        for ( auto ch : prefix ) {
            int idx = ch - 'a';
            if ( !cur->child[idx] )
                return false; 
                
            cur = cur->child[idx];
        }
        return true;        
    }
    TrieNode* root;
};