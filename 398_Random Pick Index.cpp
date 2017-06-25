class Solution {
    vector<int> nums;
    
public:
    Solution( vector<int> nums ) {
        this->nums = nums;
    }
    
    int pick( int target ) {
        int cnt = 0;
        int index = -1;
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( nums[i] == target ) {
                if ( rand() % ++cnt == 0 ) 
                    index = i;
            }
        }
        return index;
    }
};