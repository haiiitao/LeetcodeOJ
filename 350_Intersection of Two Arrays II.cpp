class Solution {
public:
    vector<int> intersect( vector<int>& nums1, vector<int>& nums2 ) {
        unordered_map<int, int> dict;
        for ( auto i : nums1 ) 
            dict[i]++;
            
        vector<int> res;
        for ( auto i : nums2 ) {
            auto it = dict.find( i );
            if ( it != dict.end() && it->second ) { 
                res.push_back( i );   
                it->second--;
            }
        }
        return res;
    }
};