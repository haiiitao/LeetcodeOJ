class Solution {
    class TrieNode {
        public:
        TrieNode* child[2];
        TrieNode() {
            child[0] = NULL;
            child[1] = NULL;
        }
    };
public:
    void insert( int num, TrieNode* root ) {
        for ( int i = 31; i >= 0; i-- ) {
            int bit = num >> i & 1;
            if ( !root->child[bit])
                root->child[bit] = new TrieNode();
            
            root = root->child[bit];
        }
    }
    
    int findMaximumXOR( vector<int>& nums ) {
        TrieNode* root = new TrieNode;
        for ( auto num : nums )
            insert( num, root );

        int result = 0;
        for ( auto num : nums ) {
            TrieNode* p = root;
            int temp = 0;
            for ( int i = 31; i >= 0; i-- ) {
                int bit = num >> i & 1;
                if ( p->child[1 - bit] ) {
                    temp |= 1 << i;
                    p = p->child[1 - bit];
                } else 
                    p = p->child[bit];
            }
            result = max( result, temp );
        }
        return result;
    }
};