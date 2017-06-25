class Solution {
public:
    bool hasPath( vector<vector<int>>& maze, vector<int>& start, vector<int>& dest ) {
        unordered_map<int, unordered_set<int>> cache;
        return dfs( maze, start[0], start[1], dest, cache );
    }
    bool dfs( vector<vector<int>>& maze, int i, int j, vector<int>& dest, unordered_map<int, unordered_set<int>>& cache ) {
        const int m = maze.size(), n = !m ? 0 : maze[0].size();
        int x = i, y = j;
        if ( cache[x << 16 | y].insert( 0 ).second ) { // up
            while ( x && maze[x - 1][y] == 0 ) x--;
            if ( (x == dest[0] && y == dest[1]) || dfs( maze, x, y, dest, cache ) )
                return true;
        }
        x = i, y = j;
        if ( cache[x << 16 | y].insert( 1 ).second ) { // down
            while ( x < m - 1 && maze[x + 1][y] == 0 ) x++;
            if ( (x == dest[0] && y == dest[1]) || dfs( maze, x, y, dest, cache ) )
                return true;
        }        
        x = i, y = j;
        if ( cache[x << 16 | y].insert( 2 ).second ) { // left
            while ( y && maze[x][y - 1] == 0 ) y--;
            if ( (x == dest[0] && y == dest[1]) || dfs( maze, x, y, dest, cache ) )
                return true;
        }
        x = i, y = j;
        if ( cache[x << 16 | y].insert( 3 ).second ) { // right
            while ( y < n - 1 && maze[x][y + 1] == 0 ) y++;
            if ( (x == dest[0] && y == dest[1]) || dfs( maze, x, y, dest, cache ) )
                return true;
        }
        return false;
    }
};