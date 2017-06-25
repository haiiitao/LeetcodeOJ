// Manancher-like solution
class Solution {
public:
    int minCut( string s ) {
        const int len = s.size();
        if ( len <= 1 ) 
            return 0;

        int minCUTS[len + 1];
        for ( int i = 0; i <= len; i++ ) 
            minCUTS[i] = i - 1;

        for ( int d = 1; d < len; d++ ) {
            for ( int j = 0; (d - j) >= 0 && (d + j) < len && s[d - j] == s[d + j]; j++ ) // odd-length substrings 
                minCUTS[d + j + 1] = min( minCUTS[d + j + 1], 1 + minCUTS[d - j] );
            
            for ( int j = 0; (d - j - 1) >= 0 && (d + j) < len && s[d - j - 1] == s[d + j]; j++ ) // even-length substrings
                minCUTS[d + j + 1] = min( minCUTS[d + j + 1], 1 + minCUTS[d - j - 1] );
        }
        return minCUTS[len];
    }
};

class Solution {
public:
    int minCut(string s) {
        const int len = s.size();
        int f[len + 1];
        bool p[len][len];
        fill_n( &p[0][0], len * len, false );
        
        //the worst case is cutting by each char
        for ( int i = 0; i <= len; i++ )
            f[i] = i - 1; 
            
        for ( int j = 0; j < len; j++ ) {
            for ( int i = j; i >= 0; i-- ) {
                if ( s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]) ) {
                    p[i][j] = true;
                    f[j + 1] = min( f[j + 1], f[i] + 1 );
                }
            }
        }
        return f[len];
    }
};