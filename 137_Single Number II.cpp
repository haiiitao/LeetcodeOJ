class Solution {
public:
    int singleNumber( vector<int>& nums ) {
        int one = 0, two = 0;
        for ( auto num : nums ) {
            two |= (one & num);
            one ^= num;
            int mask = ~(one & two);
            one &= mask;
            two &= mask;
        }
        return one;   
    }
};