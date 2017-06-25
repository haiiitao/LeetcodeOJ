/**
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false 
 */
class Solution {
public:
    bool isMatch( string s, string p ) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, asterisk = -1, match;
        while ( i < m ) {
            if ( j < n && p[j] == '*' ) {
                match = i; 
                asterisk = j++;
            } else if ( j < n && (s[i] == p[j] || p[j] == '?') ) {
                i++; 
                j++;
            } else if ( asterisk >= 0 ) {
                i = ++match;
                j = asterisk + 1;
            } else 
                return false;
        }
        
        while ( j < n && p[j] == '*' ) 
            j++;
            
        return j == n;
    }
};

class Solution {
public:
    bool isMatch( string s, string p ) {
        const int m = s.size(), n = p.size();
        if ( !n )
            return m == 0;
            
        bool f[n + 1] = {}; 
        f[0] = true;
        for ( int j = 1; j <= n; j++ )
            f[j] = f[j - 1] && p[j - 1] == '*';
            
        for ( int i = 1; i <= m; i++ ) {
            bool diag = i == 1;
            for ( int j = 1; j <= n; j++ ) {
                bool temp = f[j];
                if ( p[j - 1] == '*' ) 
                    f[j] |= f[j - 1];
                else 
                    f[j] = diag && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
            
                diag = temp;
            }
        }
        return f[n];
    }
};