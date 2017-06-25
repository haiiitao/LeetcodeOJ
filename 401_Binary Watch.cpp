class Solution {
public:
    vector<string> readBinaryWatch( int num ) {
        vector<string> result;
        for ( int h = 0; h < 12; h++ )
            for ( int m = 0; m < 60; m++ )
                if ( count_bit( h << 6 | m ) == num )
                    result.emplace_back( to_string( h ) + (m < 10 ? ":0" : ":") + to_string( m ) );
                
        return result;
    }

    int count_bit ( int n ) {
        int count = 0;
        while ( n ) {
            n &= n - 1;
            count++;
        }
        return count;
    }
};