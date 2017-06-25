class Solution {
public:
    int minMoves( vector<int>& nums ) {
        int n = *min_element( nums.begin(), nums.end() );
        int result = 0;
        for ( auto num : nums )
            result += num - n;
            
        return result;
    }
};