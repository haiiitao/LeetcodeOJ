class Solution {
public:
    int thirdMax( vector<int>& nums ) {
        set<int> visited;
        for ( auto num : nums ) {
            if ( visited.size() < 3 )
                visited.insert( num );
            else {
                visited.insert( num );
                if ( visited.size() == 4 )
                    visited.erase( visited.begin() );
            }
        }
        return visited.size() < 3 ? *visited.rbegin() : *visited.begin();
    }
};