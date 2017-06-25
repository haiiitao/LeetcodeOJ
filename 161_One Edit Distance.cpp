class Solution {
public:
    bool isOneEditDistance( string s, string t ) {
        int lens = s.size(), lent = t.size();
        if ( abs( lens - lent ) > 1 || s == t )
            return false;
            
        int i = 0, j = 0;
        bool diff = false;
        while( i < lens && j < lent ) {
            if ( s[i] == t[j] ) {
                i++;
                j++;
                continue;
            }
            if ( diff )
                return false;
                
            diff = true;
            if ( lens >= lent ) i++;
            if ( lent >= lens ) j++;
        }
        return true;
    }
};