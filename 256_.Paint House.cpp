/**
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. T
he cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, 
and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
 */
class Solution {
public:
    int minCost( vector<vector<int>>& costs ) {
        int cur[3] = { 0 }, prev[3];
        for ( int h = 0, len = costs.size(); h < len; h++ ) {
            swap( prev, cur );
            cur[0] = min( prev[1], prev[2] ) + costs[h][0];
            cur[1] = min( prev[0], prev[2] ) + costs[h][1];
            cur[2] = min( prev[0], prev[1] ) + costs[h][2];
        }
        return min( cur[0], min( cur[1], cur[2] ) );
    }
};