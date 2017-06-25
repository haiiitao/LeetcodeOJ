class Solution {
public:
    int trapRainWater( vector<vector<int>>& heightMap ) {
        const int m = heightMap.size(), n = !m ? 0 : heightMap[0].size();
        if ( !m || !n )
            return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        bool visited[m][n] = {};
        int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        int result = 0, level = INT_MIN;
        
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( !( i == 0 || i == m - 1 || j == 0 || j == n - 1 ) ) 
                    continue;
                    
                pq.push( make_pair( heightMap[i][j], i * n + j ) );
                visited[i][j] = true;
            }
        }
        while ( !pq.empty() ) {
            auto val = pq.top(); 
            pq.pop();
            int height = val.first, x = val.second / n, y = val.second % n;
            level = max( level, height);
            for ( int k = 0; k < 4; k++ ) {
                int next_x = x + dir[k][0];
                int next_y = y + dir[k][1];
                if ( unsigned( next_x ) >= m || unsigned( next_y ) >= n || visited[next_x][next_y] ) 
                    continue;
                    
                visited[next_x][next_y] = true;
                result += max( 0, level - heightMap[next_x][next_y] );
                pq.push( make_pair( heightMap[next_x][next_y], next_x * n + next_y ) );
            }
        }
        return result;       
    }
};