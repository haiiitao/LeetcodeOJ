class Solution {
public:
    int divide( int dividend, int divisor ) {
        if ( !divisor || divisor == -1 && dividend == INT_MIN )
            return INT_MAX;

        long ldividend = labs( dividend );
        long ldivisor = labs( divisor );
        int result = 0;
        while ( ldividend >= ldivisor ) {
            long temp = ldivisor;
            int multiple  = 1;
            while ( ldividend >= (temp << 1 ) ) {
                multiple  <<= 1;
                temp <<= 1;
            }
            ldividend -= temp;
            result += multiple ;
        }
        return (dividend ^ divisor) >> 31 ? -result : result;
    }
};