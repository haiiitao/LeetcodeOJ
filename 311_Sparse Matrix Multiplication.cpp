/**
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
 */
class Solution {
public:
    vector<vector<int>> multiply( vector<vector<int>>& A, vector<vector<int>>& B ) {
        const int m = A.size(), p = B.size(), n = B[0].size();
        vector<vector<int>> C( m, vector<int>( n, 0 ) );
        unordered_map<int, unordered_set<int>> sA;
        unordered_map<int, unordered_set<int>> sB;
        for ( int i = 0; i < m; i++ ) {
            for ( int k = 0; k < p; k++ ) {
                if ( A[i][k] )
                    sA[i].insert( k );
            }
        }
        for ( int j = 0; j < n; j++ ) {
            for ( int k = 0; k < p; k++ ) {
                if ( B[k][j] )
                    sB[j].insert( k );
            }
        }
        for ( auto iA = sA.begin(), iAEnd = sA.end(); iA != iAEnd; iA++ ) {
            auto& rA = iA->second;
            for ( auto iB = sB.begin(), iBEnd = sB.end(); iB != iBEnd; iB++ ) {
                auto& cB = iB->second;
                for ( auto iter = rA.begin(), iterEnd = rA.end(); iter != iterEnd; iter++ ) {
                    if ( cB.count( *iter ) ) {
                        C[iA->first][iB->first] += A[iA->first][*iter] * B[*iter][iB->first];
                    }
                }
            }
        }
        return C;
    }
};