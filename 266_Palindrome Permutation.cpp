/**
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.
 */
class Solution {
public:
    bool canPermutePalindrome( string s ) {
        int count[128] = { 0 };
        for ( auto ch : s )
            count[ch]++;
            
        bool found = false;
        for ( int i = 0; i < 128; i++ ) {
            if ( count[i] % 2 == 0 )
                continue;
            
            if ( found )
                return false;
            
            found = true;
        }
        return true;
    }
};