/**
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 */

class Solution {
public:
    int countComponents( int n, vector<pair<int, int>>& edges ) {
        unordered_set<int> visited;
        vector<int> graph[n];
        for ( auto& e : edges ) {
            graph[e.first].push_back( e.second );
            graph[e.second].push_back( e.first );
        }
        
        int result = 0;
        for ( int i = 0; i < n; i++ ) {
            if ( !visited.count( i ) ) {
                dfs( i, graph, visited );
                result++;
            }
        }
        return result;
    }

private:
    void dfs( int start, vector<int> graph[], unordered_set<int>& visited ) {
        if ( !visited.insert( start ).second )
            return;
        
        for ( int i : graph[start] ) 
            dfs( i, graph, visited );
    }
};

// Union find
class Solution {
public:
    int countComponents( int n, vector<pair<int, int>>& edges ) {
        if ( !n )
            return 0;
            
        int f[n] = {};
        for ( int i = 0; i < n; i++ )
            f[i] = i;
        
        for ( auto& e : edges ) {
            int root1 = findRoot( f, e.first );
            int root2 = findRoot( f, e.second );
            if ( root1 != root2 )
                f[root1] = root2;
        }
        int count = 0;
        for ( int i = 0; i < n; i++ )
            if ( f[i] == i )
                count++;
                
        return count;
    }
    int findRoot( int f[], int i ) {
        while ( i != f[i] ) {
            f[i] = f[f[i]];
            i = f[i];
        }
        return i;
    }
};