/**
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.
 */
class Solution {
public:
    int maxProfit( vector<int>& prices ) {
        int hold = INT_MIN, rele =  0;
        for ( auto price : prices ) {
            rele = max( rele, hold + price );
            hold = max( hold, -price );
        }
        return rele;
    }
};