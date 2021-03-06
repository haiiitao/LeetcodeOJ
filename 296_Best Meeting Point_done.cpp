/**
A group of two or more people wants to meet and minimize the total travel distance. 
You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. 
The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
 */
class Solution {
public:
    int minTotalDistance( vector<vector<int>>& grid ) {
        const int m = grid.size(), n = grid[0].size();
        vector<int> locationX, locationY;
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( grid[i][j] ) {
                    locationX.push_back( i );
                    locationY.push_back( j );
                }
            }
        }
        return get_min( locationX ) + get_min( locationY );
    }
    
private:
    int get_min( vector<int>& location ) {
        sort( location.begin(), location.end() );
        int left = 0, right = location.size() - 1, result = 0;
        while ( left < right )
            result += location[right--] - location[left++];
        
        return result;
    }
};