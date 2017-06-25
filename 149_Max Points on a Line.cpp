/**
 * Description: Given n points on a 2D plane, 
 * find the maximum number of points that lie on the same straight line.
 *
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints( vector<Point>& points ) {
        const int len = points.size();
        if ( len < 3 )
            return len;
           
        unordered_set<long> visited; 
        unordered_map<double, int> slope_count;
        int result = 0;
        for ( int i = 0; i < len - 1; i++ ) {
            long key = points[i].x << 32 | points[i].y;
            if ( !visited.insert( key ).second ) 
                continue;
                    
            int same = 1;
            for ( int j = i + 1; j < len; j++ ) {
                if ( points[i].x == points[j].x ) {
                    if( points[i].y == points[j].y )
                        same++;
                    else    
                        slope_count[std::numeric_limits<double>::infinity()]++;
                    
                    continue;
                }
                double slope = double(points[i].y - points[j].y) * 100 / double(points[i].x - points[j].x);
                slope_count[slope]++;
            }
            int count = 0;
            for ( auto it = slope_count.begin(); it != slope_count.end(); it++ )
                count = max( count, it->second );
                
            result = max( result, same + count );
            slope_count.clear();
        }
        return result;
    }
};