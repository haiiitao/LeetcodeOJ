/**
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert( vector<Interval>& intervals, Interval newInterval ) {
        vector<Interval> result;
        bool finish = false;
        for ( auto it = intervals.begin(); it != intervals.end(); it++ ) {
            if ( it->end < newInterval.start ) {
                result.push_back( *it );
            } else if ( newInterval.end < it->start) {
                result.push_back( newInterval );
                result.insert( result.end(), it, intervals.end() );
                finish = true;
                break;
            } else {
                newInterval.start = min( newInterval.start, it->start );
                newInterval.end = max( newInterval.end, it->end );
            }
        }
        
        if ( !finish )
            result.push_back( newInterval );
            
        return result;
    }
};
// ==> another version
class Solution {
public:
    vector<Interval> insert( vector<Interval> &intervals, Interval newInterval ) {
        auto it = intervals.begin(), itEnd = intervals.end();
        vector<Interval>::iterator first, last;
        bool b_Erase = false;
        while ( it != itEnd ) {
            if ( newInterval.end < it->start ) {
                break;
            } else if ( newInterval.start > it->end ) {
                ;
            } else { 
                last = it;
                newInterval.start = min( newInterval.start, it->start );
                newInterval.end = max( newInterval.end, it->end );
                if ( !b_Erase ) {
                    first = it;
                    b_Erase = true;
                }
            }
            it++;
        }
        if ( b_Erase )
            it = intervals.erase( first, next( last ) );
            
        intervals.insert( it, newInterval );
        return intervals;
    }
};