/**
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
 */
class Solution {
public:
    bool validTree( int n, vector<pair<int, int>>& edges ) {
        vector<int> graph[n];
        unordered_set<int> visited;
        for ( auto& e : edges ) {
            graph[e.first].push_back( e.second );
            graph[e.second].push_back( e.first );
        }
        
        function<bool( int, int )> IsCycle = [&]( int child, int parent ) {
            if ( !visited.insert( child ).second )
                return true;

            for ( auto i : graph[child] )
                if ( i != parent && IsCycle( i, child ) )
                    return true;
                    
            return false;                
        };
       
        return IsCycle( 0, -1 ) ? false : visited.size() == n;
    } 
};
//==> better solution
class Solution {
public:
    bool validTree( int n, vector<pair<int, int>>& edges ) {
        int p[n];
        for ( int i = 0 ; i < n; ++i ) p[i] = i;
        for ( auto& edge : edges ){
            int v = edge.first, w = edge.second;
            while( p[v] != v ) v = p[v];
            while( p[w] != w ) w = p[w];
            p[v] = w;
            if( v != w ) 
                --n;
            else 
                return false; // cycle detected
        }
        return n == 1;
    }
};