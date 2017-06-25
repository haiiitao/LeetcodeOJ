/**
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
 */
class Solution {
public:
    int longestConsecutive( vector<int> &num ) {
        unordered_map<int, bool> visit;
        for ( auto i : num )
            visit[i] = false;
            
        int max_len = 0;
        for ( auto i : num ) {
            if ( visit[i] )
                continue;
            
            int len = 1;
            visit[i] = true;
            for ( int j = i - 1; visit.count( j ); j--, len++ )
                visit[j] = true;
                
            for ( int j = i + 1; visit.count( j ); j++, len++ )
                visit[j] = true;
            
            max_len = max( max_len, len );
        }
        return max_len;
    }
};