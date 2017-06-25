class Solution {
public:
    vector<double> calcEquation( 
            vector<pair<string, string>> equ, 
            vector<double>& values, 
            vector<pair<string, string>> queries ) {
        vector<double> result;
        unordered_map<string, vector<pair<string, double>>> graph;      
        for ( size_t i = 0, len = equ.size(); i < len; i++ ) {
            graph[equ[i].first].push_back( make_pair( equ[i].second, values[i] ) );  
            graph[equ[i].second].push_back( make_pair( equ[i].first, 1 / values[i] ) );
            graph[equ[i].first].push_back( make_pair( equ[i].first, 1.0 ) );  
            graph[equ[i].second].push_back( make_pair( equ[i].second, 1.0 ) );
        }   
        
        for ( auto& p : queries ) {
            unordered_set<string> visited;                          
            result.push_back( dfs(p.first, p.second, visited, 1.0, graph).second );
        }
        return result;
    }
    pair<bool, double> dfs( string& a, string& b, unordered_set<string>& visited, double val, unordered_map<string, vector<pair<string, double>>>& graph ) {
        if ( visited.insert(a).second ) {
            for ( auto& p : graph[a] ) {
                double temp = val * p.second; 
                if ( p.first == b ) 
                    return make_pair( true, temp ); 
                    
                auto result = dfs( p.first, b, visited, temp, graph );
                if ( result.first ) 
                    return result;
            }
        }
        return make_pair( false, -1.0 );
    }
};