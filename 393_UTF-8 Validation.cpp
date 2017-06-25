class Solution {
public:
    bool validUtf8( vector<int>& data ) {
        int count = 0;
        for ( auto i : data ) {
            if ( !count ) {
                if ( i >> 5 == 6 ) count = 1;
                else if ( i >> 4 == 14 ) count = 2;
                else if ( i >> 3 == 30 ) count = 3;
                else if ( i >> 7 ) return false;
            } else if ( i >> 6 != 2 ) return false;
            else count--;
        }
        return count == 0;
    }
};