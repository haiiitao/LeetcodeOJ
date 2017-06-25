/**
 * Description: Given a string s and a dictionary of words dict, 
 * determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 * 
 * Return true because "leetcode" can be segmented as "leet code".
 */
class Solution {
public:
    bool wordBreak( string s, unordered_set<string>& dict ) {
        const int len = s.size();
        bool f[len + 1];
        fill_n( f, len, false );
        f[len] = true;
        for ( int i = len - 1; i >= 0; i-- ) {
            for ( int j = i + 1; j <= len; j++ ) {
                if ( f[j] && dict.count( s.substr( i, j - i ) ) ) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[0];
    }
};

// ==> another direction
class Solution {
public:
    bool wordBreak( string s, unordered_set<string> &dict ) {
        const int len = s.size();
        bool f[len + 1];
        fill_n( f, len + 1, false );
        f[0] = true;
        for ( int i = 1; i <= len; i++ ) {
            for ( int j = i - 1; j >= 0; j-- ) {
                if ( f[j] && dict.count( s.substr( j, i - j ) ) ) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[len];
    }
};