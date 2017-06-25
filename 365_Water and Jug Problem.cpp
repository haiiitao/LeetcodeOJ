class Solution {
public:
    bool canMeasureWater( int x, int y, int z ) {
        if ( x + y == z )
            return true;

        if ( x + y < z )
            return false;

        if ( x > y )
            swap( x, y );

        int volume = 0;
        while ( true ) {
            volume += volume < x ? y : -x;
            if ( volume == z )
                return true;

            if ( volume == 0 )
                return false;
        }
    }
};