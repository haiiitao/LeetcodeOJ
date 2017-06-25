class Solution {
public:
    int coinChange( vector<int>& coins, int amount ) {
        int f[amount+1];
        fill_n(f, amount + 1, INT_MAX - 1 );
        f[0] =0;
        sort( coins.begin(), coins.end() );
        for ( auto coin : coins ) {
            for ( int i = coin; i <= amount; i++ )
                f[i] = min( f[i], f[i - coin] + 1 );
        }
        return f[amount] == INT_MAX - 1 ? -1 : f[amount];
    }
};