/**
 * Description: Given a string s and a dictionary of words dict, 
 * add spaces in s to construct a sentence where each word is a valid dictionary word.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 * 
 * A solution is ["cats and dog", "cat sand dog"].
 */
class Solution {
public:
    vector<string> wordBreak( string s, unordered_set<string>& wordDict ) {
        const int len = s.size();
        bool f[len + 1] = { false };
        f[len] = true;
        for ( int i = len - 1; i >= 0; i-- ) {
            for ( int j = i + 1; j <= len; j++ ) {
                if ( f[j] && wordDict.count( s.substr( i, j - i ) ) ) {
                    f[i] = true;
                    break;
                }
            }
        }

        vector<string> result;
        function<void( int, string )> dfs = [&]( int idx, string path ) {
            if ( idx == len ) {
                path.erase( path.begin() );
                result.push_back( path );
                return ;
            }
            for ( int i = idx + 1; i <= len; i++ ) {
                string str( s, idx, i - idx );
                if ( f[i] && wordDict.count( str ) ) {
                    dfs( i, path + " " + str );
                }
            }            
        };
        if ( f[0] ) 
            dfs( 0, "" );
            
        return result;
    }
};