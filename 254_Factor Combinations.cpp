/**
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 
Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Examples: 
input: 1
output: 
[]
input: 37
output: 
[]
input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
 */
class Solution {
public:
    vector<vector<int>> getFactors( int n ) {
        vector<int> path;
        vector<vector<int>> result;
        genFactors( result, path, n );
        
        return result;
    }
    
private:
    void genFactors( vector<vector<int>>& result, vector<int>& path, int n ) {
        int bnd = sqrt( n );
        int i = path.empty() ? 2 : path.back();
        for ( ; i <= bnd; i++ ) {
            if ( n % i ) // can't be divided
                continue;
                
            path.push_back( i );
            path.push_back( n / i );
            result.push_back( path );
            path.pop_back();
            genFactors( result, path, n / i );
            path.pop_back();
        }
    }
};