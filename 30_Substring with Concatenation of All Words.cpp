/**
You are given a string, s, and a list of words, words, that are all of the same length. 
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once 
and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
 */
class Solution {
public:
    vector<int> findSubstring( string s, vector<string>& dict ) {
    	vector<int> result;
        int wordLength = dict[0].size();
        int catLength = wordLength * dict.size();

        unordered_map<string, int> wordCount;
        for ( auto& word : dict ) ++wordCount[word];
        for ( int i = 0, len = s.size(); i <= len - catLength; i++ ) {
            unordered_map<string, int> unused( wordCount );
            for ( int j = i; j < i + catLength; j += wordLength ) {
                auto pos = unused.find( s.substr( j, wordLength ) );
                if ( pos == unused.end() || !pos->second ) break;
                if ( !--pos->second ) unused.erase( pos );
            }
            if ( unused.empty() ) result.push_back( i );
        }
        return result;
    }
};