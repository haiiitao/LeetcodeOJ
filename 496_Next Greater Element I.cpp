class Solution {
public:
    vector<int> nextGreaterElement( vector<int>& findNums, vector<int>& nums ) {
        const int len = findNums.size();
        unordered_map<int, int> revIdx;
        stack<int> stk;
        vector<int> result( len, -1 );
        for ( int i = 0; i < len; i++ ) 
            revIdx[findNums[i]] = i; // build up the reverse index mapping
        
        for ( auto n : nums ) {
            while ( !stk.empty() && stk.top() < n ) {
                auto it = revIdx.find( stk.top() );
                if ( it != revIdx.end() ) 
                    result[it->second] = n;
                    
                stk.pop();
            }
            stk.push( n );
        }
        return result;
    }
};