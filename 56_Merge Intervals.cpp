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
    vector<Interval> merge( vector<Interval>& intervals ) {
        sort( intervals.begin(), intervals.end(), [&]( Interval& a, Interval& b ) {
            return a.start == b.start ? a.end < b.end : a. start < b.start;
        } );
        
        vector<Interval> result;
        for ( int i = 0, len = intervals.size(); i < len; i++ ) {
            if ( result.empty() || result.back().end < intervals[i].start )
                result.push_back( intervals[i] );
            else
                result.back().end = max( result.back().end, intervals[i].end );
        }
        return result;
    }
};

class Solution {
public:
    vector<Interval> merge( vector<Interval>&intervals ) {
        vector<Interval> result;
        for ( int i = 0, len = intervals.size(); i < len; i++ )
            insert( result, intervals[i] );
            
        return result;
    }
    
private:
    void insert( vector<Interval>& intervals, Interval newInterval ) {
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
    }
};