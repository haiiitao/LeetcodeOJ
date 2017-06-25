/**
 * Description: Given two strings s and t, write a function to determine if t is an anagram of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 */
class Solution {
public:
    bool isAnagram( string s, string t ) {
        if ( s.size() != t.size() )
            return false;
            
        const int len = s.size();
        int counter[128] = { 0 };
        for ( auto ch : s ) {
            counter[ch]++;
        }
        
        for ( auto ch : t ) {
            if ( !counter[ch] ) {
                return false;
            }
            counter[ch]--;
        }       
        return true;
    }
};