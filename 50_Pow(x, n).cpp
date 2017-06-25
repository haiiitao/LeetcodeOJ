g/**
Implement pow(x, n).
 */

// test case: 1, INT_MIN is error prone
class Solution {
public:
    double myPow( double x, int n ) {
        if ( n < 0 ) 
            return 1 / cal( x, -n );

        return cal( x, n );
    }
    
private:
    double cal( double x, int n ) {
        if ( !n ) 
            return 1;
            
        double v = cal( x, n / 2 );
        if ( n % 2 )
        	return x * v * v;

        return v * v;
    }
};