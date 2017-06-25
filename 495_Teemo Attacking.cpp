class Solution {
public:
    int findPoisonedDuration( vector<int>& timeSeries, int duration ) {
        int result = 0;
        int start = -1, end = -1;
        for ( auto n : timeSeries ) {
            if ( n >= end ) {
                result += end - start;
                start = n;
                end = start + duration;
            } else 
                end = n + duration;
        }
        return result + end - start;
    }
};