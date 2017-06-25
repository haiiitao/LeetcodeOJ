class Solution {
public:
    bool getSum( vector<int>& nums, int sum, int start ) {
        if ( sum == 0 )
            return true;
        
        if ( sum < 0 )
            return false;
            
        for ( int i = start, len = nums.size(); i < len; i++ ) {
            if ( getSum( nums, sum - nums[i], i + 1 ) )
                return true;
        }
        return false;
    }
    
    bool canPartition( vector<int>& nums ) {
        int sum = 0, len = nums.size();
        for ( int i = 0; i < len; ++i )
            sum += nums[i];
          
        if ( sum % 2 )
            return false;
        
        sort( nums.begin(), nums.end(), std::greater<int>() );
        return getSum( nums, sum / 2, 0 );
    }
};

class Solution {
public:
    bool canPartition( vector<int>& nums ) {
        int sum = accumulate( nums.begin(), nums.end(), 0 );
        if ( sum % 2 )
            return false;
        
        int target = sum / 2;
        bool f[target + 1] = { 0 };
        f[0] = true;
        for ( auto num : nums ) {
            for ( int i = target; i >= num; i-- ) {
                f[i] |= f[i - num];
            }
        }
        return f[target];
    }
};