class Solution {
public:
    static int map( const char c ) {
        switch ( c ) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    
    int romanToInt( string s ) {
        if ( s.empty() )
            return 0;

        int result = 0, prev = INT_MAX;;
        for ( size_t i = 0, len = s.size(); i < len; i++ ) {
            int cur = map( s[i] );
            result += cur;
            if ( prev < cur )
                result -= 2 * prev;
            
            prev = cur;
        }
        return result;
    }
};