/**
Given an integer array with all positive numbers and no duplicates, 
find the number of possible combinations that add up to a positive integer target.
 */
class Solution {
public:
    int combinationSum4( vector<int>& nums, int target ) {
        int len = nums.size();
        if ( !len ) 
            return 0;
            
        int f[target + 1] = { 0 };
        f[0] = 1;
        for ( int i = 1; i <= target; i++ )   {
            for ( int v : nums ) {
                if ( i - v < 0 ) 
                    continue;
                    
                f[i] += f[i - v];
            }
        }
        return f[target];
    }
};