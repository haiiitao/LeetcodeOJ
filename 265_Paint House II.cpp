/**
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
 */
class Solution {
public:
    int minCostII( vector<vector<int>>& costs ) {
        const int n = costs.size(), k = n ? costs[0].size() : 0;
        if ( !n ) return 0;
        int minValue = INT_MAX, minIdx, secMinValue; 
        for ( int i = 0; i < k; i++ ) {
            if ( costs[0][i] < minValue ) {
                secMinValue = minValue;
                minValue = costs[0][i];
                minIdx = i;
            } else if ( costs[0][i] < secMinValue ) 
                secMinValue = costs[0][i];
        }
    
        for ( size_t i = 1; i < n; i++ ) {
            int newMinValue = INT_MAX, newMinIdx = 0, newSecMinValue;
            for ( int j = 0; j < k; j++ ) {
                int sum = costs[i][j] + (j != minIdx ? minValue : secMinValue);
                if ( sum < newMinValue ) {
                    newSecMinValue = newMinValue;
                    newMinValue = sum;
                    newMinIdx = j;
                } else if ( sum < newSecMinValue ) 
                    newSecMinValue = sum;
            }
            minValue = newMinValue;
            minIdx = newMinIdx;
            secMinValue = newSecMinValue;
        }
        return minValue;
    }
};