/**
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
Return:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
 */
class Solution {
public:
    vector<vector<string>> groupStrings( vector<string>& strings ) {
        unordered_map<string, vector<string>> dict;
        sort( strings.begin(), strings.end() );
        vector<vector<string>> result;
        for ( auto& str: strings )
            dict[getKey( str )].push_back( str );
            
        for ( auto& aGroup: dict )
            result.push_back( aGroup.second );
        
        return result;
    }
    
private:
    string getKey( string str ) {
        int diff = str[0] - 'a';
        for ( char& c : str )
            c = (c - diff + 26) % 26 + 'a';
        
        return str;
    }
};