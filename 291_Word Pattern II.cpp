/**
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
Notes:
You may assume both pattern and str contains only lowercase letters.
 */
class Solution {
public:
    bool wordPatternMatch( string pattern, string str ) {
        return dfs( pattern, str, 0, 0 );
    }

private:
    bool dfs( string& pattern, string& str, int pi, int si ) {
        if ( pattern.size() == pi ) 
            return str.size() == si;
        
        auto found = mapping.find( pattern[pi] );
        if ( found != mapping.end() ) {
            const string& value = found->second;
            const int value_len = value.size();
            if ( value_len > str.size() - si || str.substr( si, value_len ) != value ) 
                return false;
                
            if ( dfs( pattern, str, pi + 1, si + value_len ) ) 
                return true;
        } else {
            for ( int i = si + 1, str_len = str.size(); i <= str_len; i++ ) {
                string candidate = str.substr( si, i - si );
                if ( pattern.find( pattern[pi], pi + 1 ) != string::npos && str.find( candidate, i ) == string::npos ) 
                    continue;
                
                if ( !visited.insert( candidate ).second ) 
                    continue;
                    
                mapping[pattern[pi]] = candidate;
                if ( dfs( pattern, str, pi + 1, i ) )
                    return true;
                    
                mapping.erase( pattern[pi] );
                visited.erase( candidate );
            }
        }
        return false;        
    }
    unordered_map<char, string> mapping;
    unordered_set<string> visited;
};