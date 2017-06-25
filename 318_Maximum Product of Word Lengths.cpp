/**
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. 
You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
 */
class Solution {
public:
    int maxProduct( vector<string>& words ) {
        int len = words.size(), result = 0;
        vector<int> counter( len, 0 );
        for ( int i = 0; i < len; i++ ) {
            for ( auto ch : words[i] ) {
                counter[i] |= (1 << (ch - 'a'));
            }
        }

        for ( int i = 0; i < len; i++ ) {
            const int leni = words[i].size();
            for ( int j = i + 1; j < len; j++ ) {
                if ( counter[i] & counter[j] ) 
                    continue;
                
                int length = leni * words[j].size();
                result = max( result, length );
            }
        }
        return result;
    }
};