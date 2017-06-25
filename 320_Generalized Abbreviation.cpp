/**
Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 */
class Solution {
public:
    vector<string> generateAbbreviations( string word ) {
        vector<string> result;
        string path = "";
        dfs( result, path, word, 0, false );
        
        return result;
    }
    void dfs( vector<string>& result, string& path, string& word, int idx, bool b_num ) {
        int len = word.size();
        if ( idx == len ) {
            result.push_back( path );
            return;
        }
        if ( !b_num ) {
            for ( int i = idx + 1; i <= len; i++ ) {
                if ( i - idx <= 9 ) {
                    path.push_back( '0' + i - idx );
                    dfs( result, path, word, i, true );
                    path.pop_back();
                    continue;
                }
                string str_Num = to_string( i - idx );
                path += str_Num;
                dfs( result, path, word, i, true );
                for ( size_t j = 0, len1 = str_Num.size(); j < len1; j++ )
                    path.pop_back();
            }
        }
        path.push_back( word[idx] );
        dfs( result, path, word, idx + 1, false );
        path.pop_back();
    }
};