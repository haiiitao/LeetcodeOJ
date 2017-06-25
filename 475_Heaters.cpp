// upper bound
class Solution {
public:
    int findRadius( vector<int>& houses, vector<int>& heaters ) {
        sort( heaters.begin(), heaters.end() );
        int result = 0;
        for ( auto h : houses ) {
            auto right = upper_bound( heaters.begin(), heaters.end(), h );
            int d = INT_MAX;
            if ( right != heaters.end() ) d = min( d, *right - h);
            if ( right != heaters.begin() ) d = min( d, h - *prev( right ) );
            result = max( result, d );
        }
        return result;
    }
};
// lower bound
class Solution {
public:
    int findRadius( vector<int>& houses, vector<int>& heaters ) {
        sort( heaters.begin(), heaters.end() );
        int result = 0, r;
        for ( int i = 0, len = houses.size(); i < len; i++ ) {
            auto it = lower_bound( heaters.begin(), heaters.end(), houses[i] );
            if ( it == heaters.begin() )
                r = *it - houses[i];
            else if ( it == heaters.end() )
                r = houses[i] - *prev(it);
            else
                r = min( *it - houses[i], houses[i] - *prev(it) );
            
            result = max( result, r );
        }
        return result;
    }
}