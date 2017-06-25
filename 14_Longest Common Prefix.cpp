/**
Write a function to find the longest common prefix string amongst an array of strings.
 */
class Solution {
public:
    string longestCommonPrefix( vector<string>& strs ) {
        if ( strs.empty() ) 
            return "";
        
        int len = strs[0].size();
        for ( int i = 1; i < strs.size(); i++ ) {
            for ( int j = 0; j < len; j++ ) {
                if ( strs[i][j] != strs[0][j] ) {
                    len = j;
                    break;
                }
            }
        }
        return strs[0].substr( 0, len );
    }
};