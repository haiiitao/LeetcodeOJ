class Solution {
public:
    int arrangeCoins( int n ) {
        long temp =  sqrt( 2 ) * sqrt( n );
        if ( temp * (temp + 1) / 2 <= n )
            return temp;
        else 
            return temp - 1;
    }
};