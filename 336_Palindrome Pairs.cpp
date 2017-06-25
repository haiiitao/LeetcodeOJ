/**
Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
 */
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> dict;
        vector<vector<int>> result;
        for ( int i = 0, len = words.size(); i < len; i++ ) {
            string key = words[i];
            reverse( key.begin(), key.end() );
            dict[key] = i;
        }

        if ( dict.count( "" ) ) {
            for ( int i = 0, idx_empty = dict[""], len = words.size(); i < len; i++ ) {
                if ( i == idx_empty ) 
                    continue;
                    
                if ( isPalindrome( words[i] ) ) 
                    result.push_back( { idx_empty, i } );
            }
        }

        for ( int i = 0, len = words.size(); i < len; i++ ) {
            string& word = words[i];
            for ( int j = 0, word_len = word.size(); j < word_len; j++ ) {
                string l = word.substr( 0, j );
                string r = word.substr( j , word_len - j );
                if ( dict.count( l ) && isPalindrome( r ) && dict[l] != i )
                    result.push_back( { i, dict[l] } );  

                if ( dict.count( r ) && isPalindrome( l ) && dict[r] != i )
                    result.push_back( { dict[r], i } );
            }
        }
        return result;        
    }

    bool isPalindrome( string& str ) {
        int l = 0, r = str.size() - 1; 
        while ( l < r ) { 
            if ( str[l++] != str[r--] )
                return false;
        }
        return true;
    }
};