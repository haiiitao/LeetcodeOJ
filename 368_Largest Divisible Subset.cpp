class Solution {
public:
    vector<int> largestDivisibleSubset( vector<int>& nums ) {
        sort( nums.begin(), nums.end() );
        if ( nums.empty() )
            return {};
        
        const int len = nums.size();
        int f[len] = { 0 };
        int parent[len] = { 0 } ;
        int max_size = 0, start = 0;
        for ( int i = len - 1; i >= 0; --i ) {
            for ( int j = i; j < len; ++j ) {
                if ( nums[j] % nums[i] == 0 && f[i] < 1+ f[j] ) {
                    f[i] = 1 + f[j];
                    parent[i] = j;
                    if ( f[i] > max_size ) {
                        max_size = f[i];
                        start = i;
                    }
                }
            }
        }
        
        vector<int> result;
        for ( int i = 0; i < max_size; ++i ) {
            result.push_back( nums[start] );
            start = parent[start];
        }
        return result;
    }
};