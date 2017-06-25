class Solution {
public:
    bool isRectangleCover( vector<vector<int>>& rectangles ) {
        int min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX, max_y = INT_MIN;
        int sum = 0;
        unordered_set<int> counter;
        for ( auto& rect : rectangles ) {
            min_x = min( min_x, rect[0] );
            max_x = max( max_x, rect[2] );
            min_y = min( min_y, rect[1] );
            max_y = max( max_y, rect[3] );
            sum += (rect[2] - rect[0]) * (rect[3] - rect[1]);

            int corner1 = (rect[0] << 8) + rect[1];
            int corner2 = (rect[0] << 8) + rect[3];
            int corner3 = (rect[2] << 8) + rect[1];
            int corner4 = (rect[2] << 8) + rect[3];
            if ( !counter.insert( corner1 ).second ) counter.erase( corner1 );
            if ( !counter.insert( corner2 ).second ) counter.erase( corner2 );
            if ( !counter.insert( corner3 ).second ) counter.erase( corner3 );
            if ( !counter.insert( corner4 ).second ) counter.erase( corner4 );
        }
        if ( !counter.count( (min_x << 8) + min_y ) || !counter.count( (min_x << 8) + max_y ) ||
             !counter.count( (max_x << 8) + min_y ) || !counter.count( (max_x << 8) + max_y ) || 
              counter.size() != 4 )
            return false;
            
        return (max_x - min_x) * (max_y - min_y) == sum;
    }
};