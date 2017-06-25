/**
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. 
All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
 */
class Solution {
public:
    vector<string> findItinerary( vector<pair<string, string>> tickets ) {
        unordered_map<string, vector<string>> routes;
        for ( auto& ticket : tickets ) // build up map
            routes[ticket.first].push_back( ticket.second );
            
        for ( auto it = routes.begin(), itEnd = routes.end(); it != itEnd; it++ )
            sort( it->second.begin(), it->second.end(), ::greater<string>() ); // sort destination
    
        string start = "JFK";
        vector<string> result;
        dfs( result, routes, start );
        reverse( result.begin(), result.end() );
        
        return result;
    }
    
private:
    void dfs( vector<string>& result, unordered_map<string, vector<string>>& routes, string& start ) {
        auto& destinations = routes[start];
        while( !destinations.empty() ) {
            string destination = destinations.back();
            destinations.pop_back();
            dfs( result, routes, destination );
        }
        result.push_back( start );
    }
};