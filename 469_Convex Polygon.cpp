class Solution {
public:
    bool isConvex( vector<vector<int>>& p ) {
        int len = p.size();
        long prev = 0, cur;
        for ( int i = 0; i < len; i++ ) {
            int A[2][2] = { { p[(i + 1) % len][0] - p[i][0], p[(i + 1) % len][1] - p[i][1] }, 
                          { p[(i + 2) % len][0] - p[i][0], p[(i + 2) % len][1] - p[i][1] } };
        if ( cur = det2( A ) ) 
            if ( cur * prev < 0 ) 
                return false; 
            else prev = cur;
        }
        return true;
    }
    long det2( int A[][2] ) { 
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];
    }
};