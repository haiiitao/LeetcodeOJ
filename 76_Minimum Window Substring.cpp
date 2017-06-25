/**
Given a string S and a string T, find the minimum window in S 
which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, 
return the empty string "".

If there are multiple such windows, you are guaranteed that 
there will always be only one unique minimum window in S.
 */
class Solution {
public:
    string minWindow( string s, string t ) {
        const int lenS = s.size(), lenT = t.size();
        int appear_count[128] = { 0 };
        int expect_count[128] = { 0 };
        for ( auto ch : t )
            expect_count[ch]++;
            
        int l = 0, r = 0, appeared = 0;
        int min_start, min_length = INT_MAX;
        while ( r < lenS ) {
            if ( expect_count[s[r]] ) {
                if ( ++appear_count[s[r]] <= expect_count[s[r]] )
                    appeared++;
            }
            r++;
            if ( appeared < lenT )
                continue;
                
            while ( appear_count[s[l]] > expect_count[s[l]] || !expect_count[s[l]] )
               appear_count[s[l++]]--;
            
            if ( min_length > r - l ) {
                min_length = r - l;
                min_start = l;
            }
        }
        return min_length == INT_MAX ? "" : s.substr( min_start, min_length );
    }
};