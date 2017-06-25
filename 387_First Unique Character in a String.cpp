class Solution {
public:
    int firstUniqChar( string s ) {
        int counter[128] = { 0 };
        for ( auto ch : s )
            counter[ch] ++;
            
        for ( int i = 0, len = s.size(); i < len; i++ )
            if ( counter[s[i]] == 1 )
                return i;
        
        return -1;
    }
};