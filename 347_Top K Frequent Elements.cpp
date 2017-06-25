class Solution {
public:
    vector<int> topKFrequent( vector<int>& nums, int k ) {
        unordered_map<int, int> counter;
        for ( auto num : nums )
            counter[num]++;
            
        vector<int> result;
        priority_queue<pair<int, int>> pq;
        for ( auto it = counter.begin(); it != counter.end(); it++ ) {
            pq.push( { it->second, it->first } );
            if ( pq.size() > counter.size() - k ) {
                result.push_back( pq.top().second );
                pq.pop();
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> topKFrequent( vector<int>& nums, int k ) {
        if ( nums.empty() || !k )
            return {};
            
        unordered_map<int, int> counter;
        for ( auto i : nums )
            counter[i]++;
        
        if ( counter.size() < k )
            k = counter.size();
            
        map<int, queue<int>> map_Cnt2Eles;
        for ( auto& i : counter ) 
            map_Cnt2Eles[i.second].push( i.first );

        vector<int> result;
        auto it = map_Cnt2Eles.rbegin();
        while ( k-- ) {
            if( it->second.empty() ) 
                it++;
                
            result.push_back( it->second.front() );
            it->second.pop();
        }
        return result;
    }
};