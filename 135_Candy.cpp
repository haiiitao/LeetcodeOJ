/**
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
 */
class Solution {
public:
    int candy( vector<int>& ratings ) {
        const int len = ratings.size();
        vector<int> result( len, 1 );
        for ( int i = 1; i < len; i++ )
            if ( ratings[i] > ratings[i - 1] )
                result[i] = result[i - 1] + 1;
                
        for ( int i = len - 2; i >= 0; i-- )
            if ( ratings[i] > ratings[i + 1] )
                result[i] = max( result[i], result[i + 1] + 1 );
                
        int sum = 0;
        for ( int i = 0; i < len; i++ )
            sum += result[i];
            
        return sum;
    }
};