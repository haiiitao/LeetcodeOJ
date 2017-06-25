/**
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */
class Solution {
public:
    int maxProfit( vector<int>& prices ) {
        int len = prices.size();
        if ( len < 2 )
            return 0;

        int profit = 0, lowest =  prices[0];
        for ( size_t i = 1; i < len; i++ ) {
            profit = max( profit, prices[i] - lowest );
            lowest = min( lowest, prices[i] );
        }
        return profit;
    }
};

// ===>> another version, can be extended to k transaction
class Solution {
public:
    int maxProfit( vector<int>& prices ) {
        int hold = INT_MIN, rele =  0;
        for ( size_t i = 0, len = prices.size(); i < len; i++ ) {
            rele = max( rele, hold + prices[i] );
            hold = max( hold, -prices[i] );
        }
        return rele;
    }
};