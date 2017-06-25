/**
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int rele1 = 0, rele2 = 0;
        for ( auto price : prices) {
            rele2 = max( rele2, hold2 + price );
            hold2 = max( hold2, rele1 - price );
            rele1 = max( rele1, hold1 + price );
            hold1 = max( hold1, -price );
        }
        return rele2;
    }
};