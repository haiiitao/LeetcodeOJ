class Solution {
public:
    vector<int> findDiagonalOrder( vector<vector<int>>& matrix ) {
        vector<vector<int>> temp;
        const int m = matrix.size(), n = !m ? 0 : matrix[0].size();
        for ( int i = 0; i < n; i++ ) {
            int j = 0, k = i;
            temp.push_back( vector<int>() );
            while ( k >= 0 && j < m )
                temp.back().push_back( matrix[j++][k--] );
        }
        for ( int i = 1; i < m; i++) {
            int j = i, k = n - 1;
            temp.push_back( vector<int>() );
            while ( k >= 0 && j < m )
                temp.back().push_back( matrix[j++][k--] );
        }
        vector<int> result;
        for ( int i = 0, len = temp.size(); i < len; i++ ) {
            if ( i % 2 == 1 )
                for ( auto it = temp[i].begin(), itEnd = temp[i].end(); it != itEnd; it++ )
                    result.push_back( *it );
            else
                for ( auto it = temp[i].rbegin(), itEnd = temp[i].rend(); it != itEnd; it++ )
                    result.push_back( *it );
        }
        return result;
    }
};