class Solution {
public:
    vector<vector<int>> fourSum( vector<int>& nums, int target ) {
        vector<vector<int>> result;
        sort( nums.begin(), nums.end() );
        for ( int i = 0, len = nums.size(); i < len - 3; i++ ) {
            if ( i && nums[i] == nums[i - 1] ) continue;
            if ( nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target ) continue;        
            if ( nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target ) break;
            for ( int j = i + 1; j < len - 2; j++ ) {
                if ( j > i + 1 && nums[j] == nums[j - 1] ) continue;
                if ( nums[i] + nums[j] + nums[len - 2] + nums[len - 1] < target ) continue;                  
                if ( nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target ) break;
                int left = j + 1, right = len - 1;
                while ( left < right ) {
                    int sum = nums[left] + nums[right] + nums[i] + nums[j];
                    if ( sum < target ) while ( ++left < len && nums[left] == nums[left - 1] );
                    else if ( sum > target ) while ( --right > j && nums[right] == nums[right + 1] );
                    else {
                        result.push_back( {nums[i], nums[j], nums[left], nums[right]} );
                        while ( ++left < len && nums[left] == nums[left - 1] );
                        while ( --right > j && nums[right] == nums[right + 1] );
                    }
                }
            }
        }
        return result;
    }
};