/**
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
 */
class Solution {
public:
    int maxEnvelopes( vector<pair<int, int>>& envelopes ) {
        vector<int> dp;
        sort( envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if ( a.first == b.first ) return a.second > b.second;
            return a.first < b.first;
        });
        
        for ( int i = 0, len = envelopes.size(); i < len; i++ ) {
            auto it = lower_bound( dp.begin(), dp.end(), envelopes[i].second );
            if ( it == dp.end() ) 
                dp.push_back( envelopes[i].second );
            else
                *it = envelopes[i].second;
        }
        return dp.size();
    }
};

class Solution {
public:
    int maxEnvelopes( vector<pair<int, int>>& envelopes ) {
        sort( envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first;
        });
        
        int len = envelopes.size();
        if ( !len )
            return 0;
        
        int f[len];
        fill_n( f, len, 1 );
        int result = 1;
        for ( int i = len - 2; i >= 0; i-- ) {
            for ( int j = i + 1; j < len; j++ ) {
                if ( envelopes[i].first < envelopes[j].first && envelopes[i].second < envelopes[j].second && f[i] < 1 + f[j] ) {
                    f[i] = 1 + f[j];
                    result = max( result, f[i] );
                }
            }
        }
        return result;
    }
};