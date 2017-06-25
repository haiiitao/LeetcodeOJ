class Solution {
public:
    int reverse( int x ) {
        if ( x == INT_MIN )
            return 0;
            
        bool sign = x < 0;
        x = abs( x );
        int num = 0;
        for ( ; x; x /= 10 ) {
            int temp = x % 10;
            if ( num > INT_MAX / 10 )
                return 0;
                
            if ( num == INT_MAX / 10 && temp > INT_MAX % 10 ) 
                return 0;
            
            num = num * 10 + temp;
        }
        return sign ? -num : num;
    }
};

class Solution {
public:
    int reverse( int x ) {
        if ( x == INT_MIN )
            return 0;
            
        if ( x > 0 )
            return helper( x );
        else
            return -helper( -x );
    }
    int helper( int x ) {
        int num = 0;
        while ( x ) {
            if ( num > INT_MAX / 10 || (num == INT_MAX / 10 && x % 10 > INT_MAX % 10) )
                return 0;
                
            num = num * 10 + x % 10;
            x /= 10;
        }
        return num;
    }
};