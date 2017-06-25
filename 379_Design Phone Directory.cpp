class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory( int maxNumbers ) {
        used.reserve( 2* maxNumbers );
        nonUsed.reserve( 2* maxNumbers );
        for ( int i = 0; i < maxNumbers; i++ )
            nonUsed.insert( i );
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if ( nonUsed.empty() )
            return -1;
        
        int temp = *nonUsed.begin();
        nonUsed.erase( nonUsed.begin() );
        used.insert( temp );
        return temp;
    }
    
    /** Check if a number is available or not. */
    bool check( int number ) {
        return nonUsed.count( number ) == 1;
    }
    
    /** Recycle or release a number. */
    void release( int number ) {
        auto it = used.find( number );
        if ( it != used.end() ) {
            used.erase( it );
            nonUsed.insert( number );
        }
        
    }
    unordered_set<int> used;
    bitset<>
};