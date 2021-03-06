/**
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, 
and to take course 0 you should also have finished course 1. So it is impossible.
 */
class Solution {
public:
    bool canFinish( int numCourses, vector<pair<int, int>>& prerequisites ) {
        bool visited[numCourses] = { false }, rec[numCourses] = { false };
        vector<int> g[numCourses];
        for ( auto& dep : prerequisites )
            g[dep.first].push_back( dep.second );
        
        function<bool(int)> isCycle = [&]( int n ) {
            if ( !visited[n] ) {
                visited[n] = true, rec[n] = true;
                vector<int>& dependency = g[n];
                for ( auto i : dependency ) {
                    if ( isCycle( i ) || rec[i] )
                        return true;
                }
                rec[n] = false;
            }
            return false;            
        };
        
        for ( int i = 0; i < numCourses; i++ )
            if ( isCycle( i ) )
                return false;

        return true;
    }
};