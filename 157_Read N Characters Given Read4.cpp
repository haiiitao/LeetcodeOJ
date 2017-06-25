// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read( char *buf, int n ) {
        int result = 0;
        while ( n > 0 ) {
            int temp = min( n, read4( buf ) );
            n -= temp;
            buf += temp;
            result += temp;
            if ( temp < 4 )
                break;
        }
        return result;
    }
};