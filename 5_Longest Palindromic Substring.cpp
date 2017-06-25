/**
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */
class Solution {
public:
    string longestPalindrome( string s ) {
        int max_start = 0, max_len = 0;
        for ( int i = 0, len = s.size(); i < len - max_len / 2; ) {
            int left = i, right = i;
            while ( right < len - 1 && s[right + 1] == s[right] ) 
                ++right; // Skip duplicate characters.
                
            i = right + 1;
            while ( right < len - 1 && left > 0 && s[right + 1] == s[left - 1] ) {   
                ++right;  // Expand.
                --left; 
            } 
            const int new_len = right - left + 1;
            if ( new_len > max_len ) { 
                max_start = left; 
                max_len = new_len; 
            }
        }
        return s.substr( max_start, max_len );
    }
};