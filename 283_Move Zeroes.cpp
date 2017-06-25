// Move to right
class Solution {
public:
    void moveZeroes( vector<int>& nums ) {
        for ( int i = 0, idx = 0, len = nums.size(); i < len; i++ ) {
            if ( nums[i] ) 
                swap( nums[i], nums[idx++]);
        }
    }
};

// Move to left
class Solution {
public:
    void moveZeroes( vector<int>& nums ) {
        int idx = nums.size() - 1;
        for ( int i = idx; i >= 0; i-- )
            if ( nums[i] )
                swap( nums[i], nums[idx--] );
    }
};
class Solution {
public:
    void moveZeroes( vector<int>& nums ) {
        int idx = 0;
        bool b_swap = false;
        for ( int i = 0, len = nums.size(); i < len; i++ )
            if( nums[i] )
                if ( b_swap )
                    swap( nums[i], nums[idx++] );
                else
                    idx++;
            else
                b_swap = true;
    }
};