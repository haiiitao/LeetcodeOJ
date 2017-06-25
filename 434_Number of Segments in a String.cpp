class Solution {
public:
    int countSegments( string s ) {
        int result = 0;
        for ( int i = 0, len = s.size(); i < len; ) {
            while ( i < s.size() && s[i] == ' ' ) 
                i++;
            
            if ( i == len )
                break;
            
            result++;
            while ( i < len && s[i] != ' ' )
                i++;
        }
        return result;
    }
};