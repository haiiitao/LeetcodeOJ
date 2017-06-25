/**
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams( vector<string>& strs ) {
        unordered_map<string, int> map_Key2Idx;
        vector<vector<string>> result;
        sort( strs.begin(), strs.end() );
        
        int idx = 0;
        for ( auto& str : strs ) {
            string key( str );
            sort( key.begin(), key.end() );
            auto it = map_Key2Idx.find( key );
            if ( it == map_Key2Idx.end() ) {
                map_Key2Idx[key] = idx++;
                result.push_back( { str } );
            } else 
                result[it->second].push_back( str );
        }
        return result;
    }
};