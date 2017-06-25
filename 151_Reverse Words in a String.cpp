class Solution {
public:
    void reverseWords( string& str ) {
        reverse( str.begin(), str.end() );
        int cur = 0;
        for ( size_t i = 0, len = str.size(); i < len; i++ ) {
            if ( str[i] == ' ' ) continue;
            if ( cur ) str[cur++] = ' ';
            
            int j = i;
            while ( str[j] != ' ' && j < len )
                str[cur++] = str[j++]; 
                
            reverse( str.begin() + cur - (j - i), str.begin() + cur );
            i = j;
        }
        str.erase( str.begin() + cur, str.end() );
    }
};