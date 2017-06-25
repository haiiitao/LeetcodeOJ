bool knows(int a, int b);

class Solution {
public:
    int findCelebrity( int n ) {
        int candidate = 0;
        for ( int i = 1; i < n; i++ ) {
            if ( !knows( i, candidate ) )
                candidate = i;
        }
        for ( int i = 0; i < n; i++ ) {
            if ( i == candidate ) 
                continue;
    
            //if i does not know candidate, or candidate knows i, return -1;
            if( !knows( i, candidate ) || knows( candidate, i ) )
                return -1;
        }
        return candidate;
    }
};