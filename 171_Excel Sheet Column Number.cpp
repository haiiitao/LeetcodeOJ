class Solution {
public:
    int titleToNumber( string s ) {
        int result = 0;
        for ( int i = 0, len = s.size(); i < len; i++ ) 
            result = result * 26 + (s[i] - 'A' + 1);
        
        return result;
    }
};