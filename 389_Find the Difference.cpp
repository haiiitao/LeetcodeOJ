class Solution {
public:
    char findTheDifference( string s, string t ) {
        char result = 0;
        for ( auto ch : s )
            result ^= ch;
        
        for ( auto ch : t )
            result ^= ch;
    
        return result;
    }
};