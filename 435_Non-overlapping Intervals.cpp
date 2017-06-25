class Solution {
public:
    int eraseOverlapIntervals( vector<Interval>& intervals ) {
        sort( intervals.begin(), intervals.end(), [&]( const Interval& a, const Interval& b ) {
           return a.start == b.start ? a.end < b.end : a.start < b.start; 
        });
        if ( intervals.empty() )
            return 0;
            
        int result = 0;
        for ( int i = 1, end = intervals[0].end, len = intervals.size(); i < len; i++ ) {
            if ( intervals[i].start < end ) {
                end = min( end, intervals[i].end );
                result++;
            } else if ( intervals[i].start >= end) 
                end = intervals[i].end;
        }
        return result;
    }
};