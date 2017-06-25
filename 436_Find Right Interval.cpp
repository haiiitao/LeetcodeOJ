class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> mapping;
        for ( size_t i = 0, len = intervals.size(); i < len; i++ )
            mapping[intervals[i].start] = i;
        
        vector<int> result;
        for ( auto& i : intervals ) {
            auto it = mapping.lower_bound( i.end );
            if ( it == mapping.end() )
                result.push_back( -1 );
            else
                result.push_back( it->second );
        }
        return result;
    }
};