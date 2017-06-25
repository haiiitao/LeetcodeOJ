class Solution {
public:
    int totalHammingDistance( vector<int>& nums ) {
        int result = 0;
        for ( int i = 0, len = nums.size(); i < 32; i++ ) {
            int ones = 0;
            for ( int val : nums )
                ones += val >> i & 1;
                
            result += (len - ones) * ones;
        }
        return result;
    }
};