class Solution {
public:
    bool canWin( string s ) {
        unordered_map<string, bool> cache;
        return canWin( s, cache );
    }
    bool canWin( string& s, unordered_map<string, bool>& cache ) { 
        auto it = cache.find( s );
        if ( it != cache.end() )
            return it->second;
            
        for ( int i = 0, len = s.size(); i < len - 1; i++ ) {
            if ( s[i] == '+' && s[i + 1] == '+' ) {
                s[i] = s[i + 1] = '-';
                if ( !canWin( s, cache ) ) {
                    s[i] = s[i + 1] = '+';
                    return cache[s] = true;;
                }
                s[i] = s[i + 1] = '+';
            }  
        }
        return cache[s] = false;
    }
};