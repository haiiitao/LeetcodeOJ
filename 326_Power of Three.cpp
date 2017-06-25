class Solution {
public:
    bool isPowerOfThree( int n ) {
        const static int bound = (int)pow( 3, 19 );
        if ( n <= 0 )
            return false;
            
        return bound % n == 0;
    }
};