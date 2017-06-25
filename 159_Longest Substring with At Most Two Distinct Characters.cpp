/**
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
 */
class Solution { 
public:
    int lengthOfLongestSubstringTwoDistinct( string str ) {
        int count[128] = { 0 }; 
        int left = 0, right = 0, max_len = 0, k = 0, len = str.size();
        while ( right < len ) {
            if ( ++count[str[right]] == 1 ) { // new char
                k++;
                while ( k == 3 ) {
                    if ( !--count[str[left++]] ) 
                        k--; 
                }
            }
            max_len = max( max_len, right - left + 1 );
            right++;
        }
        return max_len;
    }
};