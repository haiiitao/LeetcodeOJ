class Solution {
public:
    void reverseWords( string& s ) {
        reverse( s.begin(), s.end() );
        for ( size_t i = 0, len = s.size(); i < len; i++ ) {
            size_t pos = s.find( ' ', i );
            if ( pos == -1 ) 
                pos = len;
            
            reverse( s.begin() + i, s.begin() + pos );
            i = pos;
        }
    }
};