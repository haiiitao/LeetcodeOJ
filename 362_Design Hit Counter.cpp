class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        time = vector<int>( 300, 0 );
        counter = vector<int>( 300, 0 );
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit( int timestamp ) {
    	int index = timestamp % 300;
    	if ( time[index] != timestamp ) {
    		time[index] = timestamp;
    		counter[index] = 1;
    	} else 
    		counter[index]++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits( int timestamp ) {
   	    int total = 0;
    	for ( int i = 0; i < 300; i++ ) {
    	    if ( timestamp - time[i] < 300 )
    	    	total += counter[i];
    	}
    	return total;
    }
    vector<int> time;
    vector<int> counter;
};