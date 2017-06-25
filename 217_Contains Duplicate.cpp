class Solution {
public:
    bool containsDuplicate( vector<int>& nums ) {
        unordered_set<int> visited;
        for ( auto num : nums ) {
            if ( !visited.insert( num ).second ) {
                return true;
            }
        }
        return false;
    }
};