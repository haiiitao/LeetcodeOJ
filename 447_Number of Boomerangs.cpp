class Solution {
public:
    int numberOfBoomerangs( vector<pair<int, int>>& points ) {
        int res = 0;
        unordered_map<int, int> counter;
        for ( int i = 0, len = points.size(); i < len; ++i ) {
            for ( int j = 0; j < len; ++j ) {
                if ( j == i ) 
                    continue;
                
                int dy = points[i].second - points[j].second;
                int dx = points[i].first - points[j].first;
                ++counter[dx * dx + dy * dy];
            }
            for  ( auto& p : counter ) 
                res += p.second * (p.second - 1);
            
            counter.clear();
        }
        return res;
    }
};