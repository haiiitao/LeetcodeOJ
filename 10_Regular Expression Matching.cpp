/**
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
 */
class Solution {
public:
    bool isMatch( string s, string p ) {
        const int lenS = s.size(), lenP = p.size();
        int i, j;
        bool checked[lenS + 1][lenP + 1];

        for ( j = 2, checked[0][0] = true, checked[0][1] = false; j <= lenP; j++ ) // match s[0..0]
            checked[0][j] = p[j - 1] == '*' ? checked[0][j - 2] : false;
        
        for ( i = 1; i <= lenS; i++ ) {
            for ( j = 1, checked[i][0] = false; j <= lenP; j++) {
                if ( p[j - 1] == '*' ) // case (1)
                    checked[i][j] = (j > 1) && ( checked[i][j - 2]  || ( ( checked[i - 1][j]) && (s[i - 1]== p[j - 2] || p[j - 2] == '.')) );
                else // case (2)
                    checked[i][j] = checked[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');        
            }
        }
        return checked[lenS][lenP];
    }
};

class Solution {
public:
    bool isMatch( string s, string p ) {
        if ( p.empty() )    
            return s.empty();

        if ( '*' == p[1] )
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
            return (isMatch( s, p.substr( 2 ) ) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch( s.substr( 1 ), p ));
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch( s.substr( 1 ), p.substr( 1 ) );
    }
};

class Solution {
public:
    bool isMatch( string s, string p ) {
        const int m = s.size(), n = p.size();
        bool f[m + 1][n + 1] = { false };
        f[0][0] = true;
        for ( int i = 1; i <= m; i++ )
            f[i][0] = false;
            
        for ( int j = 1; j <= n; j++ )
            f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];

        for ( int i = 1; i <= m; i++ ) {
            for ( int j = 1; j <= n; j++ ) {
                if ( p[j - 1] != '*' )
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                else
                    // p[0] cannot be '*' so no need to check "j > 1" here
                    f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];
            }
        }
        return f[m][n];
    }
};