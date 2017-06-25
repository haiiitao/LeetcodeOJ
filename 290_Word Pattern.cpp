/**
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
 */
class Solution {
public:
    bool wordPattern( string pattern, string str ) {
        unordered_map<char, string> map_c2s;
        unordered_map<string, char> map_s2c;
        vector<string> vec_strLine;
        split( vec_strLine, str );
        
        if ( vec_strLine.size() != pattern.size() ) 
            return false;
            
        for ( size_t i = 0, len = pattern.size(); i < len; i++ ) {
            auto it1 = map_c2s.find( pattern[i] );
            auto it2 = map_s2c.find( vec_strLine[i] );
            if ( it1 == map_c2s.end() && it2 == map_s2c.end() ) {
                map_c2s[pattern[i]] = vec_strLine[i];
                map_s2c[vec_strLine[i]] = pattern[i];
            } else if ( it1 == map_c2s.end() ^ it2 == map_s2c.end() ) {
                return false;
            } else if ( it1->second != vec_strLine[i] || it2->second != pattern[i] )
                return false;
        }
        return true;
    }

private:
    void split( vector<string>& result, string& str ) {
        stringstream ss( str );
        string temp;
        while ( getline( ss, temp, ' ' ) )
            result.push_back( temp );
    }
};