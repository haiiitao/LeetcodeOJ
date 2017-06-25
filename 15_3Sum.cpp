class Solution {
public:
    vector<vector<int>> threeSum( vector<int>& nums ) {
        vector<vector<int>> result;
        sort( nums.begin(), nums.end() );
        for ( int i = 0, len = nums.size(); i < len; i++ ) {
            if ( i && nums[i] == nums[i - 1] )
                continue;
                
            int l = i + 1, r = len - 1;
            while ( l < r ) {
                int sum = nums[i] + nums[l] + nums[r];
                if ( sum == 0 ) {
                    result.push_back( { nums[i], nums[l], nums[r] } );
                    while ( ++l < r && nums[l] == nums[l - 1] );
                    while ( l < --r && nums[r] == nums[r + 1] );
                } else if ( sum < 0 )
                    while ( ++l < r && nums[l] == nums[l - 1] );
                else
                    while ( l < --r && nums[r] == nums[r + 1] );
            }
        }
        return result;
    }
};