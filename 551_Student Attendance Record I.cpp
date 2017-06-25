class Solution {
public:
    bool checkRecord( string s ) {
        int countL = 0, countA = 0;
        for ( int i = 0, len = s.size(); i < len; i++ ) {
            if ( s[i] == 'A' ) {
                countA++;
                countL = 0;
            } else if ( s[i] == 'P' )
                countL = 0;
            else    
                countL++;
            
            if ( countA > 1 || countL > 2 )
                return false;
        }
        return true;
    }
};