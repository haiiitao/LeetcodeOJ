class Solution {
public:
    bool find132pattern( vector<int>& nums ) {
        stack<int> stk;
        int a3 = INT_MIN;
        for ( int i = nums.size() - 1; i >= 0; i-- ) {
            if ( nums[i] < a3 )
                return true;
                
            while ( !stk.empty() && nums[i] > stk.top() ){ 
                a3 = max( a3, stk.top() ); 
                stk.pop();
            }
            stk.push( nums[i] );
        }
        return false;
    }
};