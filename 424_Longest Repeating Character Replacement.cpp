class Solution {
public:
    int characterReplacement( string s, int k ) {
        int count[128] = { 0 };
        int most = 0, start = 0, end = 0;
        for ( int len = s.size(); end < len; ) {
            most = max( most, ++count[s[end++]] );
            if ( end - start - most > k ) 
                count[s[start++]]--;
        }
        return end - start;
    }
};