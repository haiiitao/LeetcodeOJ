class Solution {
public:
    int fourSumCount( vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D ) {
        unordered_map<int, int> counter;
        for ( auto a : A )
            for ( auto b : B)
                counter[a + b]++;
        
        int result = 0;
        for ( auto c : C )
            for ( auto d : D ) {
                auto it = counter.find( -c -d );
                if ( it != counter.end() )
                    result += it->second;
            }
        
        return result;
    }
};