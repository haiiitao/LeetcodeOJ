class Solution {
public:
    void nextPermutation( vector<int>& nums ) {
        int i, j;
        for ( i = nums.size() - 2; i >= 0; i-- )
            if ( nums[i] < nums[i + 1] )
                break;
                
        if ( i != -1 ) {
            for ( j = nums.size() - 1; j > i; j-- )
                if ( nums[j] > nums[i] )
                    break;
                
            swap( nums[i], nums[j] );
        }
        reverse( nums.begin() + i + 1, nums.end() );
    }
};

class Solution {
public:
    void nextPermutation( vector<int>& nums ) {
        int i = nums.size() - 1;
        while ( i && nums[i] <= nums[i - 1] )
            i--;
        
        if ( --i < 0 ) {
            reverse( nums.begin(), nums.end() );
            return;
        }
        int j = nums.size() - 1;
        while ( j != i && nums[j] <= nums[i] )
            j--;
        
        swap( nums[i], nums[j] );
        reverse( nums.begin() + i + 1, nums.end() );
    }
};