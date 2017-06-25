class Solution {
public:
    int findMinArrowShots( vector<pair<int, int>>& points ) {
        sort( points.begin(), points.end() );
        int result = 1, arrow = INT_MAX;
        for ( int i = 0, len = points.size(); i < len; i++ ) {
            if ( points[i].first <= arrow ) {  
                arrow = min( arrow, points[i].second );
            } else{
                result++;
                arrow = points[i].second;
            }
        }
        return points.empty() ? 0 : result;
    }
};