/**
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
 */
class Solution {
public:
    int lengthOfLongestSubstringKDistinct( string s, int k ) {
        int l = 0, r = 0, len = s.size(), count = 0, result = 0;
        int counter[128] = { 0 };
        while ( r < len ) {
            if ( ++counter[s[r++]] == 1 )
                count++;
                
            if ( count == k + 1 ) {
                while ( --counter[s[l++]] ) 
                    ;
                
                count = k;
            }
            result = max( result, r - l );
        }
        return result;
    }
};