/**
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
class Solution {
public:
    int maxProfit( int k, vector<int>& prices ) {
        int len = prices.size();
        if ( len < 2 ) 
            return 0;
            
        if ( k > len / 2 ) { // simple case
            int ans = 0;
            for ( int i = 1; i < len; i++ )
                ans += max( prices[i] - prices[i - 1], 0 );
            
            return ans;
        }
        
        int hold[k + 1];
        int rele[k + 1];
        fill_n( hold, k + 1, INT_MIN );
        fill_n( rele, k + 1, 0 );

        for ( int i = 0; i < len; i++ ) {
            for ( int j = k; j > 0; j-- ) {
                rele[j] = max( rele[j], hold[j] + prices[i] );
                hold[j] = max( hold[j], rele[j - 1] - prices[i] );
            }
        }
        return rele[k];
    }
};

class Solution {
public:
    int maxProfit( int k, vector<int>& prices ) {
        k = min( k, (int)prices.size() );
        if ( !k )
            return 0;
            
        int release[k] = {};
        int hold[k];
        fill_n( hold, k, INT_MIN );
        for ( auto i : prices ) {
            for ( int j = k - 1; j >= 0; j-- ) {
                release[j] = max( release[j], hold[j] + i );
                hold[j] = max( hold[j], ( !j ? 0 : release[j - 1]) - i );
            }
        }
        return release[k - 1];
    }
};