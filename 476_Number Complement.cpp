class Solution {
public:
    int findComplement( int num ) {
        int t = num;
        int count = 0;
        while ( t ) {
            count++;
            t >>= 1;
        }
        int result = 0;
        for ( int i = 0; i < count; i++ ) {
            int b = num & (1 << i);
            if ( !b )
                result += 1 << i;
        }
        return result;
    }
};