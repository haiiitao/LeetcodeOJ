class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set_intNums1;
        for ( auto i : nums1 )
            set_intNums1.insert( i );
        
        vector<int> ans;
        for ( auto i : nums2 ) {
            auto it = set_intNums1.find( i );
            if ( it == set_intNums1.end() )
                continue;
            
            ans.push_back( i );
            set_intNums1.erase(it);
        }
        return ans;
    }
};