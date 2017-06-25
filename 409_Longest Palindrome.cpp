class Solution {
public:
    int longestPalindrome( string s ) {
        int counter[128] = { 0 };
        for ( ch : s )
            counter[ch]++;
        
        int result = 0, odd = 0;
        for ( int i = 0; i < 128; i++ ) {
            if ( counter[i] % 2 == 1 ) { // odd
                odd = 1;
                result += counter[i] - 1;
            } else
                result += counter[i];
        }
        return result + odd;
    }
};