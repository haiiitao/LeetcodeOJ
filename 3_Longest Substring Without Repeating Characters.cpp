/**
 * Given a string, find the length of the longest substring without repeating characters. 
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
 * which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */
class Solution {
public:
    int lengthOfLongestSubstring( string s ) {
        int prev[128];
        fill_n( prev, 128, -1 );
        
        int l = 0, r = 0, max_len = 0, len = s.size();
        while ( r < len ) {
            if ( prev[s[r]] >= l ) {
                max_len = max( max_len, r - l );
                l = prev[s[r]] + 1;
            }
            prev[s[r]] = r++;
        }
        return max( max_len, len - l );
    }
};