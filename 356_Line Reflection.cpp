class Solution {
public:
    bool isReflected( vector<pair<int, int>>& points ) {
        int width_min = INT_MAX, width_max= INT_MIN;
        unordered_map<int, unordered_set<int>> mappings;
        for ( auto& point : points ) {
            point.first *= 2;
            width_min = min( width_min, point.first );
            width_max = max( width_max, point.first );
            mappings[point.first].insert( point.second );
        }
        int mid = (width_min + width_max) / 2, count = 0;
        for ( auto& point : points ) {
            int ref = 2 * mid - point.first;
            if ( !mappings[ref].count( point.second ) )
                return false;
        }
        return true;
    }
};